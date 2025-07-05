#include "../include/Vec3.h"
#include "../include/Ray.h"
#include "../include/Camera.h"
#include "../include/Sphere.h"
#include <cfloat>

vec3 ray_color(const Ray& r, const Sphere& sphere) {
    float tHit; 
    if(sphere.hit(r, 0.001f, FLT_MAX, tHit)){
        auto hitPoint = r.at(tHit); 
        auto normal = (hitPoint - sphere.center).Normalize(); 
        return 0.5f * vec3(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }
    vec3 unit_dir = r.direction.Normalize();
    float t = 0.5f * (unit_dir.y() + 1.0f);
    return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    const float aspect_ratio = 16.0f / 9.0f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    Camera cam;
    Sphere sphere(vec3(0, 0, -1), 0.5f);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            // compute normalized uv coordinates
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            
            // get each ray for each point 
            Ray r = cam.get_ray(u, v);

            // Create a color vector using u,v for red and green, blue constant
            color pixel_color = ray_color(r, sphere); 

            // Convert to integers 0-255
            int ir = static_cast<int>(255.999 * pixel_color.x());
            int ig = static_cast<int>(255.999 * pixel_color.y());
            int ib = static_cast<int>(255.999 * pixel_color.z());

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
