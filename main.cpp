#include "../include/Vec3.h"
#include "../include/Ray.h"
#include "../include/Camera.h"
#include "../include/Sphere.h"
#include "../include/Hittable.h"
#include "../include/HittableList.h"

#include <iostream>
#include <cfloat>

vec3 ray_color(const Ray& r, const Hittable& world) {
    hitRecord rec;
    if (world.hit(r, 0.001f, FLT_MAX, rec)) {
        vec3 normal = rec.normal.Normalize();
        return 0.5f * vec3(normal.x() + 1.0f, normal.y() + 1.0f, normal.z() + 1.0f);
    }

    vec3 unit_dir = r.direction.Normalize();
    float t = 0.5f * (unit_dir.y() + 1.0f);
    return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    float aspect_ratio = 16.0f / 9.0f;
    int image_width = 400;
    int image_height = static_cast<int>(image_width / aspect_ratio);

    HittableList world;
    world.add(new Sphere(point3(0, 0, -1), 0.5));
    world.add(new Sphere(point3(0, -100.5, -1), 100));

    Camera cam;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);  

            Ray r = cam.get_ray(u, v);
            color pixel_color = ray_color(r, world);

            int ir = static_cast<int>(255.999 * pixel_color.x());
            int ig = static_cast<int>(255.999 * pixel_color.y());
            int ib = static_cast<int>(255.999 * pixel_color.z());

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}