//
//  main.cpp
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <string>
#include "People.h"
#include "Man.h"

using namespace std;
using namespace eoe;

int main(int argc, const char * argv[])
{

//    string name = "LiMing";
//    Man *m = new Man(20,name.c_str());
//    m->sayHi();
//    
//    m->sayHello();
//    
//    Woman woman(20,"Xiaoli");
//    
//    m->love(woman);
//    
//    delete m;
    
    
    People *p = new People(20,"ZhangSan");
    printf("%s ,retain count is %d\n",p->getName(),p->retainCount());
    p->release();
    
    return 0;
}

