#include "Camera.h"

Camera::Camera() {
    float aspect_ratio = 16.0f / 9.0f;
    float viewport_height = 2.0f;
    float viewport_width = viewport_height * aspect_ratio;
    float focal_length = 1.0f;

    origin = vec3(0, 0, 0);
    horizontal = vec3(viewport_width, 0, 0);
    vertical = vec3(0, viewport_height, 0);
    lower_left_corner = origin - horizontal * 0.5f - vertical * 0.5f - vec3(0, 0, focal_length);
}

Ray Camera::get_ray(float u, float v) const {
    return Ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
}
