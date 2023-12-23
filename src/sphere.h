#ifndef _SPHERE_H
#define _SPHERE_H

#include "hittable.h"
#include "hit_record.h"
#include "vec3.h"
#include "interval.h"

class sphere : public hittable {
  public:
    sphere(point3 _center, double _radius);
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
  private:
    point3 center;
    double radius;
};

#endif
