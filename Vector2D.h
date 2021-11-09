#include <iostream>
#include <math.h>
#ifndef VECTOR_N
#define VECTOR_N
template <typename T,std::size_t N>
class VectorN{
    T data[N];
public:
    VectorN(T* table);
    VectorN();
    ~VectorN();

    void set(int index,T data);

    T operator()(int i) const;
    void operator=(VectorN<T,N>& other);
    T* table() const {return data;};
    bool operator==(VectorN<T,N>& other) const;
    VectorN<T,N> operator+(VectorN<T,N>& other);
    T operator*(VectorN<T,N>& other);
    VectorN<T,N> operator*(T scalar);
    VectorN<double,N> mult(double scalar);
    VectorN<T,N+1> homogenize();
    double norma();
    VectorN<double,N> normalize();
};

template<typename T,std::size_t N>
inline std::ostream& operator<<(std::ostream& out, const VectorN<T,N> data){
  std::string buffer="";
  for(int i=0;i<N;i++){
    buffer+=std::to_string(data(i));
    if(i<N-1)buffer+=", "; 
  }
  return out<<buffer;
}
template<typename T,std::size_t N>
VectorN<double,N> VectorN<T,N>::mult(double scalar){
    VectorN<double,N> fin=VectorN<double,N>();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,(double)data[i]*scalar);
    }
    return fin;
}

template<typename T,std::size_t N>
VectorN<T,N>::VectorN(T* table){
    for (size_t i = 0; i < N; i++)
    {
        this->data[i]=table[i];
    }
};
template <typename T,std::size_t N>
VectorN<T,N>::~VectorN(){}

template<typename T,std::size_t N>
VectorN<T,N>::VectorN(){
  for(int i=0;i<N;i++){
    this->data[i]=T();
  }
};

template <typename T,std::size_t N>
void VectorN<T,N>::operator=(VectorN<T,N>& other){
    for (size_t i = 0; i < N; i++)
    {
        this->data[i]=other(i);
    }
    
}
template <typename T,std::size_t N>
T VectorN<T,N>::operator()(int i) const{
    if (i<0||i>=N)return T();
    return data[i];
}

template <typename T,std::size_t N>
bool VectorN<T,N>::operator==(VectorN<T,N>& other) const{
    for (size_t i = 0; i < N; i++)
    {
        if (data[i]!=other(i))
        {
            return false;
        }
    }
    return true;
}
template <typename T,std::size_t N>
VectorN<T,N> VectorN<T,N>::operator+(VectorN<T,N>& other){
    VectorN<T,N> fin=VectorN<T,N>();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,data[i]+other(i));
    }
    return fin;
}

template <typename T,std::size_t N>
void VectorN<T,N>::set(int index,T data){
    if (index<0||index>=N)
    {
        return;
    }
    this->data[index]=data;
}
template <typename T,std::size_t N>
T VectorN<T,N>::operator*(VectorN<T,N>& other){
    T sum=0;
    for (size_t i = 0; i < N; i++)
    {
        sum+=data[i]*other(i);
    }
    return sum;    
}
template <typename T,std::size_t N>
VectorN<T,N> VectorN<T,N>::operator*(T scalar){
    VectorN<T,N> fin=VectorN<T,N>();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,data[i]*scalar);
    }
    return fin;
}
template <typename T,std::size_t N>
double VectorN<T,N>::norma(){
    T sum=T();
    for (size_t i = 0; i < N; i++)
    {
        sum+=data[i]*data[i];
    }
    return sqrt(sum); 
}
template <typename T,std::size_t N>
VectorN<double,N> VectorN<T,N>::normalize(){
    return this->mult(1/std::abs(norma()));
}

template <typename T,std::size_t N>
VectorN<T,N+1> VectorN<T,N>::homogenize(){
    VectorN<T,N+1> fin;
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,data[i]);
    }
    fin.set(N,T(1));
    return fin;
}

#endif