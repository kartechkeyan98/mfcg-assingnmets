#pragma once
#ifndef TORUS_H
#define TORUS_H

#include "hittable.h"
#include "vec3.h"
using namespace std;


class torus: public hittable{
    public: 
        vec3 center;
        vec3 axis;
        double major;
        double minor;
        //shared_ptr<material>mat;

        torus(vec3 cen,double R,double r,vec3 ax):center(cen),major(R),minor(r){
            axis=unit_vector(ax);
        }

        virtual bool hit(const ray &r,double t_min,double t_max,hit_record &rec)const override{
            const double eps=1e-20;
            for(double t=t_min;t<5.0;t+=0.01){
                point3 p=r.at(t);
                vec3 pc=p-center;

                vec3 tube=major*unit_vector(pc-axis*dot(pc,axis));
                vec3 outward_nomral=(pc-tube);
                if(outward_nomral.length()-minor<eps){
                    rec.p=p;
                    rec.t=t;

                    outward_nomral=unit_vector(outward_nomral);
                    rec.set_face_normal(r,outward_nomral);
                    return true;
                }
            }
            return false;
        }
};
#endif