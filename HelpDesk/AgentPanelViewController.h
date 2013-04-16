//
//  AgentPanelViewController.h
//  HelpDesk
//
//  Created by Matt Van Veenendaal on 1/10/13.
//  Copyright (c) 2013 ShowKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AgentPanelViewController : UIViewController <UIAlertViewDelegate>

@property (nonatomic, strong) IBOutlet UIView *displayView;
@property (nonatomic, strong) IBOutlet UIButton *endCall;

- (IBAction)hangUpCall:(id)sender;

@end
