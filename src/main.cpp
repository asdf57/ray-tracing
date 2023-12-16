#include <iostream>

constexpr int IMAGE_WIDTH = 256;
constexpr int IMAGE_HEIGHT = 256;

int main(){
  std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

  for(int row = 0; row < IMAGE_HEIGHT; row++){
    std::clog << "\nScanlines remaining: "
      << (IMAGE_HEIGHT - row)
      << ' '
      << std::flush;

    for(int col = 0; col < IMAGE_WIDTH; col++){
      double r = double(col) / (IMAGE_WIDTH-1);
      double g = double(row) / (IMAGE_HEIGHT-1);
      double b = 0;

      //Normalizing colors to {0..255} mapping
      int ir = static_cast<int>(255.51 * r);
      int ig = static_cast<int>(255.51 * g);
      int ib = static_cast<int>(255.51 * b);

      std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
    }
  }
  std::clog << "\rDone.                 \n";
}
