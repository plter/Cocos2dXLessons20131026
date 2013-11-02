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
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    label = CCLabelTTF::create("Click me", "Courier", 48);
    label->setRotation(45);
    label->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    addChild(label);
    
    setTouchEnabled(true);
    
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch * touch;
    
//    for (CCSetIterator it = pTouches->begin(); it!=pTouches->end(); it++) {
//        touch = (CCTouch*)*it;
//    }
    
    touch = (CCTouch*)pTouches->anyObject();
    CCPoint p = touch->getLocation();
    
    if(label->boundingBox().containsPoint(p)){
        CCLog("Button Clicked");
    }
    
//    CCLog(">>>>");
//    CCMessageBox("Message", "Title");
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
