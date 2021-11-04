#include <string>
#include <iostream>
#include <stdlib.h>
template <typename T,std::size_t N>
class ArrayNxN
{
    T data[N*N];
public:
    ArrayNxN(T* table);
    ArrayNxN();
    void operator=(const ArrayNxN<T,N>& other);
    T operator()(int r,int c)const;
    T* table() const {return data;};
    bool operator==(ArrayNxN<T,N> other)const;
    ArrayNxN<T,N> operator+(const ArrayNxN<T,N>& other) const;
    ArrayNxN<T,N> operator*(const ArrayNxN<T,N>& other) const;
    ArrayNxN<T,N> operator*(int lambda) const;
    friend std::ostream& operator<<(std::ostream& out,const ArrayNxN<T,N> data);
    ~ArrayNxN(){};
};

std::ostream& operator<<(std::ostream& out, const ArrayNxN<int,2> data){
    std::string buffer="";
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t k = 0; k < 2; k++)
        {
            buffer+= std::to_string(data(i,k));
            if (i*2+k<3)buffer+=", ";
        }
        buffer+="\n";
    }
    return out<<buffer;
}
std::ostream& operator<<(std::ostream& out, const ArrayNxN<int,3> data){
    std::string buffer="";
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t k = 0; k < 3; k++)
        {
            buffer+= std::to_string(data(i,k));
            if (i*3+k<8)buffer+=", ";
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
            table[i*2+j]=this->data[i*N+j]+other(i,j);
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
 