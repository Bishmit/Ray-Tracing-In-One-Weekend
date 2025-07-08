#pragma once

#include "Ray.h"

struct hitRecord
{
    point3 p; 
    vec3 normal; 
    float t;
    bool frontFace; 
    
    void setFaceNormal(const Ray& r, const vec3& outwardNormal){
        //NOTE: the parameter outward normal is assumed to have unit length 
        
        frontFace = r.direction.Dot(outwardNormal)< 0; 
        normal = frontFace ? outwardNormal : -outwardNormal; 
    }
};

struct Hittable
{
    virtual ~Hittable() = default; 
    virtual bool hit(const Ray& r, float rayTmin, float rayTmax, hitRecord& record) const = 0; 
};

