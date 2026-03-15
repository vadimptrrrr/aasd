#include <cstddef>

// 1.1 глубокое копирование структуры. строгая гарантия
template< class T >
struct List
{
  T val;
  List< T >* next;
};

template< class T >
struct Vec
{
  T* data;
  size_t s;
};

template< class T >
List< Vec< T > >* clear(List< Vec< T > >* h)
{
  while (h)
  {
    delete[] h->val.data;
    List< Vec< T > >* temp = h;
    h = h->next;
    delete temp;
  }
  
}

template< class T >
Vec< T > copy(Vec< T >& v)
{
  Vec< T > new_v;
  new_v.data = nullptr;
  try
  {
    new_v.data = new T[v.s];
    for(size_t i = 0; i < v.s; i++)
    {
      new_v.data[i] = v.data[i];
    }
    new_v.s = v.s;
  }
  catch(const std::exception& e)
  {
    delete[] new_v.data;
  }
  return new_v;
}

template< class T >
List< Vec< T > >* copy(const List< Vec< T > >* h)
{
  if(!h)
  {
    return nullptr;
  }

  List< Vec< T > >* head = List< Vec< T > >{copy(h->val), nullptr};
  try
  {
    List< Vec< T > >* node = head;
    while (h->next)
    {
      node->next = List< Vec< T > >{copy(h->val), nullptr};
      h = h->next;
      node = node->next;
    }
    
  }
  catch(...)
  {
    clear(res);
    throw;
  }
  return head;
}

// 2.1 конвертация
template< class T >
List< T >* next(List< T >* node)
{
  return node->next;
}

template< class T >
bool hasNext(List< T >* node)
{
  return node->next != nullptr;
}

template< class T >
struct Vec2
{
  T* data;
  size_t s, cap;
};

template< class T >
Vec< List< T >* > convert(List< Vec< T > >* h)
{

}
