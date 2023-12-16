#ifndef _VEC3_H
#define _VEC3_H

#include <iostream>

class vec3{
  public:
    double components[3];
    vec3();
    vec3(double v0, double v1, double v2);

    double v0() const { return components[0]; }
    double v1() const { return components[1]; };
    double v2() const { return components[2]; };

    vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);
    vec3& operator+=(const vec3 &v);
    vec3& operator*=(const vec3 &v);
    vec3& operator/=(const vec3 &v);

    double length() const;
    double length_squared() const;
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream &out, const vec3 &v);
inline vec3 operator+(const vec3 &u, const vec3 &v);
inline vec3 operator-(const vec3 &u, const vec3 &v);
inline vec3 operator*(const vec3 &u, const vec3 &v);
inline vec3 operator*(double t, const vec3 &v);
inline vec3 operator*(const vec3 &v, double t);
inline vec3 operator/(vec3 v, double t);
inline double dot(const vec3 &u, const vec3 &v);
inline vec3 cross(const vec3 &u, const vec3 &v);
inline vec3 unit_vector(vec3 v);

#endif
