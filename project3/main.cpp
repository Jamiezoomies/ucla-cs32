#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

using namespace std;
using namespace cs32;

int main()
{
    using namespace std;

    // test code

    // the get function enables a client to iterate over all elements of a List
    List l1;
    
    assert(l1.min() == "");

    l1.addToFront("Hawkeye");
    l1.addToFront("Thor");
    l1.addToFront("Hulk");
    l1.addToFront("Black Widow");
    l1.addToFront("Iron Man");
    l1.addToFront("Captain America");
    
    for (int k = 0; k < l1.size(); k++)
    {
        string x;
        l1.get(k, x);
        cout << x << endl;
    }
    
    // l1.get false test
    string y;
    if (!l1.get(6, y)) {
        cout << y << endl;
    }
    
    // should print: 
    // Captain America
    // Iron Man
    // Black Widow
    // Hulk
    // Thor
    // Hawkeye
    assert(l1.position("") == -1);
    assert(l1.position("Hawkeye") == 5);
    assert(l1.position("Thor") == 4);
    assert(l1.position("Hulk") == 3);
    assert(l1.position("Black Widow") == 2);
    assert(l1.position("Iron Man") == 1);
    assert(l1.position("Captain America") == 0);
    assert(l1.position("Not there") == -1);

    assert(l1.before("Not there", "Hulk") == false);
    assert(l1.before("Hulk", "Not there") == false);
    assert(l1.before("Hulk", "Captain America") == false);
    assert(l1.before("Black Widow", "Hulk") == true);
    assert(l1.before("Captain America", "Hulk") == true);

    // custom before, min functions test
    assert(l1.before("Captain America", "Captain America") == false);
    assert(l1.min() == "Black Widow");

    // removeAllBiggerThan function test
    l1.removeAllBiggerThan("Happy");
    cout << l1.printItems() << endl;
    // now just "Captain America", "Black Widow"
    
    assert(l1.size() == 2);
    assert(l1.position("Hawkeye") == -1);
    assert(l1.position("Thor") == -1);
    assert(l1.position("Hulk") == -1);
    assert(l1.position("Black Widow") == 1);
    assert(l1.position("Iron Man") == -1);
    assert(l1.position("Captain America") == 0);
    assert(l1.position("Not there") == -1);
    
    l1.removeAllBiggerThan("Black Widow");
    assert(l1.size() == 1);
    assert(l1.position("Black Widow") == 0);
    assert(l1.before("Black Widow", "Captain America") == false);
    assert(l1.before("Black Widow", "") == false);
    assert(l1.before("", "Black Widow") == false);
    assert(l1.min() == "Black Widow");

    cout << l1.printItems() << endl;

    // get false test
    for (int k = 0; k < l1.size()+1; k++)
    {
        string x;
        if (l1.get(k, x))
            cout << x << endl;
        else
            cout << "FALSE" << endl;
    }

    // custom test
    l1.removeAllBiggerThan("");
    assert(l1.size() == 0);
    assert(l1.position("") == -1);
    assert(l1.before("", "") == false);
    assert(l1.min() == "");
    
    cout << "all tests passed!" << endl;
    return(0);
}