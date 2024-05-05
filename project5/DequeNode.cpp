#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP


#include "DequeNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
DequeNode<Type>::DequeNode( const Type& v, DequeNode * node, DequeNode * pre )
{
    // constructor sets default values for private member variables.
    value = v;
    next = node;
    previous = pre;
}

template <typename Type>
Type DequeNode<Type>::getElement() const {
    // getter for the value
	return( value );
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getNext() const {
    // getter for the next node
	return( next );
}

template <typename Type>
void DequeNode<Type>::setNext( DequeNode<Type> * node ) {
    // setter for the next node
    next = node;
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getPrevious() const {
    // getter for the previous node
    return( previous );
}

template <typename Type>
void DequeNode<Type>::setPrevious( DequeNode<Type> * node ) {
    // setter for the previous node
    previous = node;
}

}


#endif
