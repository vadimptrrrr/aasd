#include <cstddef>

//========= 1 ========
// + элемент на определённую позицию
template < class T >
T* insert(const T* a, size_t s, size_t i, T v)
{
  T* r = new T[s + 1];
  try
  {
    for (size_t k = 0; k < i; ++k)
    {
      r[k] = a[k];
    }
    r[i] = v;
    for (size_t k = i+1; k < s+1; ++k)
    {
      r[k] = a[k-1]
    }
  }
  catch(...)
  {
    delete[] r;
    throw;
  }
  return r;
}

//========= 2 ========
//  Разворот массива
template < class T >
T* reverse(const T* a, size_t s)
{
  T* r = new T[s];               //T::T()
  try
  {
    for(size_t i = 0; i < s; ++i)
    {
      r[i] = a[s-i+1]
    }                              //T::operator=(T)
  }
  catch(...)
  {
    delete[] r;
    throw;
  }
    return r
}

//========= 3 ========
// Раворот на месте по месту
template< class T >
void reverse(T* a, size_t s, size_t& z)
{
  z = 0;
  for(size_t i = 0; i < s/2; ++i)
  {
    std::swap(a[i], a[s-i+1]);
    ++z;
  }
}

//========= 3.1 ========
// remove
template < class T >
T* remove(const T* a, size_t s, T v)
{}
