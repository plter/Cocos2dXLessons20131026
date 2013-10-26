//
//  People.h
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0104HelloCPP__People__
#define __L0104HelloCPP__People__

#include <iostream>
#include "IPeople.h"
#include "Object.h"

namespace eoe {
    
    class People :public IPeople,public Object{
        
    public:
        People(int _age,const char *_name);
        virtual void sayHi();
        virtual int getAge(){
            return age;
        }
        
        virtual const char* getName(){
            return name;
        }
        
        virtual void release(){
            Object::release();
            
            if (retainCount()<=0) {
                delete this;
            }
        }
        
        ~People(){
            std::cout<<"delloc People\n";
        }
    private:
        int age;
        const char *name;
    };
}

#endif /* defined(__L0104HelloCPP__People__) */
