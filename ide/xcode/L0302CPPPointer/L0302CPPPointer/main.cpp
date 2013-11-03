//
//  main.cpp
//  L0302CPPPointer
//
//  Created by plter on 13-11-3.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>


class Hello {
    
public:
    virtual void sayHello(){
        std::cout<<"Hello CPP\n";
    }
};


int main(int argc, const char * argv[])
{

    Hello *h = new Hello();
    long long pointer = (long long)h;
    
    Hello *h1 = (Hello*)pointer;
    h1->sayHello();
    
    return 0;
}

