//
//  IPeople.h
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0104HelloCPP__IPeople__
#define __L0104HelloCPP__IPeople__

#include <iostream>


namespace eoe {
    class IPeople{
    public:
        virtual int getAge()=0;
        virtual const char *getName()=0;
    };
}

#endif /* defined(__L0104HelloCPP__IPeople__) */
