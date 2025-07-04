#pragma once 
#include "Vec3.h"
#include "Ray.h"

struct Camera {
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;

    Camera();

    Ray get_ray(float u, float v) const;
};
