//
// Created by tw on 11/20/2020.
//

#include <iostream>
#include <fstream> // for files manipulation
#include <complex> // for complex numbers
#include <chrono> // time
#include <thread>
#include <future> // get value out of thread
#include <vector>
#include <random>
using namespace std;
using namespace std::chrono;

int thread_number = 8;
int base_pixel_number = 2048 / (thread_number*2);
int width = base_pixel_number * thread_number;
int height = base_pixel_number * thread_number;
double x_base_translation = 1.5;
double y_base_translation = 0.5;
int iteration_depth = 33;

namespace RGB {
int R = 0;
int G = 22;
int B = 0;
}

std::string mandelbrot_file_name(int x) {
  return "mandelbrot" + to_string(x / (width / thread_number)) + ".not_ppm";
}

int value(int x, int y) {
  complex<double> point((double) x / width - x_base_translation, (double) y / height - y_base_translation);
  // we divide by the image dimensions to get values smaller than 1
  // then apply a translation
  complex<double> z(0, 0);
  int nb_iter = 0;
  while (abs(z) < 2 && nb_iter <= iteration_depth) {
    z = z * z + point;
    nb_iter++;
  }
  if (nb_iter < iteration_depth) return (255 * nb_iter) / (iteration_depth - 1);
  else return 0;
}


class mandelbrot_partial_thread_obj {
 public:
  void operator()(int starting_x, int x_amount, int thread_id, const std::string& file_name, std::promise<int> &&p) {
    ofstream my_Image(file_name);
    if (my_Image.is_open()) {
      int i;
      int j;
      for (i = starting_x; i < starting_x + x_amount - 1; i++) {
        for (j = 0; j < height; j++) {
          my_Image << value(i, j) << ' ' << RGB::G << ' ' << RGB::B << "\n";
          if (j == height / 2 && i % 100 == 0) {
            cout << "thread " << thread_id << " in step " << i << " of " << starting_x + x_amount << endl;
          }
        }
      }
      my_Image.close();
      p.set_value(i);
    } else cout << "Could not open the file " << file_name << endl;
  }
};

int main() {
  auto start = high_resolution_clock::now();
  bool thread_mode = true;
  if (thread_mode) {
    std::vector<std::string> file_name_vector;
    std::vector<std::tuple<int, std::string, std::promise<int>>> thread_start_data;
    std::vector<thread> thread_array;
    std::vector<std::promise<int>> promises;
    std::vector<std::future<int>> promise_future;
    std::vector<int> promise_answer;
    std::vector<std::tuple<int, int>> lateral_values;
    int x_slice_size = width / thread_number;
    int temp_size = 0;
    for (int i = 0; i < thread_number; i++) {
      std::promise<int> p;
      thread_start_data.emplace_back(std::make_tuple(temp_size, mandelbrot_file_name(temp_size), std::move(p)));
      temp_size += x_slice_size;
      cout << to_string(temp_size) << endl;
    }

    int temp_thread_id = 0;
    for (auto &[starting_point, file_name, promise]: thread_start_data) {
      promise_future.emplace_back(promise.get_future());
      thread_array.emplace_back(thread(mandelbrot_partial_thread_obj(),
                                       starting_point,
                                       x_slice_size,
                                       temp_thread_id,
                                       file_name,
                                       std::move(promise)));
      temp_thread_id++;
    }
    std::default_random_engine e((unsigned int)time(0));
    int i = e();
    std::string file_name("mandelbrot_final"+to_string(i)+".ppm");
    ofstream my_Image(file_name);
    if (my_Image.is_open()) {
      my_Image << "P3\n" << width << " " << height << " 255\n";
      std::vector<std::ifstream> input_files;
      for (int i = 0; i < thread_number; i++) {
        thread_array[i].join();
        promise_answer.emplace_back(promise_future[i].get());
        auto temp_file = std::ifstream(std::get<1>(thread_start_data[i]), std::ios_base::binary);
        my_Image << temp_file.rdbuf();
      }
    }
    my_Image.close();

    // edge check
    for (int i = 1; i < thread_number; i++) {
      if (std::get<0>(thread_start_data[i]) != promise_answer[i - 1] + 1) {
        cout << "edges didnt match " << std::get<0>(thread_start_data[i]) << " "
             << promise_answer[i - 1] << " in thread " << thread_number << endl;
      }
    }

    cout << "last edge was " << promise_answer[thread_number - 1] << endl;
  } else {
    ofstream my_Image("mandelbrot.ppm");
    if (my_Image.is_open()) {
      my_Image << "P3\n" << width << " " << height << " 255\n";
      for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
          if (j == width / 2 && i % 100 == 0) {
            cout << i << endl;
          }
          my_Image << value(i, j) << ' ' << RGB::G << ' ' << RGB::B << "\n";
        }
      }
      my_Image.close();
    } else cout << "Could not open the file";
  }

  auto stop = high_resolution_clock::now();
  // Get duration. Substart timepoints to
  // get durarion. To cast it to proper unit
  // use duration cast method
  auto duration_microseconds = duration_cast<microseconds>(stop - start);
  auto duration_seconds = duration_cast<seconds>(stop - start);

  cout << "Time taken by function: "
       << duration_microseconds.count() << " microseconds" << endl;

  cout << "Time taken by function: "
       << duration_seconds.count() << " seconds" << endl;

  return 0;
}
