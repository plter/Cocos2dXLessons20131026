//
//  Circle.cpp
//  L0401DrawAPI
//
//  Created by plter on 13-11-9.
//
//

#include "Circle.h"

bool Circle::init(){
    CCSprite::init();
    
    r = 20.23;
    maxX = 800;
    maxY = 480;
    
    speedX = CCRANDOM_0_1()*3.0f+2.0f;
    speedY = CCRANDOM_0_1()*3.0f+2.0f;
    rotateSpeed = CCRANDOM_0_1()*10;
    
    return true;
}


void Circle::draw(){
    ccDrawCircle(ccp(0, 0), r, 0, 50, true);
}


void Circle::move(){
    setPositionX(getPositionX()+speedX);
    setPositionY(getPositionY()+speedY);
    setRotation(getRotation()+rotateSpeed);
    
//    if (getPositionY()>maxY-r||getPositionY()<r) {
//        speedY = -speedY;
//    }
//    if (getPositionX()>maxX-r||getPositionX()<r) {
//        speedX=-speedX;
//    }
    
    if (getPositionX()<r) {
        speedX = fabsf(speedX);
    }
    if (getPositionX()>maxX-r) {
        speedX = -fabsf(speedX);
    }
    if (getPositionY()<r) {
        speedY = fabsf(speedY);
    }
    if (getPositionY()>maxY-r) {
        speedY = -fabsf(speedY);
    }
    
}