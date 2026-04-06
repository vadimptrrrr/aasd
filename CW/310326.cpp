// разные хэш-таблицы
#include <iostream>

template< class Key, class T, class Hash, class Equal >
struct HashTable
{
  using Value = std::pair< Key, T >;
  
  size_t size_;
  size_t capacity_;
  Value** slots;
};

template< class K, class T, class Hash, class Equal >
typename HashTable< K, T, Hash, Equal >::Value** find(
    const HashTable< K, T, Hash, Equal >& table, const K& key)
{

}

template< class K, class T, class Hash, class Equal >
size_t psl(const HashTable< K, T, Hash, Equal >& table, typename HashTable< K, T, Hash, Equal >::Value** value)
{
  Hash haser;
  size_t home = haser(*value->first) % table.capacity_;
  size_t ind = value - table.slots;
  if (ind >= home)
  {
    return ind - home;
  }
  else
  {
    return table.capacity_ - (home - ind);
  }
}