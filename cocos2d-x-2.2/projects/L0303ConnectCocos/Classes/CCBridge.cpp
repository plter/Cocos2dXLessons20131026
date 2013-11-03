//
//  CCBridge.cpp
//  L0303ConnectCocos
//
//  Created by plter on 13-11-3.
//
//

#include "CCBridge.h"
#include "CurrentJavaVM.h"


void CCBridge::showToast(const char * msg){
    JavaVM *vm = CurrentJavaVM::getJavaVM();
    JNIEnv *env;
    vm->AttachCurrentThread(&env, NULL);
    jclass jc = env->FindClass("cn/eoe/conncc/CCBridge");
    jmethodID mid = env->GetStaticMethodID(jc, "showToast", "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(jc, mid,env->NewStringUTF(msg));
}