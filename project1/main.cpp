//
//  main.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    Card c;

    
 
    Card c1;
    Card c2;
    Hand h( c1, c2);
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::CLUBS, Face::THREE );
    Card four( Suit::CLUBS, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::CLUBS, Face::SIX );
    Card seven( Suit::CLUBS, Face::SEVEN );
    Card eight( Suit::CLUBS, Face::EIGHT );
    Card nine( Suit::CLUBS, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::CLUBS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::CLUBS, Face::KING );
    // two aces...
    assert( h.evaluateHand(two) == Choice::SPLIT );
    
    Hand h1( two, two );
    assert( h1.evaluateHand(two) == Choice::SPLITHIT );
    assert( h1.evaluateHand(three) == Choice::SPLITHIT );
    assert( h1.evaluateHand(four) == Choice::SPLIT );
    assert( h1.evaluateHand(five) == Choice::SPLIT );
    assert( h1.evaluateHand(six) == Choice::SPLIT );
    assert( h1.evaluateHand(seven) == Choice::SPLIT );
    assert( h1.evaluateHand(eight) == Choice::HIT );
    assert( h1.evaluateHand(nine) == Choice::HIT );
    assert( h1.evaluateHand(ten) == Choice::HIT );
    assert( h1.evaluateHand(jack) == Choice::HIT );
    assert( h1.evaluateHand(queen) == Choice::HIT );
    assert( h1.evaluateHand(king) == Choice::HIT );
    
    // test 

    Card x(Suit::CLUBS, Face::DEUCE);
    assert(x.getSuit() == Suit::CLUBS);
    assert(x.getFace() == Face::DEUCE);
    assert(x.getValue() == 2);

    Card y(Suit::SPADES, Face::QUEEN);
    assert(y.getSuit() == Suit::SPADES);
    assert(y.getFace() == Face::QUEEN);
    assert(y.getValue() == 10);

    Hand h3(x, y);
    assert(h3.evaluateHand(two) == Choice::HIT);
    assert(h3.evaluateHand(three) == Choice::HIT);
    assert(h3.evaluateHand(four) == Choice::STAND);
    assert(h3.evaluateHand(five) == Choice::STAND);
    assert(h3.isPair() == false);
    assert(h3.isSoft() == false);

    h3 = Hand(ace, seven);
    assert(h3.evaluateHand(five) == Choice::DOUBLESTAND);
    assert(h3.evaluateHand(six) == Choice::DOUBLESTAND);
    assert(h3.evaluateHand(seven) == Choice::STAND);
    assert(h3.evaluateHand(eight) == Choice::STAND);
    assert(h3.evaluateHand(nine) == Choice::HIT);
    assert(h3.isPair() == false);
    assert(h3.isSoft() == true);

    Hand h4 = Hand(five, five);
    assert(h4.evaluateHand(two) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(three) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h4.isPair() == true);
    assert(h4.isSoft() == false);

    // My test
    
    // 16
    h4 = Hand(six, king);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::SURRENDERHIT);
    assert(h4.evaluateHand(ten) == Choice::SURRENDERHIT);
    assert(h4.evaluateHand(ace) == Choice::SURRENDERHIT);

    // 16
    h4 = Hand(nine, seven);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::SURRENDERHIT);
    assert(h4.evaluateHand(ten) == Choice::SURRENDERHIT);
    assert(h4.evaluateHand(ace) == Choice::SURRENDERHIT);


    // 17
    h4 = Hand(seven, king);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::STAND);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);
    
    h4 = Hand(nine, eight);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::STAND);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);

    // A, 2
    h4 = Hand(ace, two);
    assert(h4.evaluateHand(two) == Choice::HIT);
    assert(h4.evaluateHand(three) == Choice::HIT);
    assert(h4.evaluateHand(four) == Choice::HIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // A, 3
    h4 = Hand(ace, three);
    assert(h4.evaluateHand(two) == Choice::HIT);
    assert(h4.evaluateHand(three) == Choice::HIT);
    assert(h4.evaluateHand(four) == Choice::HIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // A, 4
    h4 = Hand(ace, four);
    assert(h4.evaluateHand(two) == Choice::HIT);
    assert(h4.evaluateHand(three) == Choice::HIT);
    assert(h4.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // A, 5
    h4 = Hand(ace, five);
    assert(h4.evaluateHand(two) == Choice::HIT);
    assert(h4.evaluateHand(three) == Choice::HIT);
    assert(h4.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // A, 6
    h4 = Hand(ace, six);
    assert(h4.evaluateHand(two) == Choice::HIT);
    assert(h4.evaluateHand(three) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // A, 7
    h4 = Hand(ace, seven);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::DOUBLESTAND);
    assert(h4.evaluateHand(four) == Choice::DOUBLESTAND);
    assert(h4.evaluateHand(five) == Choice::DOUBLESTAND);
    assert(h4.evaluateHand(six) == Choice::DOUBLESTAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // A, 8
    h4 = Hand(ace, eight);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::STAND);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);

    // 2, 2
    h4 = Hand(two, two);
    assert(h4.evaluateHand(two) == Choice::SPLITHIT);
    assert(h4.evaluateHand(three) == Choice::SPLITHIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::SPLIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 3, 3
    h4 = Hand(three, three);
    assert(h4.evaluateHand(two) == Choice::SPLITHIT);
    assert(h4.evaluateHand(three) == Choice::SPLITHIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::SPLIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 4, 4
    h4 = Hand(four, four);
    assert(h4.evaluateHand(two) == Choice::HIT);
    assert(h4.evaluateHand(three) == Choice::HIT);
    assert(h4.evaluateHand(four) == Choice::HIT);
    assert(h4.evaluateHand(five) == Choice::SPLITHIT);
    assert(h4.evaluateHand(six) == Choice::SPLITHIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 5, 5
    h4 = Hand(five, five);
    assert(h4.evaluateHand(two) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(three) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(eight) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(nine) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 6, 6
    h4 = Hand(six, six);
    assert(h4.evaluateHand(two) == Choice::SPLITHIT);
    assert(h4.evaluateHand(three) == Choice::SPLIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 7, 7
    h4 = Hand(seven, seven);
    assert(h4.evaluateHand(two) == Choice::SPLIT);
    assert(h4.evaluateHand(three) == Choice::SPLIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::SPLIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::HIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 8, 8
    h4 = Hand(eight, eight);
    assert(h4.evaluateHand(two) == Choice::SPLIT);
    assert(h4.evaluateHand(three) == Choice::SPLIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::SPLIT);
    assert(h4.evaluateHand(eight) == Choice::SPLIT);
    assert(h4.evaluateHand(nine) == Choice::SPLIT);
    assert(h4.evaluateHand(ten) == Choice::SPLIT);
    assert(h4.evaluateHand(ace) == Choice::SPLIT);

    // 9, 9
    h4 = Hand(nine, nine);
    assert(h4.evaluateHand(two) == Choice::SPLIT);
    assert(h4.evaluateHand(three) == Choice::SPLIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::SPLIT);
    assert(h4.evaluateHand(nine) == Choice::SPLIT);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);

    // 10, 10
    h4 = Hand(jack, king);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::STAND);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);

    // 7
    h4 = Hand(three, four);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::STAND);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);

    // ace, ace
    h4 = Hand(ace, ace);
    assert(h4.evaluateHand(two) == Choice::SPLIT);
    assert(h4.evaluateHand(three) == Choice::SPLIT);
    assert(h4.evaluateHand(four) == Choice::SPLIT);
    assert(h4.evaluateHand(five) == Choice::SPLIT);
    assert(h4.evaluateHand(six) == Choice::SPLIT);
    assert(h4.evaluateHand(seven) == Choice::SPLIT);
    assert(h4.evaluateHand(eight) == Choice::SPLIT);
    assert(h4.evaluateHand(nine) == Choice::SPLIT);
    assert(h4.evaluateHand(ten) == Choice::SPLIT);
    assert(h4.evaluateHand(ace) == Choice::SPLIT);

    // 15
    h4 = Hand(ten, five);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::HIT);
    assert(h4.evaluateHand(eight) == Choice::HIT);
    assert(h4.evaluateHand(nine) == Choice::HIT);
    assert(h4.evaluateHand(ten) == Choice::SURRENDERHIT);
    assert(h4.evaluateHand(ace) == Choice::HIT);

    // 11
    h4 = Hand(nine, two);
    assert(h4.evaluateHand(two) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(three) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(five) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(six) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(seven) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(eight) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(nine) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(ten) == Choice::DOUBLEHIT);
    assert(h4.evaluateHand(ace) == Choice::DOUBLEHIT);

    // 21 Blackjack
    h4 = Hand(king, ace);
    assert(h4.evaluateHand(two) == Choice::STAND);
    assert(h4.evaluateHand(three) == Choice::STAND);
    assert(h4.evaluateHand(four) == Choice::STAND);
    assert(h4.evaluateHand(five) == Choice::STAND);
    assert(h4.evaluateHand(six) == Choice::STAND);
    assert(h4.evaluateHand(seven) == Choice::STAND);
    assert(h4.evaluateHand(eight) == Choice::STAND);
    assert(h4.evaluateHand(nine) == Choice::STAND);
    assert(h4.evaluateHand(ten) == Choice::STAND);
    assert(h4.evaluateHand(ace) == Choice::STAND);



    cout << "all tests passed!" << endl;
    return( 0 );
}
