//
//  Img2.cpp
//  L0405Effects
//
//  Created by plter on 13-11-9.
//
//

#include "Img2.h"
#include "HelloWorldScene.h"


CCScene* Img2::scene(){
    
    CCScene* s = CCScene::create();
    s->addChild(Img2::create());
    
    return s;
}


bool Img2::init(){
    CCLayer::init();
    
    setTouchEnabled(true);
    
    CCSprite *s = CCSprite::create("img2.jpg");
    s->setAnchorPoint(ccp(0, 0));
    addChild(s);
    
    return true;
}


void Img2::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCDirector::sharedDirector()->popScene();
    
//    CCDirector::sharedDirector()->popToRootScene();
    
//    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(1, HelloWorld::scene()));
}
