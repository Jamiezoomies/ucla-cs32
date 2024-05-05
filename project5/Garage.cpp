#include "Garage.h"

namespace cs32
{


Garage::Garage( size_t capacity )
{
    // constructor sets capacity
    mCapacity = capacity;
}

// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    // if the garage is full, purge the least used item from the rear and place the new item at the front.
    if (mDeque.size() >= mCapacity) {
        mDeque.deleteRear();
        mDeque.addToFront(s);
        return true;
    }
    // if the garage has a space, add the new item at the front.
    else {    
        mDeque.addToFront(s);
        return false;
    }
}

bool Garage::tossOut( std::string s )
{
    // find item with the string and toss out.
    if (mDeque.deleteItem(s)) {
        return true;
    }

    return( false );
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    // use something found with string and toss it in at the front (most recently used).
    // used deleteItem function to validate whether something is found (deleted) or not.
    if (mDeque.deleteItem(s)) {
        tossIn(s);
        return true;
    }
    // if nothing is found, then do nothing and return false.
    else {
        return( false );
    }
}

// is it in the garage?
bool Garage::find( std::string s )
{
    // use get function to find something in the garage.
    string found;
    for (int i = 0; i < mDeque.size(); i++)
    {
        mDeque.get(i, found);
        if (found == s) {
            return true;
        }
    }
    return( false );
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    // return capacity size
    return mCapacity;
}
// how much is in this garage right now?
size_t Garage::size( )
{
    // return the number of items (nodes of deque)
    return( mDeque.size() );
}

std::string Garage::printItems( )
{
    // print all items in garage.
    return ( mDeque.printItems() );
}


}
