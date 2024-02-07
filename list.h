#ifndef LIST_H
#define LIST_H

class Link
{
  public:
    Link( Link* pNext, int id )
        : _pNext( pNext ),
          _id( id )
    {
    }

    Link*
    Next() const;

    int
    Id() const;

    ~Link();

  private:
    int   _id;
    Link* _pNext;
};

class List
{
  public:
    List();

    ~List();

    void
    Add( int id );

    Link const*
    GetHead() const;

  private:
    Link* _pHead;
};

#endif // LIST_H
