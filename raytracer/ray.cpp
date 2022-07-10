//
//  ray.cpp
//  raytracer
//
//  Created by Vrushank Gunjur on 7/9/22.
//

#include "ray.hpp"

ray::ray() {
    vec3 o(0,0,0);
    vec3 d(0,0,0);
    
    this->ogn = o;
    this->dtn = d;
}

ray::ray(const vec3& o, const vec3& d) {
    this->ogn = o;
    this->dtn = d;
}

vec3 ray::origin() const {
    return ogn;
}

vec3 ray::direction() const {
    return dtn;
}

vec3 ray::p_t(float t) const {
    return ogn + (dtn*t);
}

void ray::set_origin(vec3 new_origin) {
    ogn = new_origin;
}

void ray::set_direction(vec3 new_direction) {
    dtn = new_direction;
}
