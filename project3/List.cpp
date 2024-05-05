#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}

// Deep copy of linked list
const List& List::operator =(const List& rhs) {
    if (this != &rhs) {
        makeEmpty();

        ListNode* right = rhs.head;

        while (right != nullptr)
        {
            addToRear(right->getElement());
            right = right->getNext();
        }
    }

    return(*this);
}

// return the number of total data values found in the list
size_t List::size() const {
    size_t count = 0;
    ListNode* current = head;

    // continues as long as the current node is not nullptr
    while (current != nullptr) {
        // while moving to the next node, count the number of nodes.
        current = current->getNext();
        count++;
    }

    return count;
}

// return the location of the first occurrence of data found in the list
int List::position(const std::string& data) const {
    int index = 0;
    ListNode* current = head;
    // continues as long as the current node is not nullptr
    while (current != nullptr) {
        // if the data value is found in the list, return the index
        if (current->getElement() == data) {
            return index;
        }
        // move to the next node and the index increases
        current = current->getNext();
        index++;
    }
    return -1;
}

// check if the before value is found in the list at a position less then the after value.
bool List::before(const std::string& before, const std::string& after) const {
    // set the default before and after indexes as -1
    int beforeIndex = -1;
    int afterIndex = -1;
    int index = 0;

    ListNode* current = head;
    // continues as long as the current node is not nullptr
    while (current != nullptr) {
        // if the before value is found, set the before index
        if (current->getElement() == before) {
            beforeIndex = index;
        }
        
        // if the after value is found, set the after index
        if (current->getElement() == after) {
            afterIndex = index;
        }
        
        // move to the next and the current index increases
        current = current->getNext();
        index++;
    }

    // if the before and after values are not found, return false
    if (beforeIndex == -1 || afterIndex == -1) {
        return false;
    } 
    // if the before value is found at a position less then the after value, return true
    else {
        return (beforeIndex < afterIndex);
        
    }
}

// set the value of the parameter data to be the element located at position i and return bool results.
bool List::get(int i, std::string& data) const {
    ListNode* current = head;
    // move the current node to the node located at position i
    for (int j = 0; j < i; j++) {
        // while moving to the position, if the current node is nullptr, return false
        if (current == nullptr) {
            return false;
        }
        current = current->getNext();
    }

    // after successfully moving to the position,
    // if the current node is still nullptr, return false
    if (current == nullptr) {
        return false;
    }
    // set data as the current element, and return true.
    else {
        data = current->getElement();
    }
    return true;
    
    /*
    for (int j = 0; j <= i; j++){
        if (current == nullptr) {
            return false;
        }

        if (j == i) {
            data = current->getElement();
            return true;
        }
        current = current->getNext();
    }

    return false;
    */
    
}

// return the smallest item in the list
string List::min() const {
    // if the list is empty, return empty string
    if (isEmpty()) {
        return "";
    }

    ListNode* current = head;
    // set the default minimum as the head element
    string minimum = current->getElement();

    // continues as long as the current node is not nullptr
    while (current != nullptr) {
        // if the current element is smaller than the minimum, 
        // replace the minimum with the current element
        if (minimum > current->getElement()) {
            minimum = current->getElement();
        }

        // move to the next node
        current = current->getNext();
    }

    return minimum;
}

// remove all the items bigger than the data in the list
void List::removeAllBiggerThan(const std::string& data) {
    ListNode* current = head;
    ListNode* priorNode = nullptr;

    // continues as long as current is not nullptr
    while (current != nullptr)
    {
        // if the current element is bigger than data, remove the current node, or move to the next.
        if (current->getElement() > data) {
            
            // if the prior node is not nullptr (the current node is not the head), 
            // the next node of the prior node will be set as the next node of the current node. 
            if (priorNode != nullptr) {
                priorNode->setNext(current->getNext());
            }
            // if the prior node is nullptr (the current node is the head), 
            // the next node of the head will be set as the next node of the current.
            else {
                head = current->getNext();
            }

            // after setting the next node, then delete the current node.
            // move to the next node.
            ListNode* toDelete = current;
            current = current->getNext();
            delete toDelete;
        }
        else {
            // set the prior node as the current node, and move to the next node.
            priorNode = current;
            current = current->getNext();
        }
    }
}

}


