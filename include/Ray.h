#pragma once

#include "Vec3.h"   

struct Ray
{
    vec3 origin; 
    vec3 direction; 

    Ray(); 
    Ray(const vec3& o, const vec3& d); 
    vec3 at(float t) const; 
};
