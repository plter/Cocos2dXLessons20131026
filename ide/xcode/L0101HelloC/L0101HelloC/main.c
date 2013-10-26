//
//  main.c
//  L0101HelloC
//
//  Created by plter on 13-10-26.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Hello.h"

typedef int INT32;
typedef long int INT64;

typedef struct {
    int age;
    char *name;
//    void (*sayHi);
} People;

typedef struct {
    int age;
    char *name;
} Man;

void PeopleSayHi(People *__this){
    printf("%s say hi\n",__this->name);
}

//char *getName(People *p){
//    return p->name;
//}

#define getName(obj) obj->name
#define MAX(a,b) a>b?a:b

#define MATH_PI 3.141592653

int main(int argc, const char * argv[])
{
    
//    INT32 a = 10;
//    int b =a;

//    sayHi();
    
    People p1;
    p1.age = 18;
    p1.name = "ZhangSan";
    
//    PeopleSayHi(&p1);
//
//    struct People p2 = p1;
//    p2.age = 20;
    
//    printf("age:%d,name:%s\n",p1.age,p1.name);
    
//    PeopleSayHi(p1);
    
//    People *p1 = malloc(sizeof(People));
//    p1->age = 20;
//    p1->name = "ZhangSan";
//    
//    People *p2 = p1;
//    p2->age = 18;
//    
//    printf("age:%d\n",p1->age);
    
//    People *p1 = malloc(sizeof(People));
//    p1->age = 20;
//    
//    Man *m1 = (Man*)p1;
//    
//    printf("%d\n",m1->age);
    
//    double a = MATH_PI;
    
    
//    People * p = malloc(sizeof(People));
//    p->name = "Lisi";
//    
//    PeopleSayHi(p);
//    free(p);
    
    
//    printf("%s\n",getName(p));
    
//    int a = 10;
//    float b = 10.1;
//    
//    double c = MAX(a, b);
//    printf("%g\n",c);
    
//    int a;
//    scanf("%d",&a);
//    printf("User input is %d\n",a);
    
    return 0;
}


