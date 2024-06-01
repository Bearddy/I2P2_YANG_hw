#include "function.h"

using namespace std;
using namespace oj;


Sphere::Sphere(double r, double p){
    radius = r;
    pi = p;
    if(r <= 0 || pi <= 0) setVolume(0.0);
    else setVolume(4.0/3.0*pi*radius*radius*radius);
    
}

Cone::Cone(double r, double h, double p){
    radius = r;
    height = h;
    pi = p;
    if(r <= 0 || h <= 0 || p <= 0) setVolume(0.0);
    else setVolume(1.0/3.0*pi*radius*radius*height);
}

Cuboid::Cuboid(double l, double w, double h){
    length = l;
    width = w;
    height = h;
    if(l <= 0 || w <= 0 || h <= 0) setVolume(0.0);
    else setVolume(length*width*height);
    
}

Cube::Cube(double a):Cuboid(a,a,a){
    if(a <= 0) setVolume(0.0);
    else setVolume(a*a*a);
}

