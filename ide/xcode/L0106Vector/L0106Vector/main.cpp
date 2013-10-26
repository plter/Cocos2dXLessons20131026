//
//  main.cpp
//  L0106Vector
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

    vector<char> chars;
    chars.push_back('H');
    chars.push_back('e');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('o');
    
//    chars[2]
    vector<char>::iterator it;
    for (it=chars.begin(); it!=chars.end(); it++) {
        cout<<*it<<"\n";
    }
    
    return 0;
}

