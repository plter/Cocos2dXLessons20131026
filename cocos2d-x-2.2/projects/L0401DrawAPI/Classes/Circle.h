//
//  Circle.h
//  L0401DrawAPI
//
//  Created by plter on 13-11-9.
//
//

#ifndef __L0401DrawAPI__Circle__
#define __L0401DrawAPI__Circle__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class Circle :public CCSprite{
    
public:
    virtual bool init();
    virtual void draw();
    virtual void move();
    inline void setMaxX(float _maxX){
        maxX = _maxX;
    };
    
    inline void setMaxY(float _maxY){
        maxY = _maxY;
    };
    
    CREATE_FUNC(Circle);
    
private:
    float speedX,speedY,maxX,maxY,r,rotateSpeed;
};

#endif /* defined(__L0401DrawAPI__Circle__) */
