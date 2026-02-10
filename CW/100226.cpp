#include <cstddef>
int* insert(const int* a, size_t s, size_t i, int v)
{
  int* data = new int[s + 1];
  for(size_t j = 0; j < (s + 1); ++j)
  {
    if(j < i) data[j] = a[i];
    if(j == i) data[j] = v;
    if(j > i) data[j] = a[j + 1];
  }
  return data;
}
