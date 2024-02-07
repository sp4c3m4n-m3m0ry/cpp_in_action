#include "list.h"

Link const*
List::GetHead() const
{
    return _pHead;
}

void
List::Add( int id )
{
    // add in front of the list
    Link* pLink = new Link( _pHead, id );
    _pHead      = pLink;
}

List::~List()
{
    delete _pHead;
}

List::List()
    : _pHead( 0 )
{
}

Link*
Link::Next() const
{
    return _pNext;
}

int
Link::Id() const
{
    return _id;
}

Link::~Link()
{
    delete _pNext;
}
