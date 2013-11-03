//
//  CurrentJavaVM.cpp
//  L0303ConnectCocos
//
//  Created by plter on 13-11-3.
//
//

#include "CurrentJavaVM.h"

JavaVM * CurrentJavaVM::_jvm = NULL;


void CurrentJavaVM::setJavaVM(JavaVM *vm){
    _jvm = vm;
}

JavaVM *CurrentJavaVM::getJavaVM(){
    return _jvm;
}