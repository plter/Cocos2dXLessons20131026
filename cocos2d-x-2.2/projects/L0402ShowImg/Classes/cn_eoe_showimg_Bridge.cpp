//
//  cn_eoe_showimg_Bridge.cpp
//  L0402ShowImg
//
//  Created by plter on 13-11-9.
//
//

#include "cn_eoe_showimg_Bridge.h"
#include "CurrentJavaVM.h"
#include "HelloWorldScene.h"
#include "cocos2d.h"

USING_NS_CC;

/* Inaccessible static: onBridgeInitListener */
/*
 * Class:     cn_eoe_showimg_Bridge
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_eoe_showimg_Bridge_init
(JNIEnv *env, jclass){
    
    JavaVM *vm;
    env->GetJavaVM(&vm);
    CurrentJavaVM::setJavaVM(vm);
}

/* Inaccessible static: onBridgeInitListener */
/*
 * Class:     cn_eoe_showimg_Bridge
 * Method:    showImg
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cn_eoe_showimg_Bridge_showImg
(JNIEnv *env, jclass, jstring imgName){
    
    CCSprite* s = CCSprite::create(env->GetStringUTFChars(imgName, NULL));
    
    HelloWorld::getCurrentInstance()->addChild(s);
}