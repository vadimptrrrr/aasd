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
  for(size_t i = 1; i < s; ++i)
  {
    List< T >* n = new List< T >{data[i], 0};
    t->next = n;
    t = h;
  }
  return h;
}
