template< class T >
struct List
{
  T val;
  List< T >* next;
  List< T >* prev;
};

template< class T >
bool has_common(const List< T >* h1, const List< T >* h2)
{
  List< T > p1 = h1; 
  while (p1->prev)
  {
    p1 = p1->prev;
  }
  while (p1)
  {
    if(p1 == h2)
    {
      return true;
    }
    p1 = p1->next;
  }
  return false;
}

template< class T >
bool no_common(List< const List< T >* >* h)
{
  const List< List < T >* >* head = h;
  const List< T >* curr = nullptr;
  while (head)
  {
    curr = head->next;
    while (curr)
    {
      if(has_common(head->val, curr.val))
      {
        return false;
      }
      curr = curr->next;
    }
    head = head->next;
  }
  return true;
}

template< class T >
struct MList
{
  T val;
  MList< T >* next;
  MList< T >* prev;
  MList< T >* ref;
};
template< class T >
bool self_refed(MList< T >* h)
{
  MList< T > hh = h;
  while (h)
  {
    if(hh.ref || !has_common(h1, hh.ref))
    {
      return false;
    }
    h = h->next;
  }
  return true;
}

template< class T >
bool has_common(const MList< T >* h1, const MList< T >* h2)
{
  MList< T > p1 = h1;
  while (p1->prev)
  {
    p1 = p1->prev;
  }
  while (p1)
  {
    if(p1 == h2)
    {
      return true;
    }
    p1 = p1->next;
  }
  return false;
}

template< class T >
List< const MList< T >* >* no_refs(const MList< T >* h)
{
  List< const MList< T >* > durmy_head{nullptr, nullptr, nullptr};
  List< const MList< T >* >* tail = &durmy_head;
  List< const MList< T >* >* prev = nullptr;
  MList< T >* inner = h;
  while (inner)
  {
    if(!has_ref(h, inner))
    {
      try
      {
        tail->next = new List< const MList< T >* >{inner, nullptr, prev};
        tail = tail->next;
        prev = tail;
      }
      catch()
      {
        List< const MList< T >* >* tmp = tail->prev;
        delete tail;
        tail = tmp;
      }
      inner = inner->next;
    }
  }
  return durmy_head->next;
}

template< class T >
bool has_ref(MList< T >* list, MList< T >* node)
{

  while (list)
  {
    if(list->ref == node)
    {
      return true;
    }
    list = list->next;
  }
  return false;
}
