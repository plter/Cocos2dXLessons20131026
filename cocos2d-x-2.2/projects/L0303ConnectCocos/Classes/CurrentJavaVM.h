//
//  CurrentJavaVM.h
//  L0303ConnectCocos
//
//  Created by plter on 13-11-3.
//
//

#ifndef __L0303ConnectCocos__CurrentJavaVM__
#define __L0303ConnectCocos__CurrentJavaVM__

#include <iostream>
#include <jni.h>

class CurrentJavaVM {
    
public:
    static JavaVM* getJavaVM();
    static void setJavaVM(JavaVM *vm);
    
private:
    static JavaVM *_jvm;
};

#endif /* defined(__L0303ConnectCocos__CurrentJavaVM__) */
