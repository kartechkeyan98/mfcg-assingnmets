#pragma once
#ifndef RAY_H
#define RAY_H

#include<iostream>
#include "vec3.h"
using namespace std;

class ray{
    public:
        // every ray is of the form P(t)=A+tb
        // A is origin (any point on line) 
        // b is line direction
        // t is a scalar (double in code)
        point3 orig;
        vec3 dir;

        ray(){}
        ray(const point3 &origin,const vec3 &dirn)
        : orig(origin),dir(dirn){}

        point3 origin()const{return orig;}
        vec3 direction()const{return dir;}

        // point P(t)=A+b*t
        point3 at(double t) const{
            return orig+t*dir;
        }
};

#endif