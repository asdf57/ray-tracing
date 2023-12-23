#ifndef _HITTABLE_H
#define _HITTABLE_H

#include "ray.h"
#include "hit_record.h"
#include "interval.h"

class hittable {
  public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
