#pragma once

#include "Hittable.h"

#include <vector>

struct HittableList: public Hittable
{
    std::vector<Hittable*> objects;

    HittableList();
    HittableList(Hittable* object);
    ~HittableList();

    void clear();
    void add(Hittable* object);

    bool hit(const Ray& r, float ray_tmin, float ray_tmax, hitRecord& rec) const override;
};
