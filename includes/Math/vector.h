#pragma once
#include<iostream>
#include<cmath>

class Vector3{
    public:
        float x;
        float y;
        float z;

        Vector3(float x, float y, float z){
            this->x=x;
            this->y=y;
            this->z=z;
        }

        // length
        double length(){
            return sqrt((this->x)*(this->x) + (this->y)*(this->y) + (this->z)*(this->z));
        } 

        // scalar multiplication: a*vec an vec*a
        friend Vector3 operator *(float a,Vector3 v){
            Vector3 res(0,0,0);
            res.x=a*v.x;
            res.y=a*v.y;
            res.z=a*v.z;
            return res;
        }
        friend Vector3 operator *(Vector3 v,float a){
            Vector3 res(0,0,0);
            res.x=a*v.x;
            res.y=a*v.y;
            res.z=a*v.z;
            return res;
        }

        // dot product multiplication
        //member function method
        double dot(Vector3 &v){
            double dot=(this->x)*v.x+(this->y)*v.y+(this->z)*(v.z);
            return dot;
        }
        //operator overload way
        double operator*(Vector3 &v){
            double dot=(this->x)*v.x+(this->y)*v.y+(this->z)*(v.z);
            return dot;
        }

        // corss product
        Vector3 cross(Vector3 &v){
            Vector3 res(0,0,0);
            res.x=(this->y)*v.z - (this->z)*v.y;
            res.y=(this->z)*v.x - (this->x)*v.x;
            res.z=(this->x)*v.y - (this->y)*v.y;
            return res;
        }

        // addition by operator overload
        Vector3 operator +(Vector3 &v){
            Vector3 res(0,0,0);
            res.x=(this->x)+v.x;
            res.y=(this->y)+v.y;
            res.z=(this->z)+v.z;
            return res;
        }

        //division by operator overload
        Vector3 operator /(float a){
            Vector3 res(0,0,0);
            res.x=(this->x)/a;
            res.y=(this->y)/a;
            res.z=(this->z)/a;
            return res;
        }

        //subtraction by operator overload
        Vector3 operator -(Vector3 &a){
            Vector3 res(0,0,0);
            res.x=this->x-a.x;
            res.y=this->y-a.y;
            res.z=this->z-a.z;
            return res;
        }

        //print
        void print(){
            printf("(%0.3f, %0.3f, %0.3f)\n",this->x,this->y,this->z);
        }
};