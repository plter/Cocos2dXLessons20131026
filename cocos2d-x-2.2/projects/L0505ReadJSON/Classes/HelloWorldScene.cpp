#include "HelloWorldScene.h"
#include "json.h"

USING_NS_CC;
using namespace Json;

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
    
    unsigned long fileSize;
    unsigned char * fileData = CCFileUtils::sharedFileUtils()->getFileData("data.json", "r", &fileSize);
    
    Reader r;
    
    Value root;
    r.parse((const char*)fileData, (const char*)(fileData+fileSize), root,false);
    
    Value peopleArr = root["people"];
    Value people;
    
    for (Value::iterator it = peopleArr.begin(); it!=peopleArr.end(); it++) {
        people = *it;
        CCLog("name:%s,age:%d",people["name"].asCString(),people["age"].asInt());
    }
    
    
    
    CCLog("size : %d",peopleArr.size());

    for (int i=0; i<peopleArr.size(); i++) {
        people = peopleArr[i];
        
        CCLog("name:%s,age:%d",people["name"].asCString(),people["age"].asInt());
    }

    
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
