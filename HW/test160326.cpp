#include <cstddef>
// @tag:nextEditSuggestions

template< class T >
struct BiList {
  T val;
  BiList< T >* next, * prev;
};
template< class T >
struct Vector {
  T* data;
  size_t size, cap;
};

// 1. Посчитать количество элементов данных
template< class T >
size_t size(const Vector< const BiList< T > * > v)
{
  size_t res = 0;
  for (size_t i = 0; 0 < v.size; ++i)
  {
    const BiList< T >* list = v.data[i];
    while (list)
    {
      res++;
      list = list->next;
    }
  }
  return res;
}

// 2. Посчитать количество элементов,
// ...удовлетворяющих заданному условию
// ...и сохранить количество таких элементов
template< class T, class P >
size_t count_if(const Vector< const BiList< T > * > v, P p)
{
  size_t res = 0;
  for(size_t i = 0; i < v.size; i++)
  {
    const BiList< T >* list = v.data[i];
    while (list)
    {
      res = p(list->val) ? res + 1 : res;
      list = list->next;
    }
  }
  return res;
}

// 3. Посчитать количество элементов данных
// ...и сохранить размеры каждого списка
template< class T >
size_t size(const Vector< const BiList< T > * > v, BiList< size_t > ** sizes)
{
  size_t res = 0;
  for (size_t i = 0; i < v.size; ++i)
  {
    size_t len_list = 0;
    BiList< T >* list = v.data[i];
    while (list)
    {
      ++res;
      ++len_list;
      list = list->next;
    }
    sizes[i]->val = len_list;
  }
  return res;
}

// 4. Посчитать количество элементов,
// ...удовлетворяющих заданному условию
// ...и сохранить количество таких элементов
// ...в каждом списке
template< class T, class P >
size_t count_if(const Vector< const BiList< T > * > v, BiList< size_t > ** sizes, P p)
{
    size_t res = 0;
  for (size_t i = 0; i < v.size; ++i)
  {
    size_t len_list = 0;
    BiList< T >* list = v.data[i];
    while (list)
    {
      if (p(list->val))
      {
        ++res;
        ++len_list;
      }
      list = list->next;
    }
    sizes[i]->val = len_list;
  }
  return res;
}

// 5. Посчитать количество элементов,
// ...которые удовлетворяют всем условиям
// ...и сохранить количество таких элементов
// ...в каждом списке
template< class T, class ... P_S >
size_t count_if_all(const Vector< const BiList< T > * > v, BiList< size_t > ** sizes, P_S ... pi);

// 6. Найти элементы, удовлетворяющие заданному условию
// ...и сформировать список из указателей на такие элементы
template< class T, class P >
BiList< const BiList< T > * > * find_if(const Vector< const BiList< T > * > v, P p)
{
  BiList< const BiList< T > *>* head = nullptr;
  BiList< const BiList< T > *>* tail = nullptr;
  for (size_t i = 0; i < v.size; ++i)
  {
    const BiList< T >* list = v.data[i];
    while (list)
    {
      if(p(list->val))
      {
        try
        {
          BiList< const BiList< t >* >* n_node = new BiList< const BiList< T >* >{list, nullptr, tail};
        }
        catch(...)
        {
          std::cerr << "mem error\n";
          return head;
        }
        if (tail)
        {
          tail->next = n_node;
        }
        else
        {
          head = n_node;
        }
        tail = n_node;
      }
    }
  }
  return head;
}

// 7. Освободить память, занимаемую структурой
template< class T >
void clear(Vector< BiList< T > * > v)
{
  for (size_t i = 0; i < v.size; ++i)
  {
    BiList< T >* l = v.data[i];
    while (l)
    {
      BiList< T >* temp = l;
      l = l->next;
      delete temp;
    }
  }
}

// 8. Удалить из структуры списки,
// ...в которых хотя бы один элемент списка
// ...удовлетворяет заданному условию
// Вернуть количество удаленных элементов данных (!)
template< class T, class P >
size_t remove_if_any_in_list(Vector< BiList< T > * > v, P p)
{
  size_t res = 0;
  for (size_t i = 0; i < v.size; ++i)
  {
    BiList< T >* l = v.data[i];
    while (l)
    {
      if (p(l->val))
      {
        BiList< T >* ptemp = l->prev;
        BiList< T >* ntemp = l->next;
        ptemp->next = ntemp;
        ntemp->prev = ptemp;
        delete l;
        l = ntemp;
        ++res;
      }
      else
      {
        l = l->next;
      }
    }
  }
  return res;
}

// 9. Удалить из структуры элементы,
// ...которые удовлетворяют заданному условию
// Вернуть количество этих элементов
template< class T, class P >
size_t remove_if(Vector< BiList< T > * > v, P p)
{

}

// 10. Выполнить глубокое копирование структуры данных
template< class T >
Vector< BiList< T > * > copy(const Vector< const BiList< T > * > v);

// 11. Выполнить глубокое копирования структуры данных,
// ...оставляя только элементы, удовлетворяющие заданному условию
template< class T, class P >
Vector< BiList< T > * > copy_if(const Vector< const BiList< T > * > v, P p);

// 12. Преобразовать структуру данных в вектор
template< class T >
Vector< T > convert_to_vector(const Vector< const BiList< T > * > v);

// 13. Преобразовать структуру данных в список
template< class T >
BiList< T > * convert_to_list(const Vector< const BiList< T > * > v);

// 14. Преобразовать структуру даннных в список,
// ...перенеся узлы из оригинальной структуры
template< class T >
BiList< T > * moved_convert_to_list(Vector< BiList< T > * > v);

// 15. Проверить структуру данных:
// ...убедиться, что в векторе нет списков с общими элементами
template< class T >
bool is_different_lists(const Vector< const BiList< T > * > v);

// 16. Исправить структуру данных:
// ...убрать пустые списки из вектора
// Вернуть количество таких списков
template< class T >
size_t remove_empty(Vector< const BiList< T > * > & v);

int main()
{}
