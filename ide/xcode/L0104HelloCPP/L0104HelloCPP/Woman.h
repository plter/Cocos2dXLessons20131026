//
//  Woman.h
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#ifndef __L0104HelloCPP__Woman__
#define __L0104HelloCPP__Woman__

#include <iostream>
#include "People.h"

namespace eoe {
    class Woman:public People{
    public:
        Woman(int age,const char *name);
    };
}

#endif /* defined(__L0104HelloCPP__Woman__) */
