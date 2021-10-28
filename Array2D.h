#include <iostream>
template <typename T>
class Array2D
{
private:
    T[2][2] data;
public:
    Array2D(T** table);
    Array2D();
    void operator=(const Array2D<T>& other);
    T& operator()(int r,int c)const;
    T** table() const {return data;};
    bool operator==(Array2D<T> other)const;
    Array2D<T> operator+(const Array2D<T>& other) const;
    Array2D<T> operator*(const Array2D<T>& other) const;
    Array2D<T> operator*(int lambda) const;
    friend std::ostream& operator<<(std::ostream& out,const Array2D data);
    ~Array2D(){};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array2D<T> data){
    return out<<"hello";
}

template <typename T>
Array2D<T> Array2D<T>::operator+(const Array2D<T>& other) const{
    T[2][2] table;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            table[i][j]=data[i][j]+other[i][j];
        }
    }
    return table;    
}

template <typename T>
Array2D<T> Array2D<T>::operator*(int lambda) const{
    T[2][2] table;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            table[i][j]=data[i][j]*lambda;
        }
    }
    return table;    
}

template <typename T>
Array2D<T> Array2D<T>::operator*(const Array2D<T>& other) const{
    T[2][2] table;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            T sum=T();
            for (size_t k = 0; k < 2; k++)
            {
                sum+=data[i][k]*other[k][j];
            }
            table[i][j]=sum;
        }
    }
    return table;    
}


template <typename T>
void Array2D<T>::operator=(const Array2D<T>& other) {
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            data[i][j]=table[i][j];
        }
        
    }
}

template <typename T>
T& Array2D<T>::operator()(int r, int c) const{
    if ((r<0||r>=2)||(c<0||r>=2))return T();
    return data[i][j];
}

template <typename T>
Array2D<T>::Array2D(){
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            data[i][j]=T();
        }
        
    }
}

template <typename T>
Array2D<T>::Array2D(T** table){
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            data[i][j]=table[i][j];
        }
        
    }
}
 