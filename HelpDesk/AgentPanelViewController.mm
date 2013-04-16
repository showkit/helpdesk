//
//  AgentPanelViewController.m
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import "AgentPanelViewController.h"
#import <ShowKit/ShowKit.h>

@interface AgentPanelViewController ()

@end

@implementation AgentPanelViewController

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
    
    [ShowKit setState:SHKVideoScaleModeFit forKey:SHKVideoScaleModeKey]; //ensure that you can see the whole view.
    
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

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:SHKConnectionStatusChangedNotification object:nil];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self.endCall setHidden:YES];
    [ShowKit setState:SHKGestureCaptureLocalIndicatorsOn forKey:SHKGestureCaptureLocalIndicatorsModeKey];
    [ShowKit setState:self.displayView forKey:SHKMainDisplayViewKey];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [ShowKit setState:nil forKey:SHKMainDisplayViewKey];
}



- (void) remoteClientStatusChanged: (NSNotification*) n
{
#ifdef DEBUG_OUT
    NSLog(@"%@.remoteClientStatusChanged called on: %@ onMainThread: %d", [self class], device.name, [NSThread isMainThread]);
#endif
    SHKNotification* s;
    NSString*        status;
    
    s = (SHKNotification*) [n object];
    status = (NSString*)s.Value;
    
    if ([status isEqualToString:SHKRemoteClientVideoStateStarted]){
        NSLog(@"%@.remoteClientStatusChanged SHKRemoteClientVideoStateStarted", [self class]);
        [ShowKit setState:SHKGestureCaptureModeBroadcast
                   forKey:SHKGestureCaptureModeKey];
        NSLog(@"%@.connectionStateChanged SHKGestureCaptureModeBroadcast", [self class]);
        
    } else if ([status isEqualToString:SHKRemoteClientVideoStateStopped]) {
        NSLog(@"%@.remoteClientStatusChanged SHKRemoteClientVideoStateStopped", [self class]);
    } else if ([status isEqualToString:SHKRemoteClientAudioStateStarted]) {
        NSLog(@"%@.remoteClientStatusChanged SHKRemoteClientAudioStateStarted", [self class]);
    } else if ([status isEqualToString:SHKRemoteClientAudioStateStopped]) {
        NSLog(@"%@.remoteClientStatusChanged SHKRemoteClientAudioStateStopped", [self class]);
    } else if ([status isEqualToString:SHKRemoteClientGestureStateStarted]) {
        NSLog(@"%@.remoteClientStatusChanged SHKRemoteClientGestureStateStarted", [self class]);
    } else if ([status isEqualToString:SHKRemoteClientGestureStateStopped]) {
        NSLog(@"%@.remoteClientStatusChanged SHKRemoteClientGestureStateStopped", [self class]); 
    }
}




- (void) connectionStateChanged: (NSNotification*) n
{
    SHKNotification* s ;
    NSString * v ;
    
    s = (SHKNotification*) [n object];
    v = (NSString*)s.Value;
    
    if ([v isEqualToString:SHKConnectionStatusCallTerminated]){
        [self.endCall setHidden:YES];
        //call is terminated
    } else if ([v isEqualToString:SHKConnectionStatusInCall]) {
        //start gesture sharing
//        [ShowKit setState:SHKGestureCaptureModeBroadcast
//                   forKey:SHKGestureCaptureModeKey];
//        NSLog(@"%@.connectionStateChanged SHKGestureCaptureModeBroadcast", [self class]);
        [self.endCall setHidden:NO];
    } else if ([v isEqualToString:SHKConnectionStatusCallIncoming]) {
        [ShowKit setState: SHKVideoInputDeviceNone forKey: SHKVideoInputDeviceKey]; // Don't show your camera to the user
        UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Incoming Call"
                                                          message:@"Do you want to accept this call?"
                                                         delegate:self
                                                cancelButtonTitle:@"No"
                                                otherButtonTitles:@"Yes", nil];
        [message show];
    }
}


- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    NSString *title = [alertView buttonTitleAtIndex:buttonIndex];
    if ([title isEqualToString:@"Yes"]) {
        [ShowKit acceptCall];
    } else {
        [ShowKit rejectCall];
    }
}


- (IBAction)hangUpCall:(id)sender {
    [ShowKit hangupCall];
}


@end
