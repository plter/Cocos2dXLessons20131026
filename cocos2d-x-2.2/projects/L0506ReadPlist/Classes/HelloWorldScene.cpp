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
    
    
    CCArray *arr = CCArray::createWithContentsOfFile("users.plist");
    
    CCObject *obj;
    CCDictionary *dict;
    
    CCARRAY_FOREACH(arr, obj){
        dict = (CCDictionary*)obj;
        
        CCLog("name:%s,age:%d",dict->valueForKey("name")->getCString(),dict->valueForKey("age")->intValue());
    }
//    CCArray *arr1 = new CCArray();
//    arr1->initWithArray(CCArray::createWithContentsOfFile("users.plist"));
    
    
    CCDictionary *dic = CCDictionary::createWithContentsOfFile("users1.plist");
    
    return true;
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
