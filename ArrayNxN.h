#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#ifndef VECTOR_N
#include "Vector2D.h"
#endif
template <typename T,std::size_t N>
class ArrayNxN
{
    T data[N*N];
public:
    ArrayNxN(T* table);
    ArrayNxN();
    void set(int r,int c, T data);
    void operator=(const ArrayNxN<T,N>& other);
    T operator()(int r,int c)const;
    T* table() const {return data;};
    bool operator==(ArrayNxN<T,N> other)const;
    ArrayNxN<T,N> operator+(const ArrayNxN<T,N>& other) const;
    ArrayNxN<T,N> operator*(const ArrayNxN<T,N>& other) const;
    ArrayNxN<T,N> operator*(int lambda) const;
    VectorN<T,N> operator*(VectorN<T,N>& vec);
    static VectorN<T,N> Scale(VectorN<T,N>& vec, VectorN<T,N>& scale);
    static VectorN<T,N> Translate(VectorN<T,N>& vec, VectorN<T,N> dest);
    ~ArrayNxN(){};
};
template<typename T,std::size_t N>
inline std::ostream& operator<<(std::ostream& out, const ArrayNxN<T,N> data){
    std::string buffer="";
    for (size_t i = 0; i < N; i++)
    {
        for (size_t k = 0; k < N; k++)
        {
            buffer+= std::to_string(data(i,k));
            if (i*N+k<N*N-1)buffer+=", ";
        }
        buffer+="\n";
    }
    return out<<buffer;
}


template <typename T,std::size_t N>
ArrayNxN<T,N> ArrayNxN<T,N>::operator+(const ArrayNxN<T,N>& other) const{
    T table[N*N];
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            table[i*N+j]=this->data[i*N+j]+other(i,j);
        }
    }
    return table;    
}

template <typename T,std::size_t N>
ArrayNxN<T,N> ArrayNxN<T,N>::operator*(int lambda) const{
    T table[N*N];
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            table[i*N+j]=this->data[i*N+j]*lambda;
        }
    }
    return table;    
}

template <typename T,std::size_t N>
ArrayNxN<T,N> ArrayNxN<T,N>::operator*(const ArrayNxN<T,N>& other) const{
    T table[N*N];
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            T sum=T();
            for (size_t k = 0; k < N; k++)
            {
                sum+=this->data[i*N+k]*other(k,j);
            }
            table[i*N+j]=sum;
        }
    }
    return table;    
}


template <typename T,std::size_t N>
void ArrayNxN<T,N>::operator=(const ArrayNxN<T,N>& other) {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            this->data[i*N+j]=other(i,j);
        }
        
    }
}

template <typename T,std::size_t N>
T ArrayNxN<T,N>::operator()(int r, int c) const{
    if ((r<0||r>=N)||(c<0||r>=N))return T();
    return data[r*N+c];
}

template <typename T,std::size_t N>
ArrayNxN<T,N>::ArrayNxN(){
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            this->data[i*N+j]=T();
        }
        
    }
}

template <typename T,std::size_t N>
ArrayNxN<T,N>::ArrayNxN(T* table){
    for (size_t i = 0; i < N*N; i++)
    {
        this->data[i]=table[i];
    }
}
template <typename T,std::size_t N>
VectorN<T,N> ArrayNxN<T,N>::operator*(VectorN<T,N>& vec){
    VectorN<T,N> fin=VectorN<T,N>();
    T sum;
    for (size_t i = 0; i < N; i++)
    {
        sum=T();
        for (size_t j = 0; j < N; j++)
        {
            sum+=data[i*N+j]*vec(j);
        }
        fin.set(i,sum);
    }  
    return fin;
}
template <typename T,std::size_t N>
VectorN<T,N> ArrayNxN<T,N>::Scale(VectorN<T,N>& vec,VectorN<T,N>& scale){
    ArrayNxN<T,N> fin=ArrayNxN<T,N>();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,i,scale(i));
    }
    return fin*vec;
}

template <typename T,std::size_t N>
VectorN<T,N> ArrayNxN<T,N>::Translate(VectorN<T,N>& vec, VectorN<T,N> dest){
    // Find the homogenous vector in the N+1 dimension where w=1
    VectorN<T,N+1> add1(vec.homogenize());
    // Construct the homogenous (N+1)x(N+1) array
    ArrayNxN<T,N+1> add2=ArrayNxN<T,N+1>();
    for (size_t i = 0; i < N+1; i++)
    {
        add2.set(i,i,T(1));
    }
    for (size_t i = 0; i < N; i++)
    {
        add2.set(i,N,dest(i));
    }
    // Find the N+1 dimension vector and since w=1 return to the Nth dimension
    VectorN<T,N+1> temp=add2*add1;
    VectorN<T,N> fin=VectorN<T,N>();
    for (size_t i = 0; i < N; i++)
    {
        fin.set(i,temp(i));
    }
    return fin;
}
template <typename T,std::size_t N>
void ArrayNxN<T,N>::set(int r,int c, T data){
    if ((r<0||r>=N)||(c<0||r>=N))return;
    this->data[r*N+c]=data;
}
