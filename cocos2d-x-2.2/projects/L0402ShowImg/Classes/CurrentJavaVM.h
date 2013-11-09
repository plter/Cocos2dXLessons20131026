//
//  CurrentJavaVM.h
//  L0402ShowImg
//
//  Created by plter on 13-11-9.
//
//

#ifndef __L0402ShowImg__CurrentJavaVM__
#define __L0402ShowImg__CurrentJavaVM__

#include <iostream>
#include <jni.h>

class CurrentJavaVM {
    
public:
    static inline void setJavaVM(JavaVM* vm){
        _javaVm = vm;
    }
    
    static inline JavaVM * getJavaVM(){
        return _javaVm;
    }
    
private:
    static JavaVM * _javaVm;
};

#endif /* defined(__L0402ShowImg__CurrentJavaVM__) */
