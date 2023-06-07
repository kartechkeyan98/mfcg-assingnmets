#include<iostream>
#include<cmath>
#include "vector.h"
using namespace std;

int main(void){
    Vector3 v1(1.5,1.2,1.8);
    Vector3 v2(2.5,3.6,5.1);
    
    printf("Length of v1: %0.3f\n",v1.length());
    printf("Length of v2: %0.3f\n",v2.length());
    cout<<"2*v1 = "; (2*v1).print();
    cout<<"v1*2 = "; (v1*2).print();
    printf("v1.v2 = %0.3f\n",v1.dot(v2));
    printf("v1.v2 = %0.3f\n",v1*v2);
    cout<<"v1 X v2 = "; (v1.cross(v2)).print();
    cout<<"v1 + v2 = "; (v1+v2).print();
    cout<<"v1/2 = "; (v1/2).print();
    cout<<"v1 - v2 = "; (v1-v2).print();


}