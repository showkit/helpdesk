//
//  SupportViewController.h
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SupportViewController : UIViewController

@property (nonatomic, strong) IBOutlet UILabel *statusLabel;
@property (nonatomic, strong) NSMutableArray *agents;

@property (nonatomic, assign) bool foundAgent;

@end
