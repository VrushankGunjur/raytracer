//
//  main.cpp
//  raytracer
//  Guidance from https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf
//  Created by Vrushank Gunjur on 7/9/22.
//

#include <iostream>
#include <fstream>
#include "vec3.hpp"
#include "ray.hpp"


vec3 gen_color (const ray & r) {
    const vec3 u_dir = normalize(r.direction());
    
    float y_bal = 0.5*(u_dir.y() + 1.0);
    return vec3(1.0, 1.0, 1.0)*(1.0-y_bal) + vec3(0.5, 0.7, 1.0)*y_bal;
}

int main(int argc, const char * argv[]) {
    int x = 200;
    int y = 100;
    
    std::ofstream img("img.ppm");
    
    
    img << "P3" << '\n';
    img << x << " " << y << '\n';
    img << "255" << '\n';
    
    vec3 ll_corner(-2.0, -1.0, -1.0);
    vec3 x_dir(4.0, 0.0, 0.0);
    vec3 y_dir(0.0, 2.0, 0.0);
    vec3 og(0.0, 0.0, 0.0);
    
    for (int cy = y-1; cy >= 0; cy--) {
        for (int cx = 0; cx < x; cx++) {
            float u = float(cx) / float(x);
            float v = float(cy) / float(y);
            
            ray cur(og, ll_corner + (x_dir*u) + (y_dir*v));
            
            vec3 color = gen_color(cur);
            
            color.set_x(int(color.x()*255.99));
            color.set_y(int(color.y()*255.99));
            color.set_z(int(color.z()*255.99));
            
            img << color << '\n';
        }
    }
    
    
    img.close();
    return 0;
}
