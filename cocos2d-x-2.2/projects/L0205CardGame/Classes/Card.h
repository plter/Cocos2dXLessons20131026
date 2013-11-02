//
//  Card.h
//  L0205CardGame
//
//  Created by plter on 13-11-2.
//
//

#ifndef __L0205CardGame__Card__
#define __L0205CardGame__Card__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class Card:public CCSprite {
    
public:
    virtual bool init();
    CREATE_FUNC(Card);
    virtual void showRecto();
    virtual void showVerso();
    virtual void setNum(int n);
    virtual int getNum();
    
private:
    CCLabelTTF *recto;
    CCSprite *verso;
    
    int _num;
};


#endif /* defined(__L0205CardGame__Card__) */
