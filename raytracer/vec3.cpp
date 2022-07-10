//
//  vec3.cpp
//  raytracer
//
//  Created by /Users/vrushankgunjur/Documents/raytracer/raytracer/vec3.cppVrushank Gunjur on 7/9/22.
//

#include "vec3.hpp"

vec3::vec3() {
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}

vec3::vec3(float x1, float x2, float x3) {
    v[0] = x1;
    v[1] = x2;
    v[2] = x3;
}

 float vec3::r() const {
    return v[0];
}

 float vec3::x() const {
    return v[0];
}

 float vec3::g() const {
    return v[1];
}

 float vec3::y() const {
    return v[1];
}

 float vec3::b() const {
    return v[2];
}

 float vec3::z() const {
    return v[2];
}

 void vec3::set_x(float x) {
    this->v[0] = x;
}

 void vec3::set_y(float y) {
    this->v[1] = y;
}

 void vec3::set_z(float z) {
    this->v[2] = z;
}

vec3 vec3::operator + (const vec3 & right) const {
    vec3 to_ret;
    to_ret.set_x(this->x() + right.x());
    to_ret.set_y(this->y() + right.y());
    to_ret.set_z(this->z() + right.z());
    
    return to_ret;
}

vec3 vec3::operator - (const vec3 & right) const {
    vec3 to_ret;
    to_ret.set_x(this->x() - right.x());
    to_ret.set_y(this->y() - right.y());
    to_ret.set_z(this->z() - right.z());
    
    return to_ret;
}

vec3 vec3::operator * (const vec3 & right) const {
    vec3 to_ret;
    to_ret.set_x(this->x() * right.x());
    to_ret.set_y(this->y() * right.y());
    to_ret.set_z(this->z() * right.z());
    
    return to_ret;
}

vec3 vec3::operator / (const vec3 & right) const {
    vec3 to_ret;
    to_ret.set_x(this->x() / right.x());
    to_ret.set_y(this->y() / right.y());
    to_ret.set_z(this->z() / right.z());
    
    return to_ret;
}

vec3 vec3::operator * (const float f) const {
    vec3 to_ret(this->x()*f, this->y()*f, this->z()*f);
    return to_ret;
}

vec3 vec3::operator / (const float f) const {
    // simplify to one division for efficiency
    float mul = 1/f;
    
    vec3 to_ret(this->x()*mul, this->y()*mul, this->z()*mul);
    return to_ret;
}



vec3& vec3::operator = (const vec3 & right) {
    v[0] = right.x();
    v[1] = right.y();
    v[2] = right.z();
    
    return *this;
}


 float vec3::length() const {
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

 float vec3::sq_length() const {
    return (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

vec3 normalize(const vec3 to_norm) {
    return to_norm/to_norm.length();
}

std::ostream & operator << (std::ostream & out, const vec3 &right) {
    out << right.x() << " " << right.y() << " " << right.z() << '\n';
    return out;
}

std::istream & operator >> (std::istream & in, vec3 & right) {
    in >> right.v[0] >> right.v[1] >> right.v[2];
    return in;
}

 float dot (const vec3 &v1, const vec3 &v2) {
    return (v1.x()*v2.x()) + (v1.y()*v2.y()) + (v1.z()*v2.z());
}


// https://www.mathsisfun.com/algebra/vectors-cross-product.html second way
vec3 cross (const vec3 &v1, const vec3 &v2) {
    float cx = v1.y()*v2.z() - v1.z()*v2.y();
    float cy = v1.z()*v2.x() - v1.x()*v2.z();
    float cz = v1.x()*v2.y() - v1.y()*v2.x();
    
    vec3 to_ret(cx, cy, cz);
    return to_ret;
}
