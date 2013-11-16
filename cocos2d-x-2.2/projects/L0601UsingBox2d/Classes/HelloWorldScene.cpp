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
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    float b2MaxX = size.width/RATIO;
    float b2MaxY = size.height/RATIO;
    rectArr = new CCArray();
    setTouchEnabled(true);
    
    
    world = new b2World(b2Vec2(0, -10));
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    
    b2BodyDef bodyDef;
    b2PolygonShape shape;
    
    //create floor
    bodyDef.type = b2_staticBody;
    bodyDef.position = b2Vec2(b2MaxX/2, 0);
    b2Body * floor = world->CreateBody(&bodyDef);
    //init floor shape properties
    shape.SetAsBox(b2MaxX/2, 0.5);
    floor->CreateFixture(&shape, 1);
    
    //create left
    bodyDef.type = b2_staticBody;
    bodyDef.position = b2Vec2(0, b2MaxY/2);
    b2Body * left = world->CreateBody(&bodyDef);
    //init left shape properties
    shape.SetAsBox(0.5, b2MaxY/2);
    left->CreateFixture(&shape, 1);
    
    
    //create right
    bodyDef.type = b2_staticBody;
    bodyDef.position = b2Vec2(b2MaxX, b2MaxY/2);
    b2Body * right = world->CreateBody(&bodyDef);
    //init right shape properties
    shape.SetAsBox(0.5, b2MaxY/2);
    right->CreateFixture(&shape, 1);
    
    scheduleUpdate();
    return true;
}


void HelloWorld::update(float dt){
    
//    CCObject *obj;
//    CCARRAY_FOREACH(rectArr, obj){
//        rect = (ColorRect*)obj;
//        rect->syncStatus();
//        
//        if(!rect->getB2Body()->IsAwake()){
//            rectArr->removeObject(rect);
//            world->DestroyBody(rect->getB2Body());
//            rect->removeFromParent();
//            break;
//        }
    
//        if (rect->getB2Body()->GetLinearVelocity().y<=0&&
//            rect->getB2Body()->GetLinearVelocity().x<=0) {
//            
//            rectArr->removeObject(rect);
//            world->DestroyBody(rect->getB2Body());
//            rect->removeFromParent();
//        }
        
        //rect->getB2Body()->ApplyForceToCenter(b2Vec2(0, rect->getB2Body()->GetMass()*9));
//    }
    
    CCSprite * s;
    
    for (b2Body *b = world->GetBodyList(); b!=NULL; b=b->GetNext()) {
        if (b->GetUserData()!=NULL) {
            s = (CCSprite*)b->GetUserData();
            s->setPositionX(b->GetPosition().x*RATIO);
            s->setPositionY(b->GetPosition().y*RATIO);
            s->setRotation(-b->GetAngle()/M_PI*180);
            
            if (!b->IsAwake()) {
                b->SetUserData(NULL);
                s->removeFromParent();
                world->DestroyBody(b);
            }
        }
    }
    
    world->Step(dt, 8, 3);
}

void HelloWorld::addRect(cocos2d::CCPoint &cocosPosition){
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
//    bodyDef.angularVelocity = M_PI;
    bodyDef.linearVelocity = b2Vec2(0, 5);
    bodyDef.allowSleep = true;
    bodyDef.position = b2Vec2(cocosPosition.x/RATIO, cocosPosition.y/RATIO);
    
    b2Body * body = world->CreateBody(&bodyDef);
    
    b2PolygonShape shape;
    shape.SetAsBox(20.0f/RATIO, 20.0f/RATIO);
    
    body->CreateFixture(&shape, 1);
    
    rect = ColorRect::create();
    addChild(rect);
    rect->setRatio(RATIO);
    rect->setB2Body(body);
    
    body->SetUserData(rect);
    
//    rectArr->addObject(rect);
}

void HelloWorld::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
    CCPoint p = ((CCTouch*)pTouches->anyObject())->getLocation();
    
    addRect(p);
    
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
