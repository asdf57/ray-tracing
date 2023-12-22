#include "hit_record.h"

void hit_record::setFaceNormal(const ray& ray, const vec3& outwardNormal) {
    frontFacing = dot(ray.direction(), outwardNormal) < 0;
    normal = frontFacing ? outwardNormal : -outwardNormal;
}

point3 hit_record::getIntersection(){
    return intersectionPoint;
}

vec3 hit_record::getNormal(){
    return normal;
}

double hit_record::getT(){
    return t;
}

void hit_record::setIntersection(point3&& value){
    intersectionPoint = std::move(value);
}

void hit_record::setNormal(vec3&& value){
    normal = std::move(value);
}
void hit_record::setT(double&& value) {
    t = std::move(value);
}

void hit_record::setIntersection(const point3& value){
    intersectionPoint = value;
}

void hit_record::setNormal(const vec3& value){
    normal = value;
}

void hit_record::setT(const double& value){
    t = value;
}

bool hit_record::isFrontFacing(){
    return frontFacing;
}