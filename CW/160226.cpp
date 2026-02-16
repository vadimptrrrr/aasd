#include <cstddef>

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
    throw;
  }
}