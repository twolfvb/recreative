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

// Its just easier to split this if we're working with power of 2's
#define THREAD_AMOUNT 8
#define WIDTH 1024
#define HEIGHT 1024
#define ITER_THRESHOLD 34

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
// If too many operations happen, nb_iter > threshold, it converged, giving us a 0, blackness (?)
// If it diverges before the threshold,  it scales then amount of color to how long it took to diverge
// That color scaling is just to make it look prettier.
int value (int x, int y)  {
  // scale and translate point
  complex<float> point((float)x/WIDTH-1.5, (float)y/HEIGHT-0.5);
  complex<float> z(0, 0);
  int nb_iter = 0;
  while (abs (z) < 2 && nb_iter <= ITER_THRESHOLD) {
    z = z * z + point;
    nb_iter++;
  }
  if (nb_iter < ITER_THRESHOLD)
    return (255*nb_iter)/ITER_THRESHOLD;
  else
    return 0;
}

//
std::string partial_file_name (int x) {
  return "mandelbrot" + to_string(x / (WIDTH / THREAD_AMOUNT)) + ".not_ppm";
}

void write_partial_file (const std::string& file_name, int starting_x, int x_amount) {
  ofstream partial_mandelbrot_file(file_name);
  if (partial_mandelbrot_file.is_open()) {
    int i;
    int j;
    int value_here;
    for (i = starting_x; i < starting_x + x_amount - 1; i++) {
      for (j = 0; j < HEIGHT; j++) {
        value_here = value(i, j);
        partial_mandelbrot_file << value_here << ' ' << RGB::G << ' ' << int(RGB::B + value_here / 3) << "\n";
//        if (j == HEIGHT / 2 && i % 100 == 0) {
//          cout << "thread " << thread_id << " in step " << i << " of " << starting_x + x_amount << endl;
//        }
      }
    }
  }
  partial_mandelbrot_file.close();
  cout << "file " << file_name << "finished" << endl;
}

#if 0
int main ()  {

  auto start = high_resolution_clock::now();

// ppm format
//  P3
//  3 2
//  255
//  # The part above is the header
//  # "P3" means this is a RGB color image in ASCII
//  # "3 2" is the width and height of the image in pixels
//  # "255" is the maximum value for each color
//  # The part below is image data: RGB triplets
//  255   0   0     0 255   0     0   0 255
//  255 255   0   255 255 255     0   0   0
  ofstream my_Image ("mandelbrot.ppm");

  // For earch point, get its value and write it to the image
  if (my_Image.is_open ()) {
    my_Image << "P3\n" << WIDTH << " " << HEIGHT << " 255\n";
    for (int i = 0; i < WIDTH; i++) {
      for (int j = 0; j < HEIGHT; j++)  {
        int val = value(i, j);
        my_Image << val << ' ' << 0 << ' ' << 0 << "\n";
      }
    }
    my_Image.close();
  }
  else
    cout << "Could not open the file";
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
#else
int main() {
  auto start = high_resolution_clock::now();
  std::vector<std::tuple<int, std::string>> thread_start_data;

  int x_slice_size = WIDTH / THREAD_AMOUNT;
  int temp_size = 0;
  for (int i = 0; i < THREAD_AMOUNT; i++) {
    // stores the start value for the calculation to be made
    thread_start_data.emplace_back(std::make_tuple(temp_size, partial_file_name(temp_size)));
    temp_size += x_slice_size;
    cout << to_string(temp_size) << endl;
  }

  for (auto &[size, file_name]: thread_start_data){
    write_partial_file(file_name, size, x_slice_size);
  }

  std::default_random_engine e((unsigned int) time(0));
  int int_suffix = e();
  std::string file_name("mandelbrot_final" + to_string(int_suffix) + ".ppm");
  ofstream my_Image(file_name);
  if (my_Image.is_open()) {
    my_Image << "P3\n" << WIDTH << " " << HEIGHT << " 255\n";
    std::vector<std::ifstream> input_files;
    for (int i = 0; i < THREAD_AMOUNT; i++) {
      auto temp_file = std::ifstream(std::get<1>(thread_start_data[i]), std::ios_base::binary);
      my_Image << temp_file.rdbuf();
    }
  }
  my_Image.close();

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
#endif