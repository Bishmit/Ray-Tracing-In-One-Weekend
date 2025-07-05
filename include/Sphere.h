#pragma once 

#include "Vec3.h"
#include "Ray.h"

struct Sphere
{
    vec3 center; 
    float radius; 
    
    Sphere(const vec3& c, float r); 
    bool hit(const Ray& r, float tMin, float tMax, float& t) const; 
};
