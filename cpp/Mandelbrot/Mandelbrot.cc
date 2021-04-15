//
// from: https://github.com/SlachPi/mandelbrot_cpp/blob/master/mandelbrot.cpp
//

#include <iostream>
#include <fstream>
#include <complex>

// Its just easier to split this if we're working with power of 2's
#define WIDTH 1024
#define HEIGHT 1024
#define ITER_THRESHOLD 34

using namespace std;

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

int main ()  {
  //ppm format

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

  return 0;
}