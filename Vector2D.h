#include <stdlib.h>

template <typename T,std::size_t N>
class VectorN{
    T data[N];
public:
    VectorN(T* table);
    ~VectorN();
    void operator=(const VectorN<T,N>& other);
}

