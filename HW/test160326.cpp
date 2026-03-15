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
size_t size(const Vector< const BiList< T > * > v);

// 2. Посчитать количество элементов,
// ...удовлетворяющих заданному условию
// ...и сохранить количество таких элементов
template< class T, class P >
size_t count_if(const Vector< const BiList< T > * > v, P p);

// 3. Посчитать количество элементов данных
// ...и сохранить размеры каждого списка
template< class T >
size_t size(const Vector< const BiList< T > * > v, BiList< size_t > ** sizes);
// 4. Посчитать количество элементов,
// ...удовлетворяющих заданному условию
// ...и сохранить количество таких элементов
// ...в каждом списке
template< class T, class P >
size_t count_if(const Vector< const BiList< T > * > v, BiList< size_t > ** sizes, P p);

// 5. Посчитать количество элементов,
// ...которые удовлетворяют всем условиям
// ...и сохранить количество таких элементов
// ...в каждом списке
template< class T, class ... P_S >
size_t count_if_all(const Vector< const BiList< T > * > v, BiList< size_t > ** sizes, P_S ... pi);

// 6. Найти элементы, удовлетворяющие заданному условию
// ...и сформировать список из указателей на такие элементы
template< class T, class P >
BiList< const BiList< T > * > * find_if(const Vector< const BiList< T > * > v, P p);

// 7. Освободить память, занимаемую структурой
template< class T >
void clear(Vector< BiList< T > * > v);

// 8. Удалить из структуры списки,
// ...в которых хотя бы один элемент списка
// ...удовлетворяет заданному условию
// Вернуть количество удаленных элементов данных (!)
template< class T, class P >
size_t remove_if_any_in_list(Vector< BiList< T > * > v, P p);

// 9. Удалить из структуры элементы,
// ...которые удовлетворяют заданному условию
// Вернуть количество этих элементов
template< class T, class P >
size_t remove_if(Vector< BiList< T > * > v, P p);

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
