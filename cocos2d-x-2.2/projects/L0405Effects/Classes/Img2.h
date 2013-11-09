//
//  Img2.h
//  L0405Effects
//
//  Created by plter on 13-11-9.
//
//

#ifndef __L0405Effects__Img2__
#define __L0405Effects__Img2__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class Img2 :public CCLayer{
    
public:
    virtual bool init();
    CREATE_FUNC(Img2);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
    static CCScene* scene();
};


#endif /* defined(__L0405Effects__Img2__) */
