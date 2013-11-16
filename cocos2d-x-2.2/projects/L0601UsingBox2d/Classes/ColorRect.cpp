//
//  ColorRect.cpp
//  L0601UsingBox2d
//
//  Created by plter on 13-11-16.
//
//

#include "ColorRect.h"


bool ColorRect::init(){
    
    CCSprite::init();
    
    _body = NULL;
    _ratio = 80;
    
    setTextureRect(CCRectMake(0, 0, 40, 40));
    setColor(ccc3(255, 0, 0));
    
    setContentSize(CCSizeMake(40, 40));
    setAnchorPoint(ccp(0.5, 0.5));
    
    return true;
    
}

void ColorRect::syncStatus(){
    if (_body) {
        setPositionX(_body->GetPosition().x*getRatio());
        setPositionY(_body->GetPosition().y*getRatio());
        setRotation(-_body->GetAngle()/M_PI*180);
    }
}