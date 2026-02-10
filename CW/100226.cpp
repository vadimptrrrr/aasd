#include <cstddef>
#include <iostream>\

// 1 example
int* insert(const int* a, size_t s, size_t i, int v)
{
  int* data = new int[s + 1];
  for(size_t j = 0; j < (s + 1); ++j)
  {
    if(j < i) data[j] = a[j];
    if(j == i) data[j] = v;
    if(j > i) data[j] = a[j - 1];
  }
  return data;
}

void insert(int** a, size_t s, size_t i, int v)
{
  int* data = insert(*a, s, i, v);
  delete[] *a;
  *a = data;
}

// 2 example
int* remove(int* a, size_t s, size_t i)
{
  int r = a[i];
  for(size_t j =0; j < s - 1; ++j)
  {
    a[j] = a[j - 1];
  }
  a[s] = r;
  return a + s - 1;
}

int* cut(const int* a, size_t s) //оставить s элементов ДОМА
{

}

// 3 example
int* remove(int* a , size_t s, int v)
{
  for(size_t i = 0; i < s; ++i)
  {
    if(a[i] == v)
    {
      remove(a, s, i);
      --s;
      --i;
    }
  }
  return a + s;
}

int* cut (const int* a, size_t s)
{
  int* data = new int[s];
  for(size_t i = 0; i < s; ++i)
  data[i] = a[i];
  return data;
}

size_t erase(int** a, size_t s, int v)
{
  size_t upd = remove(*a, s, v) - (*a);
  int* t = cut(*a, remove(*a, s, v) - *a);
  delete[] *a;
  *a = t;
  return upd;
}

int* partition(int* a, size_t s, bool(*cond)(int))
{
  int k = 0;
  for(size_t i = 0; i < s; ++i)
  {
    if(!(cond(a[i])))
    {
      remove(a, s, i);
      ++k;
    }
  }
  return a + s - k;
}
