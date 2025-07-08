#include "../include/HittableList.h"

HittableList::HittableList() {}

HittableList::HittableList(Hittable* object) {
    add(object);
}

HittableList::~HittableList() {
    clear();
}

void HittableList::clear() {
    for (Hittable* obj : objects)
        delete obj;
    objects.clear();
}

void HittableList::add(Hittable* object) {
    objects.push_back(object);
}

bool HittableList::hit(const Ray& r, float ray_tmin, float ray_tmax, hitRecord& rec) const {
    hitRecord temp_rec;
    bool hit_anything = false;
    auto closestSoFar = ray_tmax;

    for (const auto& object : objects) {
        if (object->hit(r, ray_tmin, closestSoFar, temp_rec)) {
            hit_anything = true;
            closestSoFar = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}
