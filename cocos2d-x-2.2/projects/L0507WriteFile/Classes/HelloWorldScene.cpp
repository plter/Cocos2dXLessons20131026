#include "HelloWorldScene.h"
//#include "cocos-ext.h"
//#include "Json.h"
#include <fstream>
#include <sstream>

USING_NS_CC;
//USING_NS_CC_EXT;

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
    
    // :: 静态成员访问
    // -> 指针成员访问
    // .  值成员访问
    
//    std::string *writablePath;
//    (*writablePath)+="aaa";
    
//    CCFileUtils *fu = CCFileUtils::sharedFileUtils();
//    *writablePath = (*fu).getWritablePath();
//    
//    *writablePath = fu->getWritablePath();
    
//
//    CCLog("%s",path.c_str());
    
//    std::fstream fs;
//    fs.open(path.c_str());
//    fs<<"Hello iOS\n";
//    fs.flush();
//    fs.close();
    
    //>>>>>>>>>>>>>>>>
    //    std::stringbuf sbuf;
    //
    //    std::ifstream in;
    //    in.open(path.c_str());
    //
    //    in>>&sbuf;
    //
    //    CCLog("File data:%s",sbuf.str().c_str());
    //    in.close();
    //<<<<<<<<<<<<<<<<<<<<<<<
    
    
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
    std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
    path+="/data.txt";
    
    CCLog("%s",path.c_str());
    
    std::ofstream of;
    of.open(path.c_str());
    
    of<<"Hello iOS\n";
    of.flush();
    of.close();
    
#elif (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
    //android only
    std::ofstream writeToSdCard;
    writeToSdCard.open("/mnt/sdcard/data.txt");
    writeToSdCard<<"Hello Android \n";
    writeToSdCard.close();
#endif
    
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
