#include <iostream>
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

    T operator()(int i);
    void operator=(VectorN<T,N>& other);
    T* table() const {return data;};
    bool operator==(VectorN<T,N>& other) const;
    VectorN<T,N> operator+(VectorN<T,N>& other);
    T operator*(VectorN<T,N>& other);
    VectorN<T,N> operator*(T scalar);
    VectorN<T,N+1> homogenize();
    double norma();
    VectorN<double,N> normalize();
};

template<typename T,std::size_t N>
VectorN<T,N>::VectorN(T* table){
    for (size_t i = 0; i < N; i++)
    {
        this->data[i]=table[i];
    }
};
template <typename T,std::size_t N>
VectorN<T,N>::~VectorN(){}

template <typename T,std::size_t N>
void VectorN<T,N>::operator=(VectorN<T,N>& other){
    for (size_t i = 0; i < N; i++)
    {
        this->data[i]=other(i);
    }
    
}
template <typename T,std::size_t N>
T VectorN<T,N>::operator()(int i){
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
    VectorN<T,N> fin();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,data[i]+other(i));
    }
    return VectorN<T,N>;
}

template <typename T,std::size_t N>
void VectorN<T,N>::set(int index,T data){
    if (i<0||i>=N)
    {
        return;
    }
    this->data[i]=data;
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
    VectorN<T,N> fin();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(data[i]*scalar);
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
    return std::sqrt(sum); 
}
template <typename T,std::size_t N>
VectorN<double,N> VectorN<T,N>::normalize(){
    return (*this)*(1/std::abs(norma()));
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