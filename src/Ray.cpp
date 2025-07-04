#include "../include/Ray.h"

Ray::Ray(){}

Ray::Ray(const vec3& o, const vec3& d): origin(o), direction(d) {}

vec3 Ray::at(float t) const {
  return origin + direction * t;
}