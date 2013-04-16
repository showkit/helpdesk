//
//  AgentLoginViewController.m
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//
// Note, the Agent Login & All Agent Operations could occur in a completely different application then the Application that needs support.

#import "AgentLoginViewController.h"
#import <Parse/Parse.h>
#import <ShowKit/ShowKit.h>
#import "SVProgressHUD.h"

@interface AgentLoginViewController ()

@end

@implementation AgentLoginViewController

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

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];

    self.username.text = [userDefaults objectForKey:@"username"];
    self.password.text = [userDefaults objectForKey:@"password"];
}

- (IBAction)login:(id)sender {
    __block AgentLoginViewController *bSelf = self;
    [SVProgressHUD show];
    
    [SHKParseUser logInWithPFUsernameInBackground:self.username.text password:self.password.text block:^(PFUser *user, NSError *error, NSString *const connectionStatus) {
        if (user) {
            if ([connectionStatus isEqualToString:SHKConnectionStatusLoggedIn]) {
                [SVProgressHUD showSuccessWithStatus:@"Logged In"];
                [bSelf performSegueWithIdentifier:@"waiting_for_call" sender:self];
            } else {
                [SVProgressHUD showErrorWithStatus:@"Could not connect to Server"];
            }
        } else {
            [SVProgressHUD showErrorWithStatus:@"Invalid Username/Password"];
        }
    }];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

@end
