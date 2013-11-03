#include "HelloWorldScene.h"

USING_NS_CC;

#define TABLE_CELL_LABEL_TAG 2

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
    
    dataArr = new CCArray();
    for (int i=0; i<100; i++) {
        dataArr->addObject(CCString::createWithFormat("Label %d",i));
    }
    
    tableView = CCTableView::create(this, CCSizeMake(300, 400));
    tableView->setAnchorPoint(ccp(0, 0));
    tableView->setPosition(ccp(100, 100));
    tableView->setDelegate(this);
    addChild(tableView);
    
    return true;
}

CCTableViewCell * HelloWorld::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx){
    
    CCTableViewCell *cell = table->dequeueCell();
    CCLabelTTF *label;
    if (cell==NULL) {
        cell = new CCTableViewCell();
        label = CCLabelTTF::create("Label", "Courier", 48);
        cell->addChild(label);
        label->setTag(TABLE_CELL_LABEL_TAG);
        label->setAnchorPoint(ccp(0, 0));
        cell->setAnchorPoint(ccp(0, 0));
    }else{
        label = (CCLabelTTF*)cell->getChildByTag(TABLE_CELL_LABEL_TAG);
    }
    
    label->setString(((CCString*)dataArr->objectAtIndex(idx))->getCString());
    
    return cell;
}

unsigned int HelloWorld::numberOfCellsInTableView(cocos2d::extension::CCTableView *table){
    return dataArr->count();
}

CCSize HelloWorld::tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx){
    return CCSizeMake(300, 50);
}


void HelloWorld::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell){
    CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(TABLE_CELL_LABEL_TAG);
    CCLog("Click item is %s",label->getString());
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
