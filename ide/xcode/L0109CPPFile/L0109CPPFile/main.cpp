//
//  main.cpp
//  L0109CPPFile
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[])
{

//    fstream f("hello.txt",ios_base::out);
//    f<<"Hello "<<1000<<"\n";
//    f.flush();
//    f.close();
    
    stringbuf ss;
    fstream f("hello.txt",ios_base::in);
    f>>&ss;
    
    cout<<ss.str()<<"\n";
    
    return 0;
}

