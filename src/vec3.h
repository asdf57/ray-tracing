#ifndef _VEC3_H
#define _VEC3_H

#include <iostream>
#include <cmath>

class vec3{
  public:
    vec3();
    vec3(double v0, double v1, double v2);
    double v0() const;
    double v1() const;
    double v2() const;
    vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);
    vec3& operator+=(const vec3 &v);
    vec3& operator*=(const vec3 &v);
    vec3& operator/=(const vec3 &v);
    double length() const;
    double length_squared() const;

  private:
    double components[3];
};

using point3 = vec3;

//Inline functions
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.v0() << ' ' << v.v1() << ' ' << v.v2();
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.v0() + v.v0(), u.v1() + v.v1(), u.v2() + v.v2());
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.v0() - v.v0(), u.v1() - v.v1(), u.v2() - v.v2());
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
  return vec3(u.v0()*v.v0(), u.v1()*v.v1(), u.v2()*v.v2());
}

inline vec3 operator*(double t, const vec3 &v) {
  return vec3(t*v.v0(), t*v.v1(), t*v.v2());
}

inline vec3 operator*(const vec3 &v, double t) {
  return t * v;
}

inline vec3 operator/(vec3 v, double t) {
  return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
  return u.v0() * v.v0() + u.v1() * v.v1() + u.v2() * v.v2();
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
  return vec3(
    u.v0() * v.v2() - u.v2() * u.v1(),
    u.v2() * v.v0() - u.v0() * v.v2(),
    u.v0() * v.v1() - u.v1() * v.v0()
  );
}

inline vec3 unit_vector(vec3 v) {
  return vec3(
    v.v0() / v.length_squared(),
    v.v1() / v.length_squared(),
    v.v2() / v.length_squared()
  );
}

#endif
