//
//  SupportViewController.m
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import "SupportViewController.h"
#import <Parse/Parse.h>
#import <ShowKit/ShowKit.h>
#import "AppDelegate.h"

@interface SupportViewController ()

@end

@implementation SupportViewController

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

- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [[NSNotificationCenter defaultCenter]
     addObserver:self
     selector:@selector(connectionStateChanged:)
     name:SHKConnectionStatusChangedNotification
     object:nil];
    [[NSNotificationCenter defaultCenter]
     addObserver:self
     selector:@selector(remoteClientStatusChanged:)
     name:SHKRemoteClientStateChangedNotification
     object:nil];
}

- (void) viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:SHKConnectionStatusChangedNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:SHKRemoteClientStateChangedNotification object:nil];
}

- (void) viewDidAppear:(BOOL)animated {
    //todo: signup the user to ShowKit and save the details in NSUserDefaults if no user exists
    self.foundAgent = NO;
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    
    if ([[userDefaults objectForKey:@"showkit_username"] length] > 0) {
        [self setupCallingWithUsername:[userDefaults objectForKey:@"showkit_username"] password:[userDefaults objectForKey:@"showkit_password"]];
    } else {
        __block SupportViewController *bSelf = self;
        __block NSString *bPassword = [[NSUUID UUID] UUIDString];
        [ShowKit registerUser:[[NSUUID UUID] UUIDString] password:bPassword apiKey:kShowKitApiKey withCompletionBlock:^(NSString *username, NSError *error) {
            NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
            [userDefaults setObject:username forKey:@"showkit_username"];
            [userDefaults setObject:bPassword forKey:@"showkit_password"];
            [userDefaults synchronize];
            [bSelf setupCallingWithUsername:username password:bPassword];
        }];
        return;
    }
    
}

- (void) setupCallingWithUsername:(NSString *)username password:(NSString *)password {
    self.agents = nil;
    __block SupportViewController *bSelf = self;
    
    [ShowKit login:username password:password withCompletionBlock:^(NSString *const connectionStatus) {
        PFQuery *userQuery = [PFUser query];
        [userQuery findObjectsInBackgroundWithBlock:^(NSArray *results, NSError *error) {
            bSelf.agents = [NSMutableArray arrayWithArray:results];
            [bSelf callNextSupportAgent];
        }];
    }];
}

- (void) callNextSupportAgent {
    if ([self.agents count] > 0) {
        [SHKParseUser initiateCallWithPFUser:[self.agents lastObject]];
        [self.agents removeLastObject];
         return;
    }
    self.statusLabel.text = @"No Agents Available";
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) connectionStateChanged: (NSNotification*) n
{
    SHKNotification* s ;
    NSString * v ;
    
    s = (SHKNotification*) [n object];
    v = (NSString*)s.Value;
    
    if ([v isEqualToString:SHKConnectionStatusCallTerminated]){
        //call is terminated
        if (!self.foundAgent) {
            [self callNextSupportAgent];
        } else {
            self.foundAgent = NO;
        }
    } else if ([v isEqualToString:SHKConnectionStatusInCall]) {
        self.foundAgent = YES;
        [ShowKit setState: SHKVideoInputDeviceScreen forKey: SHKVideoInputDeviceKey]; //share your screen
        [ShowKit setState:SHKGestureCaptureLocalIndicatorsOn forKey:SHKGestureCaptureLocalIndicatorsModeKey];
    }
}

- (void) remoteClientStatusChanged: (NSNotification*) n
{
    SHKNotification* s;
    NSString*        status;
    
    s = (SHKNotification*) [n object];
    status = (NSString*)s.Value;
    
    NSLog(@"Remote client status changed: %@", status);
    
    if ([status isEqualToString:SHKRemoteClientGestureStateStarted]) {
        NSLog(@"Remote Client Gesture Started");
        [ShowKit setState:SHKGestureCaptureModeReceive
                   forKey:SHKGestureCaptureModeKey]; //allow incoming gestures!!
    }
}


@end
