//
//  main.cpp
//  L0108RandNum
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    srand((unsigned int)time(NULL));
    
    for (int i=0; i<100; i++) {
        std::cout<<rand()<<"\n";
    }
    
    return 0;
}

