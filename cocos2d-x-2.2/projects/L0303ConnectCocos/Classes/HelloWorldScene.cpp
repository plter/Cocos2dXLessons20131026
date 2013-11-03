#include "HelloWorldScene.h"
#include "CCBridge.h"

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
    
    setTouchEnabled(true);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    label = CCLabelTTF::create("Show Toast", "Courier", 48);
    addChild(label);
    label->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    if (label->boundingBox().containsPoint(((CCTouch*)pTouches->anyObject())->getLocation())) {
        CCBridge::showToast("Hello Android");
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
