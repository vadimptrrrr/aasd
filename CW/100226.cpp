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

int main()
{
  const int* a = new int[5]{1, 2, 4, 5, 6};
  int* b = insert(a, 5, 2, 3);
  for(size_t i = 0; i < 6; ++i)
  {
    std::cout << b[i] << ' ';
  }
  delete[] a;
}