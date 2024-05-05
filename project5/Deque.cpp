#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {


template <typename Type>
Deque<Type>::Deque()
{
    // default constructor sets head and tail as nullptrs.
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
    // When destructed, make all allocated memory empty.
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    // check whether head is nullptr to define isEmpty.
    if (head == nullptr) {
        return (true);
    }

    return( false );
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    // iterate the deletion of front nodes until the deque is empty.
    while (!isEmpty()) {
        deleteFront();
    }
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    if (head == nullptr) {
        // if nothing exists in the deque, add new node to the front and set is as both head and tail.
        DequeNode<Type>* newDequeNode = new DequeNode<Type>(data, nullptr, nullptr);
        head = newDequeNode;
        tail = newDequeNode;
    }
    else 
    {
        // add new node to the front and set it as head.
        // update the new node's next and old head's previous.
        // set the new node as head.
        DequeNode<Type>* newDequeNode = new DequeNode<Type>(data, head, nullptr);
        head->setPrevious(newDequeNode);
        head = newDequeNode;
    }
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    if (head == nullptr) {
        // if nothing exists in the deque, add new node to the front (rear) and set is as both head and tail.
        addToFront(data);
    }
    else 
    {
        // add new node to the rear and set it as tail.
        // update the new's previous and old tail's next
        // set the new node as tail.
        DequeNode<Type>* newDequeNode = new DequeNode<Type>(data, nullptr, tail);
        tail->setNext(newDequeNode);
        tail = newDequeNode;
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    // if nothing exists in the deque, do nothing.
    if (head == nullptr) {
        return;
    }

    // delete head (old) after updating head and new head's previous as nullptr. 
    if (head->getNext() != nullptr) {
        DequeNode<Type>* oldFront = head;
        head = head->getNext();
        head->setPrevious(nullptr);
        delete oldFront;
    }
    // head->getNext() is nullptr, which means only one node is in the deque. just delete the head.
    else {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
}

template <typename Type>
bool Deque<Type>::deleteItem(const Type& data)
{
    // if nothing exists in the deque, do nothing and return false.
    if (head == nullptr) {
        return false;
    }

    // find the first item matching the data and delete it. Afterward, update the next/previous references.

    DequeNode<Type>* current = head;
    DequeNode<Type>* prior = nullptr;

    while (current != nullptr) {
        // if data is matched,
        if (current->getElement() == data) {
            // if the matched node is head, delete front.
            if (current == head) {
                deleteFront();
            }
            // if the matched node is tail, delete rear.
            else if (current == tail) {
                deleteRear();
            }
            // if the matched node is in the middle, delete the node, then update all references.
            else {
                prior->setNext(current->getNext());
                current->getNext()->setPrevious(prior);
                delete current;
            }

            return true;
        }
        prior = current;
        current = current->getNext();
    }

    return(false);
}



template <typename Type>
Type Deque<Type>::front( ) const
{
    Type result = Type();
    // if head is not nullptr, return head's element.
    if (head != nullptr) {
        result = head->getElement();
    }
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type result = Type();
    // if tail is not nullptr, return tail's element.
    if (tail != nullptr) {
        result = tail->getElement();
    }
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    // if nothing exists in the deque, do nothing.
    if (tail == nullptr) {
        return;
    }
    // if only one node is in the deque, delete it with function deleteFront();
    else if (head == tail) {
        deleteFront();
    }
    // update tail and the new tail's next, then delete the old tail.
    else {
        DequeNode<Type>* oldTail = tail;
        tail = tail->getPrevious();
        tail->setNext(nullptr);
        delete oldTail;
    }
}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    // print all nodes from head to tail. 
    // ex: Head:Something1->Something2-Something3:Tail
    string s;
    s += "Head:";
    DequeNode<Type>* current = head;
    while (current != nullptr) {
        s += to_string(current->getElement());
        if (current->getNext() != nullptr) {
            s += "->";
        }
        current = current->getNext();
    }
    s += ":Tail";
    return( s );
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    // make the deque empty and add all rhs' nodes to the deque.
    if (this != &rhs) {
        makeEmpty();

        DequeNode<Type>* right = rhs.head;
        while (right != nullptr)
        {
            addToRear(right->getElement());
            right = right->getNext();
        }
    }

	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    // iterate from the head to the tail to calculate the size of the deque.
    size_t result = 0;
    DequeNode<Type>* current = head;
    while (current != nullptr) {
        result++;
        current = current->getNext();
    }
    return( result );
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    // if i is invalid index, return false.
    if (i < 0 || i >= size()) {
        return false;
    }

    // move to the i index and set data with the node's element, then return true.
    DequeNode<Type>* current = head;

    for(int j=0; j<i; j++){
        current = current->getNext();
    }

    data = current->getElement();
    return true;
 
}

}


#endif
