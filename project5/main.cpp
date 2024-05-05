// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"


int main()
{
    using namespace std;
    using namespace cs32;

    
    // * My Deque <int> Node Test
    DequeNode< int > sampleNode( 5 );
    assert(sampleNode.getElement() == 5);
    assert(sampleNode.getNext() == nullptr);
    assert(sampleNode.getPrevious() == nullptr);

    // * My Deque <int> Test
    Deque< int > otherDeque;
    otherDeque.addToFront(1);
    otherDeque.addToRear(5);
    otherDeque.addToFront(2);
    otherDeque.addToRear(4);
    // 2, 1, 5, 4
    assert(otherDeque.printItems() == "Head:2->1->5->4:Tail");
    otherDeque.deleteRear();
    otherDeque.deleteFront();
    assert(otherDeque.deleteItem(2) == false);
    assert(otherDeque.deleteItem(1) == true);
    assert(otherDeque.front() == 5);
    assert(otherDeque.rear() == 5);
    int k;
    assert(otherDeque.get(0, k) == true);
    assert(k == 5);
    assert(otherDeque.get(-1, k) == false);
    assert(otherDeque.get(2, k) == false);
    otherDeque.makeEmpty();
    assert(otherDeque.isEmpty() == true);




    // * My Deque <String> Test
    Deque< string > sampleDeque;
    sampleDeque.addToFront("James");
    sampleDeque.addToFront("Arin");
    sampleDeque.addToRear("Kevin");
    sampleDeque.addToFront("John");
    sampleDeque.addToFront("Sarah");
    sampleDeque.addToRear("Kale");
    sampleDeque.addToRear("Tate");
    sampleDeque.addToRear("Thomas");
    // Sarah, John, Arin, James, Kevin, Kale, Tate, Thomas

    assert(sampleDeque.size() == 8);
    assert(sampleDeque.front() == "Sarah");
    assert(sampleDeque.rear() == "Thomas");

    string s, c;
    assert(sampleDeque.get(1, s) == true);
    assert(s == "John");
    assert(sampleDeque.get(3, s) == true);
    assert(s == "James");
    assert(sampleDeque.get(6, s) == true);
    assert(s == "Tate");
    assert(sampleDeque.get(8, c) == false);
    assert(c == "");

    sampleDeque.deleteFront();
    sampleDeque.deleteRear();
    assert(sampleDeque.front() == "John");
    assert(sampleDeque.rear() == "Tate");
    assert(sampleDeque.size() == 6);
    // John, Arin, James, Kevin, Kale, Tate

    Deque<string> sampleDeque2;
    sampleDeque2 = sampleDeque;

    assert(sampleDeque.deleteItem("Sarah") == false);
    assert(sampleDeque.deleteItem("James") == true);
    assert(sampleDeque.deleteItem("John") == true);
    assert(sampleDeque.deleteItem("Tate") == true);

    assert(sampleDeque2.size() == 6);
    assert(sampleDeque2.front() == "John");
    assert(sampleDeque2.rear() == "Tate");
    assert(sampleDeque2.deleteItem("Arin") == true);
    assert(sampleDeque2.deleteItem("Arin") == false);
    assert(sampleDeque2.deleteItem("John") == true);
    assert(sampleDeque2.deleteItem("Tate") == true);
    assert(sampleDeque2.front() == "James");
    assert(sampleDeque2.rear() == "Kale");

    // Arin, Kevin, Kale
    assert(sampleDeque.size() == 3);
    assert(sampleDeque.front() == "Arin");
    assert(sampleDeque.rear() == "Kale");

    assert(sampleDeque.printItems() == "Head:Arin->Kevin->Kale:Tail");
    sampleDeque.makeEmpty();
    assert(sampleDeque.size() == 0);
    assert(sampleDeque.get(0, c) == false);

    sampleDeque.addToRear("Thomas");
    sampleDeque.addToRear("David");
    sampleDeque.addToFront("Young");
    sampleDeque.addToFront("Jason");
    // Jason, Young, Thomas, David
    assert(sampleDeque.deleteItem("Thomas") == true);
    assert(sampleDeque.deleteItem("David") == true);
    assert(sampleDeque.deleteItem("Young") == true);
    assert(sampleDeque.deleteItem("Jason") == true);
    assert(sampleDeque.size() == 0);
    
    sampleDeque.addToFront("Young");
    sampleDeque.addToFront("David");
    sampleDeque.addToFront("David");
    sampleDeque.addToRear("Sam");
    sampleDeque.addToRear("Edward");
    sampleDeque.addToRear("Young");

    // David, David, Young, Sam, Edward, Young
    assert(sampleDeque.size() == 6);
    assert(sampleDeque.deleteItem("David") == true);
    assert(sampleDeque.printItems() == "Head:David->Young->Sam->Edward->Young:Tail");
    assert(sampleDeque.front() == "David");
    assert(sampleDeque.get(0, s) == true);
    assert(s == "David");
    assert(sampleDeque.deleteItem("David") == true);
    assert(sampleDeque.size() == 4);
    assert(sampleDeque.deleteItem("Young") == true);
    sampleDeque.deleteFront();
    sampleDeque.deleteRear();
    sampleDeque.deleteRear();
    assert(sampleDeque.isEmpty() == true);
    assert(sampleDeque.front() == "");
    assert(sampleDeque.rear() == "");

    sampleDeque.addToFront("Young");
    assert(sampleDeque.deleteItem("Young"));
    assert(sampleDeque.isEmpty() == true);
    assert(sampleDeque.front() == "");
    assert(sampleDeque.rear() == "");

    sampleDeque.addToFront("Young");
    sampleDeque.deleteFront();
    assert(sampleDeque.isEmpty() == true);
    assert(sampleDeque.front() == "");
    assert(sampleDeque.rear() == "");





    // * My Garage Test

    Garage g( 5 );
    assert(g.capacity() == 5);
    assert(g.size() == 0);
    assert(g.tossIn("Volvo S90") == false);
    assert(g.tossIn("BMW 330") == false);
    assert(g.tossIn("Honda Accord") == false);
    assert(g.capacity() == 5);
    assert(g.size() == 3);
    assert(g.tossOut("Honda Accord") == true);
    assert(g.size() == 2);
    assert(g.tossIn("Honda Civic") == false);
    assert(g.tossIn("Benz CLA") == false);
    assert(g.tossIn("Cadillac Lyriq") == false);
    // Lyriq, CLA, Civic, 330, S90
    assert(g.size() == 5);
    assert(g.tossIn("Audi Q3") == true);
    // Q3, Lyriq, CLA, Civic, 330
    assert(g.size() == 5);
    assert(g.tossIn("BMW 550") == true);
    // 550, Q3, Lyriq, CLA, Civic
    assert(g.use("BMW 550") == true);
    // 550, Q3, Lyriq, CLA, Civic
    assert(g.use("Honda Civic") == true);
    // Civic, 550, Q3, Lyriq, CLA
    assert(g.use("Honda Accord") == false);
    // Civic, 550, Q3, Lyriq, CLA
    assert(g.find("Audi Q3") == true);
    assert(g.find("Honda Civic") == true);
    assert(g.find("Benz CLA") == true);
    assert(g.find("Bmw 330") == false);
    assert(g.printItems() == "Head:Honda Civic->BMW 550->Audi Q3->Cadillac Lyriq->Benz CLA:Tail");
    
    assert(g.use("Cadillac Lyriq") == true);
    assert(g.use("BMW 550") == true);
    assert(g.use("Honda Civic") == true);
    assert(g.use("Benz CLA") == true);
    assert(g.use("Audi Q3") == true);

    assert(g.use("Hyundai Sonata") == false);
    assert(g.size() == 5);
    assert(g.capacity() == 5);
    assert(g.tossIn("Hyundai Sonata") == true);
    assert(g.find("Cadillac Lyriq") == false);
    assert(g.printItems() == "Head:Hyundai Sonata->Audi Q3->Benz CLA->Honda Civic->BMW 550:Tail");


    // * Project 5 test

    Garage g2(3);
    assert(g2.tossIn("shoes") == false); // nothing thrown away
    assert(g2.tossIn("shirts") == false); // nothing thrown away
    assert(g2.tossIn("books") == false); // nothing thrown away
    assert(g2.size() == 3);
    assert(g2.capacity() == 3);
    g2.use("shoes");
    assert(g2.tossIn("suitcases") == true);

    Garage gSix(6);
    assert(gSix.size() == 0);
    assert(gSix.capacity() == 6);
    gSix.tossIn("shoes");
    gSix.tossIn("shirts");
    gSix.tossIn("books");
    assert(gSix.size() == 3);
    assert(gSix.capacity() == 6);
    gSix.tossIn("suitcases");
    assert(gSix.tossIn("tables") == false); // nothing thrown away
    assert(gSix.tossIn("chairs") == false); // nothing thrown away
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));
    assert(gSix.tossIn("boxes")); // shoes thrown away...
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);



    cout << "all tests passed!" << endl;
    
    return( 0 );
}
