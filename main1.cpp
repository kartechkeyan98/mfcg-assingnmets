#include<iostream>
#include<cmath>
#include "ray.h"
#include "vec3.h"
#include "color.h"
using namespace std;

// calculates the color in direction of ray
color ray_color(const ray &r){
    vec3 dir=r.direction();
    vec3 rad=dir-vec3(0,0,-1);  //position w.r.t center of plane

    double c=1;

    double x=rad.x();
    double y=rad.y();
    double m=y*y/(c+x*x);

    m=pow(m,0.5);

    double k=5;
    m*=k;
    int l=static_cast<int>(m);
    double clr;
    if(l%2==0){
        clr=m-l;
    }
    else{
        clr=l+1-m;
    }
    return color(clr,clr,clr);

}

int main(void){
    //image meta-data
    const auto aspect_ratio=16.0/9.0;
    const int img_width=400;
    const int img_height=static_cast<int>(img_width/aspect_ratio);

    //camera
    auto viewport_height=2.0;
    auto viewport_width=aspect_ratio*viewport_height;
    auto focal_length=1.0;

    auto origin=point3(0,0,0);
    auto horizontal=vec3(viewport_width,0,0);
    auto vertical=vec3(0,viewport_height,0);
    auto lower_left_corner=origin-horizontal/2-vertical/2-vec3(0,0,focal_length);

    //render
    cout<<"P3\n"<<img_width<<" "<<img_height<<"\n255\n";
    for(int j=img_height-1;j>=0;j--){
        cerr<<"\rScanlines remaining: "<<j<<" "<<flush;
        for(int i=0;i<img_width;i++){
            auto u=double(i)/(img_width-1);
            auto v=double(j)/(img_height-1);
            ray r(origin,lower_left_corner+u*horizontal+v*vertical-origin);
            color pixel_color=ray_color(r);
            write_color(cout,pixel_color);
        }
    }
    cerr<<"\nDone\n";
}

