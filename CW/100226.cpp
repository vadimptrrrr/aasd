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

// final ex
int* partition(int* a, size_t s, bool(*cond)(int))
{
  for(size_t i = 0; i < s; ++i)
  {
    if(!(cond(a[i])))
    {
      remove(a, s, i);
      --s;
    }
  }
  return a + s;
}

// 4 ex
void reverse(int* a, size_t s)
{
  for(size_t i = 0; i < s; ++i)
  {
    std::swap(a[i], a[s - i - 1]);
  }
}

int* reverse(const int* a, size_t s)
{
  int* data = new int[s];
  for(size_t i = 0; i < s; ++i)
  {
    data[s - i - 1] = a[i];
  }
  return data;
}

// 5 ex
int* unique(int* a, size_t s)
{
  size_t j = 0;
  for(size_t i = 0; i < s; ++i)
  {
    if(a[j] != a[i])
    {
      a[++j] = a[i];
    }
  }
  return a + j + 1;
}

int* cut();
int* erase();

// 6 ex
int* merge(const int* a, size_t sa, const int* b, size_t sb)
{
  size_t k;
  int* data = new int[sa + sb];
  for(size_t i = 0; i < sa; ++i)
  {
    int m = 10000000000;
    for(size_t j = 0; j < sb; ++j)
    {
      m = (a[i] < b[i]) ? a[i] : b[i];
    }
    data[k++] = m;
  }
  return data;
}

// final ex
int* merge(const int* const* a, size_t sa, const size_t* sai, int* c)
{
  size_t* sizes = new size_t[sa];
  size_t SUM = 0;
  for(size_t i = 0; i < sa; ++i)
  {
    sizes[i] = sai[i];
    SUM += sai[i];
  }

  for(size_t q = 0; q < SUM; ++q)
  {
    int MIN = 10000000;
    size_t idx = 0;
    size_t k;
    for(size_t i = 0; i < sa; ++i)
    {
      for(size_t j = sai[i] - sizes[i]; j < sai[i]; ++j)
      {
        if(a[i][j] < MIN)
        {
          MIN = a[i][j];
          idx = i;
        }
      }
    }
    sizes[idx]--;
    c[k] = MIN;
    ++k;
  }
  return c + SUM;
}
