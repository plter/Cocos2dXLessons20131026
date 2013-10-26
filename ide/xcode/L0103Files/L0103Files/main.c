//
//  main.c
//  L0103Files
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

//    FILE * f = fopen("hello.txt", "w");
//    fprintf(f, "Hello %d\n",100);
//    fclose(f);
    
    FILE *f = fopen("hello.txt", "r");
//    char c = fgetc(f);
    
    char buf[100];
    memset(buf,0,100);
    
    fgets(buf, 20, f);
    
    printf("%s\n",buf);
    
//    fscanf(<#FILE *restrict#>, <#const char *restrict, ...#>)
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

