#include "../include/Sphere.h"

Sphere::Sphere(const vec3& c, float r): center(c), radius(r) {}

bool Sphere::hit(const Ray& r, float tMin, float tMax, float& t) const{
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

    t = root; 
    return true;  
}