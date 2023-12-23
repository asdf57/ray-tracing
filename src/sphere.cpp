#include "sphere.h"

sphere::sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

bool sphere::hit(const ray& ray, interval ray_t, hit_record& rec) const{
    vec3 oc = ray.origin() - center;
    double a = ray.direction().length_squared();
    double halfB = dot(oc, ray.direction());
    double c = oc.length_squared() - radius*radius;

    double discriminant = halfB*halfB - a*c;

    //Return false if no real solutions
    if (discriminant < 0){
        return false;
    }

    double discriminantSqrt = sqrt(discriminant);

    //Find the nearest root that lies in the acceptable range.
    double root = (-halfB - discriminantSqrt) / a;
    if (!ray_t.contains(root)) {
        //Check if other root is within range
        root = (-halfB + discriminantSqrt) / a;
        if (!ray_t.contains(root))
            return false;
    }

    rec.setT(root);
    rec.setIntersection(ray.at(root));
    vec3 outwardNormal = (rec.getIntersection() - center) / radius;
    rec.setFaceNormal(ray, outwardNormal);

    return true;
}
