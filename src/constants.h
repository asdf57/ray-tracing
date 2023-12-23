#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <cmath>
#include <limits>

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = M_PI;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif
