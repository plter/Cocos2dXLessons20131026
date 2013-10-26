//
//  Object.h
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0104HelloCPP__Object__
#define __L0104HelloCPP__Object__

#include <iostream>

class Object {
    
public:
    Object(){
        _retainCount = 1;
    };
    
    virtual void retain(){
        _retainCount++;
    }
    
    virtual int retainCount(){
        return _retainCount;
    }
    
    virtual void release(){
        _retainCount--;
    }
    
    virtual void delloc(){
        delete this;
    }
    
private:
    int _retainCount;
};

#endif /* defined(__L0104HelloCPP__Object__) */
