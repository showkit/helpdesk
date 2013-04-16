//
//  ObjectsViewController.m
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/15/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import "ObjectsViewController.h"
#import <ShowKit/ShowKit.h>

@interface ObjectsViewController ()

@end

@implementation ObjectsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self shkNeedsUpdate];
}

@end
