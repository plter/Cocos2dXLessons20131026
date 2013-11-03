//
//  ViewController.m
//  L0304OCPP
//
//  Created by plter on 13-11-3.
//  Copyright (c) 2013年 plter. All rights reserved.
//

#import "ViewController.h"
#import "HelloOC.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [HelloOC sayHello];
    
//    printf("Hello C");
    
//    HelloCPP *h = new HelloCPP();
//    h->sayHello();
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
