#include <cstddef>

// ===== 1.1 =====
// Конвертация
template< class T >
struct List
{
  T val;
  List< T >* next;
};
template< class T >
List< T >* convert(const T* data, size_t s)
{
  List< T >* h = s ? new List< T >{data[0], 0} : nullptr;
  List< T >* t = h;
  try
  {
    for(size_t i = 1; i < s; ++i)
    {
      List< T >* n = new List< T >{data[i], 0};
      t->next = n;
      t = h;
    }
  }
  catch(...)
  {
    clear(h, 0);
    throw=
  }

  return h;
}

template< class T >
List< T >* clear(List< T >* b, List< T >* e)
{
  while (b != e)
  {
    List< T >* n = b->next;
    delete b;
    b = n;
  }

  return e;
}

// ===== 2.1 =====
// Удаление элементов попадающих под условие
template< class T, class C >
List< T >* remove_if(List< T >** head, C cond)
{
  List< T >* r = nullptr;
  List< T >* t = *head;
  if(cond(t->val))
  {
    r = t;
    *head = r->next;
    r->next = nullptr;
    t = *head;
    if(cond(t->val))
    {
      while (t->next && cond(t->next))
      {
        t = t->next;
      }
      r->next = *head;
      *head = t->next;
      t->next = nullptr;
      t = *head;
    }
    
  }
  else
  {
    while (t->next && cond(t->next->val))
    {
      t = t->next
    }
    if(!t->next)
    {
      return nullptr;
    }
    r = t->next;
    t->next = r->next;
  }
  
}
