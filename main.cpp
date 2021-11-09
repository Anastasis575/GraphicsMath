#include <iostream>
#include "ArrayNxN.h"
#include "Vector2D.h"
using namespace std;
int main(int argc,char** argv){
    cout<<"Let's do some math! "<<endl;
    // int data[9]={1,2,3,4,5,6,7,8,9};
    // ArrayNxN<int,3>* myArr=new ArrayNxN<int,3>(data);
    // int other[9]={2,3,4,5,6,7,8,9,10};
    // ArrayNxN<int,3>* arr2=new ArrayNxN<int,3>(other);
    // ArrayNxN<int,3> sum=(*arr2)+(*myArr);

    // cout<<sum<<endl;
    // cout<<endl;
    // cout<<(*myArr)*2<<endl;
    // cout<<endl;
    // cout<<(*myArr)*(*arr2)<<endl;

    // delete myArr;
    // delete arr2;
    float arr[3]={1.0,2.0,3.0};
    VectorN<float,3> dataV(arr);
    cout<<dataV*3<<endl;
    float arr2[3]={1.0f,1.5f,2.0f};
    VectorN<float, 3> floats(arr2);
    cout<<dataV+floats<<endl;
    cout<<dataV*floats<<endl;
    cout<<dataV.homogenize()<<endl;
    cout<<dataV.norma()<<endl;
    cout<<dataV.normalize()<<endl;
    cout<<ArrayNxN<float,3>::Scale(floats,dataV)<<endl;\
    cout<<ArrayNxN<float,3>::Translate(floats,dataV)<<endl;
    cout<<"End of experiment!!"<<endl;
}