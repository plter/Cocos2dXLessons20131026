//
//  People.cpp
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include "People.h"

namespace eoe {
    
    People::People(int _age,const char *_name):Object(){
        age = _age;
        name = _name;
    }
    
    
    void People::sayHi(){
        
        std::cout<<"People class\n";
        std::cout<<"Hello "<<name<<"\n";
    }
    
}