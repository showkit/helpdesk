//
//  AgentSignupViewController.m
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import "AgentSignupViewController.h"
#import <Parse/Parse.h>
#import "SVProgressHUD.h"

@interface AgentSignupViewController ()

@end

@implementation AgentSignupViewController

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

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

- (IBAction)registerAgent:(id)sender {
    PFUser *user = [PFUser user];
    user.username = self.username.text;
    user.password = self.password.text;
    user.email = self.email.text;
    [SVProgressHUD show];
    __block AgentSignupViewController *bSelf = self;
    
    [user signUpInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
        if (!error) {
            [SVProgressHUD showSuccessWithStatus:@"Success"];
            NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
            [userDefaults setObject:bSelf.username.text forKey:@"username"];
            [userDefaults setObject:bSelf.password.text forKey:@"password"];
            [userDefaults synchronize];
            [bSelf.navigationController popViewControllerAnimated:YES];
        } else {
            [SVProgressHUD showErrorWithStatus:[[error userInfo] objectForKey:@"error"]];
        }
    }];
}
@end
