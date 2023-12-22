#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <cmath>
#include <limits>
#include <memory>
#include "ray.h"
#include "vec3.h"

const double infinity = std::numeric_limits<double>::infinity();
const double pi = M_PI;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif
