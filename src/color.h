#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include "vec3.h"

using color = vec3;

void write_pixel(std::ostream &out, color pixel_color);

#endif
