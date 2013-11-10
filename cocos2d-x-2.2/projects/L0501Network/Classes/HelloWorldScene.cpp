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
    
    hc = CCHttpClient::getInstance();
    
    CCHttpRequest *req = new CCHttpRequest();
    req->setUrl("http://localhost:8080/JeeServer/index.jsp?a=AAAA&b=BBBB");
    req->setRequestType(CCHttpRequest::kHttpGet);
    req->setResponseCallback(this, httpresponse_selector(HelloWorld::httpCompleteHandler));
    hc->send(req);
    req->release();
    
    return true;
}

void HelloWorld::httpCompleteHandler(cocos2d::extension::CCHttpClient *client, cocos2d::extension::CCHttpResponse *response){
    
    std::vector<char> * data = response->getResponseData();
    int len = data->size();
    char buf[len+1];
    memset(buf, 0, len);
    
    int i=0;
    for (i=0; i<len; i++) {
        buf[i] = data->at(i);
    }
    buf[i]='\0';
    
    CCLog("%s",buf);
    
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
