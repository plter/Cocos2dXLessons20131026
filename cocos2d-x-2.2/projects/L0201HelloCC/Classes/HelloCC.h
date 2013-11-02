//
//  HelloCC.h
//  L0201HelloCC
//
//  Created by plter on 13-11-2.
//
//

#ifndef __L0201HelloCC__HelloCC__
#define __L0201HelloCC__HelloCC__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class HelloCC:public CCLayer {
    
public:
    static CCScene* scene();
    
    virtual bool init();
    CREATE_FUNC(HelloCC);
};

#endif /* defined(__L0201HelloCC__HelloCC__) */
