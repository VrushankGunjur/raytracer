//
//  ray.hpp
//  raytracer
//
//  Created by Vrushank Gunjur on 7/9/22.
//

#ifndef ray_hpp
#define ray_hpp

#include <stdio.h>
#include "vec3.hpp"

class ray {
public:
    ray();
    ray(const vec3&, const vec3&);
    
    vec3 origin() const;
    vec3 direction() const;
    vec3 p_t(float) const;
    
    void set_origin(vec3);
    void set_direction(vec3);
    
private:
    vec3 ogn;
    vec3 dtn;
};
#endif /* ray_hpp */
