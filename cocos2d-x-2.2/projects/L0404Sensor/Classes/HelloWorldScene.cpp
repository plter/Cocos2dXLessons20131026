#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    setAccelerometerEnabled(true);
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    circleArr = new CCArray();
    
    for (int i=0; i<20; i++) {
        circle = Circle::create();
        circle->setPosition(ccp(200, 200));
        circle->setMaxX(size.width);
        circle->setMaxY(size.height);
        addChild(circle);
        circleArr->addObject(circle);
    }
    
    scheduleUpdate();
    return true;
}


void HelloWorld::didAccelerate(cocos2d::CCAcceleration *pAccelerationValue){
    
    CCObject *obj;
    CCARRAY_FOREACH(circleArr, obj){
        circle = (Circle*)obj;
        
        circle->setAX(pAccelerationValue->x);
        circle->setAY(pAccelerationValue->y);
    }
    //    CCLog("x:%f,y:%f,z:%f",pAccelerationValue->x,pAccelerationValue->y,pAccelerationValue->z);
}


void HelloWorld::update(float dt){
    CCObject *obj;
    CCARRAY_FOREACH(circleArr, obj){
        circle = (Circle*)obj;
        
        circle->move();
    }
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
