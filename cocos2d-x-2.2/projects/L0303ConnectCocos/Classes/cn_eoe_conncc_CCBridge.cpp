//
//  cn_eoe_conncc_CCBridge.cpp
//  L0303ConnectCocos
//
//  Created by plter on 13-11-3.
//
//

#include "cn_eoe_conncc_CCBridge.h"
#include "CurrentJavaVM.h"

/*
 * Class:     cn_eoe_conncc_CCBridge
 * Method:    initNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_eoe_conncc_CCBridge_initNative
(JNIEnv *env, jclass){
    JavaVM *vm;
    env->GetJavaVM(&vm);
    CurrentJavaVM::setJavaVM(vm);
}