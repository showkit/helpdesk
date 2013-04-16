/*
 File:      SHKNotification.h

 Framework: ShowKit

 Copyright 2013 Curious Minds Inc. All rights reserved.

 */

/*!
    @file  SHKNotification.h
    @class SHKNotification
 
    @brief
    Container object for notifications posted by ShowKit.
 
 */

@interface SHKNotification : NSObject
/*!
    Stores the Key for what has been changed (see Constants.h)
 */
@property (assign)              NSString* const Key         ;
/*!
    Stores the new Value for the associated Key.
 */
@property (retain, nonatomic)   id<NSObject>    Value       ;
/*!
    Stores a UserObject (if applicable, see Constants.h)
 */
@property (retain, nonatomic)   id<NSObject>    UserObject  ;

/*!
 Create a new SHKNotification
 @param key         Set the Key to be associated with the notification
 @param value       Set the Value for the key to be associated with the notification
 */
+ (SHKNotification*) notificationWithKey: (NSString* const) key andValue: (id<NSObject>) value;
/*!
 Create a new SHKNotification
 @param key         Set the Key to be associated with the notification
 @param value       Set the Value for the key to be associated with the notification
 @param userObject  Set the UserObject to be associated with the notification
 */
+ (SHKNotification*) notificationWithKey: (NSString* const) key andValue: (id<NSObject>) value andUserObject: (id<NSObject>) userObject;

@end
