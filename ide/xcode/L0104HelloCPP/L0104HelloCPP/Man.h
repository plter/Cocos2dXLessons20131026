//
//  Man.h
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0104HelloCPP__Man__
#define __L0104HelloCPP__Man__

#include <iostream>
#include "People.h"
#include "Woman.h"

using namespace std;

namespace eoe {
    
    class Man:public People {
        
    public:
        Man(int _age,const char *_name);
        
        virtual void sayHi();
        virtual void love(Woman &woman);
        
        inline void sayHello(){
            cout<<getName()<<" Say Hello\n";
        };
    };
}

#endif /* defined(__L0104HelloCPP__Man__) */
