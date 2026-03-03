#include <cstddef>

// 1
template< class T >
struct List
{
  T val;
  List< T >* next;
};

template< class T >
size_t size(const List< T >* h)
{
  size_t count = 0;
  while (h)
  {
    ++count;
    h = h->next;
  }
  return count;
}

template< class T >
void clear(List< T > h)
{
  while (h)
  {
    List< T >* n= h->next;
    delete h;
    h = n;
  }
}

// 2
template< class T >
size_t size(const List< T* >* h)
{
  size_t count = 0;
  while (h)
  {
    count += h->val ? 1 : 0;
    h = h->next;
  }
  return count;
}

template< class T >
void clear(List< T* > h)
{
  while (h)
  {
    List< T* >* n= h->next;
    delete h->val;
    delete h;
    h = n;
  }
}

//3
template< class T >
size_t size(const List< const List< T >* >* h)
{
  size_t count = 0;
  while (h)
  {
    count += size< T >(h->next);
    h = h->next;
  }
  return count;
}

template< class T >
void clear(List< List< T >* >* h)
{
  while (h)
  {
    clear< T >(h->val);
    List< List< T >* >* n = h->next;
    delete h;
    h = n;
  }
}

// 4
template< class T >
struct Vec
{
  T* data;
  size_t size;
};

template< class T >
size_t size(Vec< const List< T >* > v)
{
  size_t count = 0;
  for(size_t = 0; i < v.size; ++i)
  {
    count += size< T >(v.data[i]);
  }
  return count;
}

template< class T >
void clear(Vec< List < T >* > v)
{
  for(size_t = 0; i < v.size; ++i)
  {
    clear< T >(v.data[i]);
  }
  delete[] v.data;
}
