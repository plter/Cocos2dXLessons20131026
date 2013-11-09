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
    
    //定义SpriteFrame缓存
    CCSpriteFrameCache *cache  = CCSpriteFrameCache::sharedSpriteFrameCache();
    //根据plist配置文件缓存动画的每一帧
    cache->addSpriteFramesWithFile("p.plist", "p.png");
    
    //创建数组用于存放动画的每一帧
    CCArray *sframes = CCArray::create();
    
    //定义缓冲区，用于生成帧名字
    char buf[10];
    memset(buf, 0, 10);
    
    for (int i=0; i<3; i++) {
        
        //生成帧名字
        sprintf(buf, "g%04d",i);
        
        //根据帧的名字获取到指定的帧，并把该帧添加到数组中
        sframes->addObject(cache->spriteFrameByName(buf));
    }
    
    //根据帧数组生成Animation对象
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(sframes,0.3f);
    //根据Animatio对象生成Animate动作
    CCAnimate *animate = CCAnimate::create(animation);
    
    CCSprite * sprite = CCSprite::create();
    addChild(sprite);
    sprite->setAnchorPoint(ccp(0, 0));
    sprite->setPosition(ccp(50, 50));
    
    //执行该动画
    sprite->runAction(CCRepeatForever::create(animate));
    
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
