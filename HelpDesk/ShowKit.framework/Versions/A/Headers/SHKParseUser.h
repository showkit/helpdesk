/*
 File:      SHKParseUser.h

 Framework: ShowKit

 Copyright 2013 Curious Minds Inc. All rights reserved.

 */
/*!
    @file  SHKParseUser.h
    @class SHKParseUser
    
    @brief Connect to ShowKit and Parse using a PFUser.

        This is an alternative method for interacting with ShowKit and Parse.
 */
#import <UIKit/UIKit.h>

@class PFUser;

/*! @cond */
typedef void (^SHKParseUserResultBlock)(PFUser *user, NSError *error, NSString* const connectionStatus);
/*! @endcond */

@interface SHKParseUser : NSObject

/*!
 *
 *  Makes an asynchronous request to log in a user with specified credentials.
 *  Returns an instance of the successfully logged in `PFUser`. This will also cache
 *  the user locally so that calls to `userFromCurrentUser` will use the latest logged in user.
 *
 *  @param username The username of the user.
 *  @param password The password of the user.
 *  @param block The block to execute. The block should have the following argument signature: (PFUser *user, NSError *error, NSString* const connectionStatus)
 *
 *
 */
+ (void)logInWithPFUsernameInBackground:(NSString *)username
                             password:(NSString *)password
                                block:(SHKParseUserResultBlock)block;

/*!
 *
 *  Logs out the currently logged in user on disk.
 */
+ (void) logOut;


/*!
 *
 *  When the user is called, you will be notified of the call starting by `SHKConnectionStatusInCall` from `SHKConnectionStatusChangedNotification`
 *  or failing by receiving an `SHKConnectionStatusCallTerminated` or `SHKConectionStatusCallFailed` with an `NSError`.  At the end of a successful call, you will receive `SHKConnectionStatusCallTerminated`.
 *
 *  @param user         PFUser to call
 */
+ (void) initiateCallWithPFUser: (PFUser*) user;



@end
