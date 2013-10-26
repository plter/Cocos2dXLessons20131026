//
//  Man.cpp
//  L0104HelloCPP
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include "Man.h"

namespace eoe {
    
    Man::Man(int _age,const char *_name):People(_age,_name){
        
    }
    
    void Man::love(eoe::Woman &woman){
        std::cout<<getName()<<" loves a woman called "<<woman.getName()<<"\n";
    }
    
    void Man::sayHi(){
        std::cout<<"Man class\n"<<"Hello "<<getName()<<"\n";
    }
}