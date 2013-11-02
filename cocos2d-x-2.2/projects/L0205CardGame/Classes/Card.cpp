//
//  Card.cpp
//  L0205CardGame
//
//  Created by plter on 13-11-2.
//
//

#include "Card.h"


bool Card::init(){
    CCSprite::init();
    
    setContentSize(CCSizeMake(80, 80));
    setAnchorPoint(ccp(0,0));
    
    recto = CCLabelTTF::create("2", "Courier", 48);
    recto->setPosition(ccp(40, 40));
    addChild(recto);
    
    verso = CCSprite::create();
    verso->setTextureRect(CCRectMake(0, 0, 80, 80));
    verso->setColor(ccc3(255, 255, 255));
    verso->setAnchorPoint(ccp(0, 0));
    addChild(verso);
    
    showRecto();
    
    return true;
}


void Card::showRecto(){
    recto->setVisible(true);
    verso->setVisible(false);
}


void Card::showVerso(){
    recto->setVisible(false);
    verso->setVisible(true);
}


void Card::setNum(int n){
    _num = n;
    
//    char buf[5];
//    memset(buf, 0, 5);
//    sprintf(buf, "%d",n);
//    recto->setString(buf);
    
    recto->setString(CCString::createWithFormat("%d",_num)->getCString());
}

int Card::getNum(){
    return _num;
}