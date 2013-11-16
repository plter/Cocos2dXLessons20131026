//
//  ColorRect.h
//  L0601UsingBox2d
//
//  Created by plter on 13-11-16.
//
//

#ifndef __L0601UsingBox2d__ColorRect__
#define __L0601UsingBox2d__ColorRect__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"

USING_NS_CC;

class ColorRect:public CCSprite {
    
private:
    b2Body *_body;
    float _ratio;
    
public:
    
    inline void setRatio(float r){
        _ratio = r;
    }
    
    inline float getRatio(){
        return _ratio;
    }
    
    inline void setB2Body(b2Body *b){
        _body = b;
    }
    
    inline b2Body *getB2Body(){
        return _body;
    }
    
    virtual void syncStatus();
    
    virtual bool init();
    
    CREATE_FUNC(ColorRect);
};


#endif /* defined(__L0601UsingBox2d__ColorRect__) */
