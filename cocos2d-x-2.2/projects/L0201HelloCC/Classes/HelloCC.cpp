//
//  HelloCC.cpp
//  L0201HelloCC
//
//  Created by plter on 13-11-2.
//
//

#include "HelloCC.h"

CCScene* HelloCC::scene(){
    
    CCScene * s = CCScene::create();
    s->addChild(HelloCC::create());
    return s;
    
}


bool HelloCC::init(){
    CCLayer::init();
    
//    CCLog("Hello CC");
    
    CCSprite *s = CCSprite::create("img.jpg");
    s->setAnchorPoint(ccp(0, 0));
    addChild(s);
    
//    CCSprite *s = new CCSprite();
//    s->autorelease();
//    s->initWithFile("img.jpg");
//    
//    addChild(s);
//    s->release();
//    CCLog("%d",s->retainCount());
    
    
    return true;
}