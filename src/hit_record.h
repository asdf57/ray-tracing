#ifndef _HIT_RECORD_H
#define _HIT_RECORD_H

#include "ray.h"

class hit_record {
  public:
    void setFaceNormal(const ray& r, const vec3& outward_normal);
    point3 getIntersection();
    vec3 getNormal();
    double getT();
    bool isFrontFacing();
    void setIntersection(point3&& value);
    void setNormal(vec3&& value);
    void setT(double&& value);
    void setFrontFace(bool&& isFrontFacing);
    void setIntersection(const point3& value);
    void setNormal(const vec3& value);
    void setT(const double& value);
    void setFrontFace(const bool& isFrontFacing);
  private:
    point3 intersectionPoint;
    vec3 normal;
    double t;
    bool frontFacing;
};

#endif
