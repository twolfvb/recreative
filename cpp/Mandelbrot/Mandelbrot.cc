//
// from: https://github.com/SlachPi/mandelbrot_cpp/blob/master/mandelbrot.cpp
//

#include <iostream>
#include <fstream>
#include <complex>
#include <chrono>
#include <vector>
#include <tuple>
#include <random>
#include <thread>

int thread_number = 64;
// It's easier to not check border conditions and just create sizes of 2 to some power
int base_pixel_number = 2048*2*2 / (thread_number*2);
int width = base_pixel_number * thread_number;
int height = base_pixel_number * thread_number;
double x_base_translation = 1.5;
double y_base_translation = 0.5;
int iter_threshold = 50;


using namespace std;
using namespace std::chrono;

// Adjust G and B to get a different output color
namespace RGB {
int R = 0;
int G = 33;
int B = 55;
}

// Returns 0-255 value from a x,y point in space
// The operation will happen until it diverges (abs bigger than 2) or too many operations happen
// If too many operations happen, nb_iter > threshold, it converged, giving us a 0, blackness
// If it diverges before the threshold,  it scales then amount of color to how long it took to diverge
// That color scaling is just to make it look prettier.
int value (int x, int y)  {
  // scale and translate point
  // x L/R, y U/D
  complex<float> point((float)x/width-x_base_translation, (float)y/height-y_base_translation);
  complex<float> z(0, 0);
  int nb_iter = 0;
  while (abs (z) < 2 && nb_iter <= iter_threshold) {
    z = z * z + point;
    nb_iter++;
  }
  if (nb_iter < iter_threshold)
    return (255*nb_iter)/iter_threshold;
  else
    return 0;
}

//
std::string partial_file_name (int x) {
  return "mandelbrot" + to_string(x / (width / thread_number)) + ".not_ppm";
}

void write_partial_file (const std::string& file_name, int starting_x, int x_amount) {
  ofstream partial_mandelbrot_file(file_name);
  if (partial_mandelbrot_file.is_open()) {
    int i;
    int j;
    int value_here;
    for (i = starting_x; i < starting_x + x_amount - 1; i++) {
      for (j = 0; j < height; j++) {
        value_here = value(i, j);
        partial_mandelbrot_file << value_here << ' ' << RGB::G << ' ' << int(RGB::B + value_here / 3) << "\n";
//        if (j == HEIGHT / 2 && i % 100 == 0) {
//          cout << "thread " << thread_id << " in step " << i << " of " << starting_x + x_amount << endl;
//        }
      }
    }
  }
  partial_mandelbrot_file.close();
  cout << "file " << file_name << " finished" << endl;
}

#if 0
int main ()  {

  auto start = high_resolution_clock::now();
  ofstream my_Image ("mandelbrot.ppm");

  // For each point, get its value and write it to the image
  if (my_Image.is_open ()) {
    my_Image << "P3\n" << width << " " << height << " 255\n";
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++)  {
        int val = value(i, j);
        my_Image << val << ' ' << 0 << ' ' << 0 << "\n";
      }
    }
    my_Image.close();
  }
  else
    cout << "Could not open the file";
  auto stop = high_resolution_clock::now();
  auto duration_microseconds = duration_cast<microseconds>(stop - start);
  auto duration_seconds = duration_cast<seconds>(stop - start);

  cout << "Time taken by function: "
       << duration_microseconds.count() << " microseconds" << endl;

  cout << "Time taken by function: "
       << duration_seconds.count() << " seconds" << endl;

  return 0;
}
#else

class mandelbrot_partial_thread_obj {
 public:
  void operator()(int starting_x, int x_amount, int thread_id, const std::string& file_name) {
    ofstream partial_mandelbrot_file(file_name);
    if (partial_mandelbrot_file.is_open()) {
      int i;
      int j;
      int value_here;
      for (i = starting_x; i < starting_x + x_amount - 1; i++) {
        for (j = 0; j < height; j++) {
          value_here = value(i,j);
          partial_mandelbrot_file << value_here << ' ' << RGB::G << ' ' << int(RGB::B + value_here/3) << "\n";
          if (j == height / 2 && i % 200 == 0) {
            cout << "thread " << thread_id << " in step " << i << " of " << starting_x + x_amount << endl;
          }
        }
      }
      partial_mandelbrot_file.close();
    } else cout << "Could not open the file " << file_name << endl;
    cout << "Thread " << thread_id << " finished" << endl;
  }
};

int main() {
  auto start = high_resolution_clock::now();
  std::vector<std::tuple<int, std::string>> thread_start_data;

  int x_slice_size = height / thread_number;
  int temp_size = 0;
  for (int i = 0; i < thread_number; i++) {
    // stores the start value for the calculation to be made
    thread_start_data.emplace_back(std::make_tuple(temp_size, partial_file_name(temp_size)));
    temp_size += x_slice_size;
    cout << to_string(temp_size) << endl;
  }

  std::vector<std::thread> thread_array;
  int temp_thread_id = 0;
  for (auto &[starting_point, file_name]: thread_start_data) {
    thread_array.emplace_back(thread(mandelbrot_partial_thread_obj(),
                                     starting_point,
                                     x_slice_size,
                                     temp_thread_id,
                                     file_name));
    temp_thread_id++;
  }

  std::default_random_engine e((unsigned int) time(0));
  int int_suffix = e();
  std::string file_name("mandelbrot_final" + to_string(int_suffix) + ".ppm");
  ofstream my_Image(file_name);
  if (my_Image.is_open()) {
    my_Image << "P3\n" << width << " " << height << " 255\n";
    std::vector<std::ifstream> input_files;
    for (int i = 0; i < thread_number; i++) {
      thread_array[i].join();
      auto temp_file = std::ifstream(std::get<1>(thread_start_data[i]), std::ios_base::binary);
      my_Image << temp_file.rdbuf();
    }
  }
  my_Image.close();

  auto stop = high_resolution_clock::now();
  auto duration_microseconds = duration_cast<microseconds>(stop - start);
  auto duration_seconds = duration_cast<seconds>(stop - start);

  cout << "Time taken by function: "
       << duration_microseconds.count() << " microseconds" << endl;

  cout << "Time taken by function: "
       << duration_seconds.count() << " seconds" << endl;

  return 0;
}
#endif