#include <iostream>
#include "Array2D.h"
using namespace std;
int main(int argc,char** argv){
    cout<<"Let's do some math!"<<endl;
    Array2D<int>* myArr=new Array2D<int>();
    cout<<myArr<<endl;
    delete myArr;
}