/*
 File:      SHKTouches.h

 Framework: ShowKit

 Copyright 2013 Curious Minds Inc. All rights reserved.

 */
/*!
 @file  SHKTouches.h
 @class SHKTouches

 @brief
 The public api for touch and gesture sharing.
 
 */
#import <UIKit/UIKit.h>

@class SHKTouches;

/*!
    @brief
    Force ShowKit to update the controls if actionable controls are added after viewDidAppear.
 */
@interface UIViewController (SHKTouches)
/*!
    Force ShowKit to update the UIViewController.  In most cases this does not need to be called, however if actionable controls have been added to a view after viewDidAppear this will need to be called.
 */
- (void)shkNeedsUpdate;
@end

/*! 
 @protocol SHKTouchesDelegate
 @brief
 Implement this protocol to receive touch points sent by the remote client if receiving gestures.  It is not necessary to set the SHKTouches delegate.
 
 */
@protocol SHKTouchesDelegate <NSObject>
@required
/*! 
 Called when remote touches begin.
 @param gesture         Pointer to the calling SHKGesture session
 @param point           Point touch began at.
 */
 
- (void)shkTouchesBegan:(SHKTouches *)gesture atPoint:(CGPoint)point;
/*!
 Called when remote touches move.
 @param gesture         Pointer to the calling SHKGesture session
 @param point           Point touch moved to.
 */

- (void)shkTouchesMoved:(SHKTouches *)gesture atPoint:(CGPoint)point;
/*!
 Called when remote touches end.
 @param gesture         Pointer to the calling SHKGesture session
 @param point           Point touch ended at.
 */

- (void)shkTouchesEnded:(SHKTouches *)gesture atPoint:(CGPoint)point;
/*!
 Called when remote touches are canceled.
 @param gesture         Pointer to the calling SHKGesture session
 @param point           Point touch was canceled.
 */

- (void)shkTouchesCancelled:(SHKTouches *)gesture atPoint:(CGPoint)point;
@end

@interface SHKTouches : NSObject
@property (readwrite, nonatomic) int tapCount;
+ (SHKTouches *) gestureManager;

@end
