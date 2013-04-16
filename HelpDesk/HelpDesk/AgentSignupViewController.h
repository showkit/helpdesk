//
//  AgentSignupViewController.h
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AgentSignupViewController : UIViewController <UITextFieldDelegate>

@property (nonatomic, retain) IBOutlet UITextField *username;
@property (nonatomic, retain) IBOutlet UITextField *password;
@property (nonatomic, retain) IBOutlet UITextField *email;
@property (nonatomic, strong) IBOutlet UIButton *signupButton;

- (IBAction)registerAgent:(id)sender;

@end
