//
//  HelloOC.m
//  L0304OCPP
//
//  Created by plter on 13-11-3.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#import "HelloOC.h"
#import <string>

class HelloCPP {
    
public:
    static void log(const char * msg){
        [HelloOC log:msg];
    }
};


@implementation HelloOC


+(void)sayHello{
    std::string str = "Hello Objective-C++";
    HelloCPP::log(str.c_str());
}

+(void)log:(const char *)msg{
    NSLog(@"%s",msg);
}


@end