//
//  main.c
//  L0102Strings
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char * argv[])
{

    const char *a = "Hello";
    const char *b = "World";
    
//    sprintf(b, "%s","World");//error
    
//    b = "Hello World";
//    char buf[10];
//    buf[0] = 'H';
//    buf[1] = 'e';
//    buf[2] = 'l';
//    buf[3] = 'l';
//    buf[4] = 'o';
//    buf[5] = '\0';
    
//    printf("Length of buf :%ld\n",strlen(buf));
//    printf("%s\n",b);
//    if (strcmp(a, b)==0) {
//        printf("a and b is same\n");
//    }
    
    char buf[100];
    memset(buf, 0, 100);
    
//    strcat(buf, a);
//    strcat(buf, b);
    
//    printf("%s\n",buf);
    
    sprintf(buf, "%s %s,%d",a,b,100);
    return 0;
}

