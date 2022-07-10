//
//  vec3.hpp
//  raytracer
//
//  Created by Vrushank Gunjur on 7/9/22.
//

#ifndef vec3_hpp
#define vec3_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

class vec3 {
public:
    vec3();
    vec3(float, float, float);
    
    // accessing x1, x2, x3
    float r() const;
    float g() const;
    float b() const;
    float x() const;
    float y() const;
    float z() const;
    
    // setting x, y, z
    
     void set_x(float);
     void set_y(float);
     void set_z(float);
    
    // vector arithmetic
    vec3 operator + (const vec3 &) const;
    vec3 operator - (const vec3 &) const;
    vec3 operator * (const vec3 &) const;
    vec3 operator / (const vec3 &) const;
    
    vec3 operator * (const float) const;
    vec3 operator / (const float) const;
    
    vec3 & operator = (const vec3 &);
    
    // property calculations
     float length() const;        // vector magnitude
     float sq_length() const;     // squared length
    
    float v[3];
    
};

std::ostream & operator << (std::ostream &, const vec3&);
std::istream & operator >> (std::istream &, vec3&);


vec3 normalize(const vec3);
float dot (const vec3 &, const vec3 &);
vec3 cross (const vec3 &, const vec3 &);

#endif /* vec3_hpp */
