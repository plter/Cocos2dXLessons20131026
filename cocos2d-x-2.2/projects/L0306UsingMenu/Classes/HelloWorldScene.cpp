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
    
    CCMessageBox("", "");
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMenuItemImage *item = CCMenuItemImage::create("normal.png", "selected.png", this, menu_selector(HelloWorld::menuHandler));
    CCLabelTTF *label = CCLabelTTF::create("Click me", "Courier", 48);
    label->setPosition(CCPoint(item->getContentSize().width/2, item->getContentSize().height/2));
    item->setTag(0);
    item->addChild(label);
    
    CCMenuItemImage *item1 = CCMenuItemImage::create("normal.png", "selected.png", this, menu_selector(HelloWorld::menuHandler));
    label = CCLabelTTF::create("Click me1", "Courier", 48);
    label->setPosition(ccp(item1->getContentSize().width/2, item1->getContentSize().height/2));
    item1->setPosition(ccp(0, 70));
    item1->addChild(label);
    item1->setTag(1);
    
    CCMenu *menu = CCMenu::create(item,item1,NULL);
    addChild(menu);
    
    return true;
}


void HelloWorld::menuHandler(cocos2d::CCObject *target){
    CCLog("Menu clicked");
    
    CCMenuItemImage *item = (CCMenuItemImage*)target;
    
    switch (item->getTag()) {
        case 0:
            CCLog("Item 0 clicked");
            break;
            
        case 1:
            CCLog("Item 1 clicked");
            break;
        default:
            break;
    }
}

