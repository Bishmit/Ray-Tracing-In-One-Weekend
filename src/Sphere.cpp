#include "../include/Sphere.h"

Sphere::Sphere(const point3& c, float r): center(c), radius(std::fmax(0, r)) {}  

bool Sphere::hit(const Ray& r, float tMin, float tMax, hitRecord& record) const{
    vec3 originCenter = r.origin - center; 
    vec3 direction = r.direction; 
    float a = direction.Dot(direction); 
    float b = 2.0f * originCenter.Dot(direction); 
    float c = originCenter.Dot(originCenter) - radius * radius; 
    float discriminant = b * b - 4 * a * c; 

    if(discriminant < 0) return false; 

    float squraeRootDiscriminant = std::sqrt(discriminant); 

    // first root 
    float root = (-b - squraeRootDiscriminant) / (2.0f * a); 
    if(root < tMin || root > tMax){
        // try second root
        root = (-b + squraeRootDiscriminant) / (2.0f * a); 
        if(root < tMin || root > tMax) return false; 
    }

    record.t = root; 
    record.p = r.at(record.t); 
    record.normal = (record.p - center) / radius; 
    auto outwardNormal = record.normal; 
    record.setFaceNormal(r, outwardNormal);
    return true;  
}