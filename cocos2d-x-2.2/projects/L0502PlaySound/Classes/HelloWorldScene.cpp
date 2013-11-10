#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

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
    
    //SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound.mp3");
    
    setTouchEnabled(true);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    btnPlaySound = CCLabelTTF::create("Play Sound", "Courier", 32);
    btnPlaySound->setPosition(ccp(visibleSize.width/2, visibleSize.height-btnPlaySound->getContentSize().height));
    addChild(btnPlaySound);
    
    btnStopSound = CCLabelTTF::create("Stop Sound", "Courier", 32);
    btnStopSound->setPosition(ccp(visibleSize.width/2, visibleSize.height-btnStopSound->getContentSize().height*2));
    addChild(btnStopSound);
    
    btnPauseSound = CCLabelTTF::create("Pause Sound", "Courier", 32);
    btnPauseSound->setPosition(ccp(visibleSize.width/2, visibleSize.height-btnPauseSound->getContentSize().height*3));
    addChild(btnPauseSound);
    
    btnResumeSound = CCLabelTTF::create("Resume Sound", "Courier", 32);
    btnResumeSound->setPosition(ccp(visibleSize.width/2, visibleSize.height-btnResumeSound->getContentSize().height*4));
    addChild(btnResumeSound);
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCPoint p = ((CCTouch*)pTouches->anyObject())->getLocation();
    
    if (btnPlaySound->boundingBox().containsPoint(p)) {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound.mp3");
    }else if (btnStopSound->boundingBox().containsPoint(p)){
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }else if (btnPauseSound->boundingBox().containsPoint(p)){
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }else if (btnResumeSound->boundingBox().containsPoint(p)){
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
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
