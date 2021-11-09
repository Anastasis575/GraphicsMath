#include <iostream>
#include "ArrayNxN.h"
using namespace std;
int main(int argc,char** argv){
    cout<<"Let's do some math! "<<double(1)<<endl;
    int data[9]={1,2,3,4,5,6,7,8,9};
    ArrayNxN<int,3>* myArr=new ArrayNxN<int,3>(data);
    int other[9]={2,3,4,5,6,7,8,9,10};
    ArrayNxN<int,3>* arr2=new ArrayNxN<int,3>(other);
    ArrayNxN<int,3> sum=(*arr2)+(*myArr);

    cout<<sum<<endl;
    cout<<endl;
    cout<<(*myArr)*2<<endl;
    cout<<endl;
    cout<<(*myArr)*(*arr2)<<endl;

    delete myArr;
    delete arr2;
}