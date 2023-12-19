#include "vec3.h"

vec3::vec3() : components{0,0,0} {}

vec3::vec3(double v0, double v1, double v2) : components{v0,v1,v2} {}

double vec3::v0() const { return components[0]; }

double vec3::v1() const { return components[1]; }

double vec3::v2() const { return components[2]; }

// Operator overloads
vec3 vec3::operator-() const {
  return vec3(-components[0], -components[1], -components[2]);
}

double vec3::operator[](int i) const {
  return components[i];
}

double& vec3::operator[](int i) {
  return components[i];
}

vec3& vec3::operator+=(const vec3 &v) {
  components[0] += v.v0();
  components[1] += v.v1();
  components[2] += v.v2();
  return *this;
}

vec3& vec3::operator*=(const vec3 &v) {
  components[0] *= v.v0();
  components[1] *= v.v1();
  components[2] *= v.v2();
  return *this;
}

vec3& vec3::operator/=(const vec3 &v) {
  components[0] /= v.v0();
  components[1] /= v.v1();
  components[2] /= v.v2();
  return *this;
}

// Utility methods
double vec3::length() const {
  return std::sqrt(length_squared());
}

double vec3::length_squared() const {
  return components[0]*components[0] + components[1]*components[1] + components[2]*components[2];
}
