#pragma once
#ifndef VEC3_H
#define VEC3_H

#include<iostream>
#include<cmath>
using namespace std;

class vec3{
    public:
        double e[3];    
        //constructor
        vec3(): e{0,0,0}{} //intializer list way of doing things
        vec3(double e0,double e1,double e2):e{e0,e1,e2}{}

        //get coordinates
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        //unary operations
        vec3 operator -()const{return vec3(-e[0],-e[1],-e[2]);}
        // return negative of vector w/o modifying original vector
        // hence declared as a constant member function
        double operator[](int i) const {return e[i];}   // non modifiable
        double& operator[](int i) {return e[i];}        // way to modify components

        //binary operations
        vec3& operator+=(const vec3 &v){
            e[0]+=v.e[0];
            e[1]+=v.e[1];
            e[2]+=v.e[2];
            return *this; //*this returns current object
        }

        vec3& operator*=(const vec3 &v){
            e[0]*=v.e[0];
            e[1]*=v.e[1];
            e[2]*=v.e[2];
            return *this; //*this returns current object
        }

        vec3& operator*=(const double t){
            e[0]*=t;
            e[1]*=t;
            e[2]*=t;
            return *this; //*this returns current object
        }

        vec3& operator/=(const double t){
            return *this*=(1/t);
        }

        //crisp of vectors: length XP
        double length_squared()const{
            return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
        }
        double length(){
            return sqrt(length_squared());
        }
};

//aliases for color and point
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color
//vec3 utility funtions

inline ostream& operator<<(ostream&out,vec3&v){
    return out<<v.e[0]<<" "<<v.e[1]<<" "<<v.e[2]<<endl;
}
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

//elementwise multiplication
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

//dot and cross product
inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}


#endif