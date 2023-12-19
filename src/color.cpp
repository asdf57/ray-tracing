#include "color.h"

void write_pixel(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.v0()) << ' '
        << static_cast<int>(255.999 * pixel_color.v1()) << ' '
        << static_cast<int>(255.999 * pixel_color.v2()) << '\n';
}
