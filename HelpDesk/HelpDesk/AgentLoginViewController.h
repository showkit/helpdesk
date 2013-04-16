//
//  AgentLoginViewController.h
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AgentLoginViewController : UIViewController <UITextFieldDelegate>

@property (nonatomic, strong) IBOutlet UITextField *username;
@property (nonatomic, strong) IBOutlet UITextField *password;
@property (nonatomic, strong) IBOutlet UIButton *loginButton;

- (IBAction)login:(id)sender;

@end
