/*
 File:      ShowKit.h

 Framework: ShowKit

 Copyright 2013 Curious Minds Inc. All rights reserved.

 */

/*!
 @file  ShowKit.h
 @class ShowKit
 
 @brief ShowKit facilitates video, audio, screen, and gesture sharing between two clients.
 
 
 See Constants.h for available modes, values, and notifications.  Users must be registered with the http://api.showkit.com API.  For best results,
 ensure users logout after logging in.  Logins will expire after 1 hour if no activity is recorded, but it is possible a user can be banned after
 several sessions if they do not logout before logging in again too quickly.
 
 Notifications to observe:
 
    SHKConnectionStatusChangedNotification  -> Notifies on (un)successful login, incoming call, call terminated, etc. (See Constants.h)
    SHKRemoteClientStateChangedNotification -> Notifies on remote video start/stop, audio start/stop, gesture start/stop.
 
 Building against this API requires use of the C++11 standard and libc++ as the standard library.
*/

#import <ShowKit/Constants.h>
#import <ShowKit/SHKNotification.h>
#import <ShowKit/SHKParseUser.h>
#import <ShowKit/SHKGLContext.h>
#import <ShowKit/SHKTouches.h>

@interface ShowKit : NSObject

/*!
 *
 *  @return A shared instance of ShowKit
 *
 */
+ (ShowKit*) sharedInstance ;

/*!
 *
 *  Update ShowKit state with a dictionary instead of one key at a time. Only keys that are specified in the dictionary will be updated.  All others will be left as is.
 *
 *  @param  dictionary      NSDictionary containing keys and values you wish to update.
 *
 */
+ (void) setConfig: (NSDictionary*) dictionary;

/*!
 *
 *  Get the current state for a key.  Some keys will pass back UIViews, and some will pass back NSDictionary. Most will pass back NSString constants.
 *  Check Constants.h for what type each key requires.
 *
 *  @param  key             Configuration key for which to get the current state.
 *
 *  @return NSObject of the current key state.
 *
 */
+ (id) getStateForKey: (NSString* const) key;

/*!
 *
 *  Set the current state for a key.  Some keys will require UIViews, and some will require NSDictionary. Most will reuire NSString constants.
 *  Check Constants.h for what type each key requires.
 *
 *  @param  state           NSObject you wish to set for the key.
 *  @param  key             Configuration key you wish to set the state for.
 *
 */
+ (void) setState: (id) state forKey: (NSString* const) key;

/*! 
 *
 *
 *  Register a user with the ShowKit API.  This method is provided for convenience.  All other interaction with the ShowKit REST API must be done externally.  The completion block's
 *  username parameter will not be exactly the same as the username provided.  The username passed by the completion block is the username that must be
 *  used to login and make calls.
 *
 *  @param  username        Desired username for api.showkit.com
 *  @param  password        Desired password for the user.
 *  @param  apiKey          api.showkit.com key for your account.
 *  @param  block           Completion handler block.  Will be called when registration is complete.  NSError will be NIL on success.
 *
 */
+ (void) registerUser: (NSString*) username password: (NSString*) password apiKey: (NSString*) apiKey withCompletionBlock:(void (^)(NSString* username, NSError* error)) block;

/*!
 *
 *  Login a user. Success or failure will be posted to SHKConnectionStatusChangedNotification.
 *
 *  @param  username        User's api.showkit.com username.
 *  @param  password        User's api.showkit.com password.
 *
 */
+ (void) login: (NSString*) username password: (NSString*) password;

/*!
 *
 *  Login a user. Success or failure will be posted to SHKConnectionStatusChangedNotification.  The SHKNotification.UserObject will contain the passed object
 *
 *  @param  username        User's api.showkit.com username.
 *  @param  password        User's api.showkit.com password.
 *  @param  object          NSObject to be passed back with the notification.
 *
 */
+ (void) login: (NSString*) username password: (NSString*) password withCompletionObject: (NSObject*) object;

/*!
 *
 *  Login a user. Success or failure will be posted to SHKConnectionStatusChangedNotification as well as passed with the specified block.
 *
 *  @param  username        User's api.showkit.com username.
 *  @param  password        User's api.showkit.com password.
 *  @param  block           Block to be called on completion, will pass the current connection status indicating success or failure.
 *
 */
+ (void) login: (NSString*) username password: (NSString*) password withCompletionBlock:  (void (^)(NSString* const connectionStatus)) block;

/*!
 *
 *  log the current user out of ShowKit
 */
+ (void) logout;

/*!
 *
 *
 *  Accept an incoming call.  You will be notified with SHKConnectionStatusCallIncoming from SHKConnectionStatusChangedNotification
 */
+ (void) acceptCall;

/*!
 *
 *
 *  Reject an incoming call. You will be notified with SHKConnectionStatusCallIncoming from SHKConnectionStatusChangedNotification
 * 
 */
+ (void) rejectCall;

/*!
 *
 *
 *  End the current call.
 *
 */
+ (void) hangupCall;

/*!
 *
 *  When the user is called, you will be notified of the call starting by SHKConnectionStatusInCall from SHKConnectionStatusChangedNotification
 *  or failing by receiving an SHKConnectionStatusCallTerminated.  At the end of a successful call, you will received SHKConnectionStatusCallTerminated.
 *
 *  @param username         api.showkit.com username to call.
 *
 *  @return FALSE if user is already on a call, or if a call is incoming.
 *
 */
+ (BOOL) initiateCallWithUser: (NSString*) username;

/*!
 *
 *  Send up to 800 bytes of data to the remote client.  The remote client will receive a SHKUserMessageReceivedNotification with the data you send.
 *
 *  @param  message      A message of up to 800 bytes.
 *
 *  @return FALSE if `message' is more than 800 bytes or if for some reason sending fails.
 *
 */
+ (BOOL) sendMessage: (NSData*) message ;


/*!
 *  Get the version number of ShowKit.
 *
 *  @return NSString with Version number.
 */
+ (NSString*) version;
@end
