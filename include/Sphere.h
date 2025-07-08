#pragma once 

#include "Vec3.h"
#include "Hittable.h"

struct Sphere: public Hittable
{ 
    Sphere(const point3& c, float r); 
    bool hit(const Ray& r, float tMin, float tMax,  hitRecord& record) const override; 

    private: 
    vec3 center; 
    float radius; 
};
