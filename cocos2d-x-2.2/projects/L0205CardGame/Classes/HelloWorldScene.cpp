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
    
    allPoints = new CCPointArray();
    allPoints->initWithCapacity(60);
    
    cards = new CCArray();
    cards->initWithCapacity(60);
    
    setTouchEnabled(true);
    
    startGame();
    
    return true;
}



void HelloWorld::startGame(){
    
    currentNum = 1;
    
    genAllPoints();
    addCards();
}

void HelloWorld::genAllPoints(){
    
    while (allPoints->count()>0) {
        allPoints->removeControlPointAtIndex(0);
    }
    
    for (int i=0; i<10; i++) {
        for (int j=0; j<6; j++) {
            allPoints->addControlPoint(ccp(i*80,j*80));
        }
    }
    
}


void HelloWorld::addCards(){
    
    Card *card;
    CCPoint p;
    int randNum;
    
    srand(time(NULL));
    
    for (int i=1; i<=9; i++) {
        card = Card::create();
        card->setNum(i);
        
        randNum = rand()%allPoints->count();
        p = allPoints->getControlPointAtIndex(randNum);
        allPoints->removeControlPointAtIndex(randNum);
        
        card->setPosition(p);
        cards->addObject(card);
        addChild(card);
    }
}


void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCTouch *t = (CCTouch*)pTouches->anyObject();
    CCPoint p = t->getLocation();
    
    CCObject *obj;Card *card;
    CCARRAY_FOREACH(cards, obj){
        card = (Card*)obj;
        
        if (card->boundingBox().containsPoint(p)) {
//            CCLog("num:%d",card->getNum());
            
            if (card->getNum()==currentNum) {
                
                card->removeFromParent();
                cards->removeObject(card);
                
                if (currentNum==1) {
                    showAllCardVerso();
                }
                
                currentNum++;
                
                if (cards->count()<=0) {
                    CCMessageBox("Success", "Note");
                }
            }else{
                CCMessageBox("Error", "Alert");
            }
            
            break;
        }
    }
    
}


void HelloWorld::showAllCardVerso(){
    CCObject *obj;
    Card *card;
    CCARRAY_FOREACH(cards, obj){
        card = (Card*)obj;
        card->showVerso();
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
