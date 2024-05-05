//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"
namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

Choice Hand::evaluateHand( Card dealerCard ) const
{
    int mCard1Value = mCard1.getValue();
    int mCard2Value = mCard2.getValue();
    int mHandValue = mCard1Value + mCard2Value;
    int mDealerValue = dealerCard.getValue();

    // by default STAND
    Choice c = Choice::STAND;
    
    if ( !isSoft() && !isPair() )
    {
        switch (mHandValue)
        {
            case 8:
                c = Choice::HIT;
                break;

            case 9:
                if (mDealerValue >= 3 && mDealerValue <= 6) 
                {
                    c = Choice::DOUBLEHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 10:
                if (mDealerValue >= 2 && mDealerValue <= 9) 
                {
                    c = Choice::DOUBLEHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 11:
                c = Choice::DOUBLEHIT;
                break;

            case 12:
                if (mDealerValue >= 4 && mDealerValue <= 6) 
                {
                    c = Choice::STAND;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 13:
                if (mDealerValue >= 2 && mDealerValue <= 6) 
                {
                    c = Choice::STAND;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 14:
                if (mDealerValue >= 2 && mDealerValue <= 6) 
                {
                    c = Choice::STAND;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 15:
                if (mDealerValue >= 2 && mDealerValue <= 6) 
                {
                    c = Choice::STAND;
                }
                else if (mDealerValue == 10) 
                {
                    c = Choice::SURRENDERHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 16:
                if (mDealerValue >= 2 && mDealerValue <= 6) 
                {
                    c = Choice::STAND;
                }
                else if (mDealerValue >= 9 || mDealerValue == 1)
                {
                    c = Choice::SURRENDERHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 17:
                c = Choice::STAND;
                break;

            default:
                c = Choice::STAND;
                break;
        }
    }

    if ( isSoft() && !isPair())
    {
        switch (mHandValue) {
            case 3:
                if (mDealerValue >= 5 && mDealerValue <= 6) 
                {
                    c = Choice::DOUBLEHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 4:
                if (mDealerValue >= 5 && mDealerValue <= 6)
                {
                    c = Choice::DOUBLEHIT;
                }
                else
                {
                    c = Choice::HIT;
                }
                break;

            case 5:
                if (mDealerValue >= 4 && mDealerValue <= 6) 
                {
                    c = Choice::DOUBLEHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 6:
                if (mDealerValue >= 4 && mDealerValue <= 6)
                {
                    c = Choice::DOUBLEHIT;
                }
                else
                {
                    c = Choice::HIT;
                }
                break;

            case 7:
                if (mDealerValue >= 3 && mDealerValue <= 6)
                {
                    c = Choice::DOUBLEHIT;
                }
                else
                {
                    c = Choice::HIT;
                }
                break;

            case 8:
                if (mDealerValue >= 3 && mDealerValue <= 6)
                {
                    c = Choice::DOUBLESTAND;
                }
                else if (mDealerValue >= 9 || mDealerValue == 1)
                {
                    c = Choice::HIT;
                }
                else 
                {
                    c = Choice::STAND;
                }
                break;

            case 9:
                c = Choice::STAND;
                break;

            default:
                c = Choice::STAND;
                break;
        }
    }

    if ( isPair() )
    {
        switch (mHandValue) {
            case 4:
                if (mDealerValue >= 2 && mDealerValue <= 3)
                {
                    c = Choice::SPLITHIT;
                }
                else if (mDealerValue >= 4 && mDealerValue <= 7)
                {
                    c = Choice::SPLIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 6:
                if (mDealerValue >= 2 && mDealerValue <= 3)
                {
                    c = Choice::SPLITHIT;
                }
                else if (mDealerValue >= 4 && mDealerValue <= 7)
                {
                    c = Choice::SPLIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 8:
                if (mDealerValue >= 5 && mDealerValue <= 6)
                {
                    c = Choice::SPLITHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 10:
                if (mDealerValue >= 2 && mDealerValue <= 9)
                {
                    c = Choice::DOUBLEHIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 12:
                if (mDealerValue == 2)
                {
                    c = Choice::SPLITHIT;
                }
                else if (mDealerValue >= 3 && mDealerValue <= 6) 
                {
                    c = Choice::SPLIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 14:
                if (mDealerValue >= 2 && mDealerValue <= 7)
                {
                    c = Choice::SPLIT;
                }
                else 
                {
                    c = Choice::HIT;
                }
                break;

            case 16:
                c = Choice::SPLIT;
                break;

            case 18:
                if ((mDealerValue >= 2 && mDealerValue <= 6) || (mDealerValue >= 8 && mDealerValue <= 9))
                {
                    c = Choice::SPLIT;
                }
                else 
                {
                    c = Choice::STAND;
                }
                break;

            case 20:
                c = Choice::STAND;
                break;

            case 2:
                c = Choice::SPLIT;
                break;
            default:
                c = Choice::STAND;
                break;
        }
    }
   
    return( c );
}

bool Hand::isPair() const
{
    if (mCard1.getFace() == mCard2.getFace()) 
    {
        return (true);
    }
    
    return (false);
}

bool Hand::isSoft() const
{
    if (mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE)
    {
        return( true );
    }

    return (false);
}


}
