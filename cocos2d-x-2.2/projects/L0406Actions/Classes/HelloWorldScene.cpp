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
    
    pLabel = CCLabelTTF::create("Hello World", "Arial", 48);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(visibleSize.width/2,
                            visibleSize.height/2));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    setTouchEnabled(true);
        
    return true;
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *event){
    
//    pLabel->runAction(CCRepeat::create(CCRotateBy::create(1, 90), 2));
//    pLabel->runAction(CCRepeatForever::create(CCRotateBy::create(1, 90)));
    
//    pLabel->runAction(CCSpawn::create(
//                                      CCRotateBy::create(1, 90),
//                                      CCMoveBy::create(1, ccp(-100, -100)),NULL
//                                      )
//                      );
    
    
    pLabel->runAction(CCSequence::create(
                                      CCRotateBy::create(1, 90),
                                         CCMoveBy::create(1, ccp(-100, -100)),CCCallFunc::create(this, callfunc_selector(HelloWorld::actionsComplete)),NULL
                                      )
                      );
}


void HelloWorld::actionsComplete(){
    CCMessageBox("Actions Complete", "title");
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
