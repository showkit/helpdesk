
/*
    File:       Constants.h
 
    Framework:  ShowKit
 
    Copyright 2013 Curious Minds Inc. All rights reserved.
 
*/

/*!

 @file Constants.h
 @brief NSDictionary keys and values for setting ShowKit state.
 
 The top values for each key are set by default.  Some keys, such as ConnectionStatusKey and the RemoteClient keys, are read only.
    
 Notifications are posted to the `NSNotificationCenter`.

 
 Usage:
 
     [ShowKit setState: SHKTorchModeOn forKey: SHKTorchModeKey];
 
     NSNumber * inBitrate = [ShowKit getStateForKey: SHKConnectionStatusCurrentDataRateInKey];
 
     [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(shkConnectionStatusChanged:) name:SHKConnectionStatusChangedNotification object:nil];
*/

#import <Foundation/Foundation.h>

/*! @cond */
#ifdef __cplusplus
#   define SHK_EXTERN extern "C"
#else
#   define SHK_EXTERN extern
#endif
/*! @endcond */

/*!
 @var SHKMainDisplayViewKey

 @brief This key sets the view that will display the remote user's video stream.  
 Takes a `UIView` as a value. Default is `nil`.

 @param UIView

 */
SHK_EXTERN NSString * const     SHKMainDisplayViewKey;
/*!
 @var SHKPreviewDisplayViewKey
 
 @brief This key sets the view that will display the local user's camera preview.  
 Takes a `UIView` as a value. Default is `nil`.

 @param UIView

 */
SHK_EXTERN NSString * const     SHKPreviewDisplayViewKey;

/*!
 @var SHKLogfileKey
 
 @param NSString
 
 @brief Set a logfile for ShowKit to output errors and debug information.  
 
 Default is `nil`.  To stop logging, set `SHKLogfileKey` to `nil`.
 */

SHK_EXTERN NSString * const     SHKLogfileKey;

/*!
 
 @var SHKGLESSharingKey 
 
 @brief This is for more advanced GLES Screen Sharing needs.  It is strongly recommended that you use the SHKGLContext class if you do not require explicit control over what is shared.

 `SHKGLESSharingKey` takes as input an `NSDictionary` with an `EAGLContext` marked by `SHKGLESContextKey` and a `CAEAGLLayer` connected to that context marked by `SHKGLESLayerKey`.
 When queried, returns an `NSDictionary` with the values for `SHKGLESFBOKey` and `SHKGLESTextureNameKey` filled in.
 You will need to draw to the FBO returned in order for your GLES data to be shared.  The texture returned is the FBO color attachment.  It will have the same
 dimensions as the CAEAGLLayer provided.
 You may optionally attach your own depth buffer and stencil buffer attachments to the FBO provided.
 Set GLESContextKey's value to `[NSNull null]` if you wish to disable GLES sharing while continuing screen sharing.

 <b>Note that you may not receive an FBO and Texture immediately upon submitting the context and layer as this is an asynchronous operation.</b>
 
 
 @param SHKGLESContextKey           EAGLContext you wish to share.
 @param SHKGLESLayerKey             CAEAGLLayer attached to the context.
 
 @return SHKGLESFBOKey              The Framebuffer Object that you will need to draw to to share content.
 @return SHKGLESTextureNameKey      The texture name of the FBO's color attachment
 
*/

SHK_EXTERN NSString * const     SHKGLESSharingKey ; /*! @cond */
SHK_EXTERN NSString * const         SHKGLESContextKey;
SHK_EXTERN NSString * const         SHKGLESLayerKey;
// read-only
SHK_EXTERN NSString * const         SHKGLESFBOKey;
SHK_EXTERN NSString * const         SHKGLESTextureNameKey; /*! @endcond */


/*!

 @var SHKUserMessageReceivedNotification
 
 
 @brief This notification is fired when a message is received from the remote user via `+(BOOL) [ShowKit sendMessage:]`
 */

SHK_EXTERN NSString * const     SHKUserMessageReceivedNotification; /*! @cond */
SHK_EXTERN NSString * const         SHKUserMessageKey; /*! @endcond */

// All keys below this will only take NSString* const


/*!
 
 @var SHKConnectionStatusChangedNotification
 
 @brief This notification is fired when the connection state changes.  You may access the new status via `SHKConnectionStatusKey`.
 */
SHK_EXTERN NSString * const     SHKConnectionStatusChangedNotification;

/*!
 
 @var SHKConnectionStatusKey [Read-Only]

 @brief  This will return the current connection status.  
 All statuses stand on their own with the exception of `SHKConnectionStatusCallIncoming`, which will include the calling user in UserObject, and `SHKConectionStatusCallFailed`, which will return
 an NSError in the UserObject parameter with the following status codes:

        500: User Does Not Exist           :: User is attempting to call a user who does not exist on the ShowKit system.
        501: User Unavailable              :: User is attempting to call a user who is not online
        502: Calling Service Unreachable   :: User is on a network that is preventing ShowKit from making a call, though they may still receive calls.
        599: Unknown Error                 :: An unknown error has occurred, please contact ShowKit support with a logfile and steps to reproduce.
 
 @return Current connection status

 */

SHK_EXTERN NSString * const     SHKConnectionStatusKey;/*! @cond */
SHK_EXTERN NSString * const         SHKConnectionStatusNotConnected;
SHK_EXTERN NSString * const         SHKConnectionStatusLoggedIn;
SHK_EXTERN NSString * const         SHKConnectionStatusLoginFailed;
SHK_EXTERN NSString * const         SHKConnectionStatusCallIncoming;
SHK_EXTERN NSString * const         SHKConnectionStatusCallOutgoing;
SHK_EXTERN NSString * const         SHKConnectionStatusCallFailed;
SHK_EXTERN NSString * const         SHKConnectionStatusInCall;
SHK_EXTERN NSString * const         SHKConnectionStatusCallTerminating;
SHK_EXTERN NSString * const         SHKConnectionStatusCallTerminated;/*! @endcond */

/*!
 
 @var SHKConnectionStatusCurrentDataRateOutKey [Read-Only]
 @brief The current measured output data rate
 @return NSNumber   Current sending data rate.
*/
SHK_EXTERN NSString * const     SHKConnectionStatusCurrentDataRateOutKey;
/*!

 @var SHKConnectionStatusCurrentDataRateInKey [Read-Only]
 @brief The current measured input data rate
 @return NSNumber  Current receiving data rate.
 */
SHK_EXTERN NSString * const     SHKConnectionStatusCurrentDataRateInKey;

/*!
 
 @var SHKAudioInputModeKey

 @brief Set the audio input mode to recording or muted.

 @param NSString* const         `SHKAudioInputModeRecording, SHKAudioInputModeMuted`

 */
 
SHK_EXTERN NSString * const     SHKAudioInputModeKey;/*! @cond */
SHK_EXTERN NSString * const         SHKAudioInputModeRecording;
SHK_EXTERN NSString * const         SHKAudioInputModeMuted;/*! @endcond */

/*!
 
 @var SHKVideoInputDeviceKey
 
 @brief Set the current video input device.

 @param NSString* const         `SHKVideoInputDeviceFrontCamera, SHKVideoInputDeviceBackCamera, SHKVideoInputDeviceScreen, SHKVideoInputDeviceNone`

 */

SHK_EXTERN NSString * const     SHKVideoInputDeviceKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoInputDeviceFrontCamera;
SHK_EXTERN NSString * const         SHKVideoInputDeviceBackCamera;
SHK_EXTERN NSString * const         SHKVideoInputDeviceScreen;
SHK_EXTERN NSString * const         SHKVideoInputDeviceNone; /*! @endcond */

/*!
 
 @var SHKVideoScaleModeKey
 
 @brief Set how the remote video is presented in the view.
 
 Set the video scale on the `SHKMainDisplayView` in the following ways:
 - Crop :: Crop the image, maintaining aspect and filling view.
 - Fit  :: Fit the image within the view, maintaining aspect and leaving black bars in excess space.
 - Fill :: Fill the view, disregarding aspect ratio.

 @param NSString* const         `SHKVideoScaleModeCrop, SHKVideoScaleModeFit, SHKVideoScaleModeFill`

 */

SHK_EXTERN NSString * const     SHKVideoScaleModeKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoScaleModeCrop;  
SHK_EXTERN NSString * const         SHKVideoScaleModeFit;    
SHK_EXTERN NSString * const         SHKVideoScaleModeFill;  /*! @endcond */


/*!
 
 @var SHKVideoInputDeviceResolutionKey
 
 @brief Set the preferred video resolution.
 
 720P video is currently only available on the following devices:
 - iPhone 5 and higher,
 - iPod Touch 5th generation and higher,
 - iPad 4th generation and higher, and iPad Mini 1st generation and higher.

 Other devices will default to Standard (VGA) with the exception of single-core devices whcih will use Low (QVGA).

 Video resolution will scale up and down from Low to the highest set value depending on network conditions

 This value must be set before a call is made or received.

 @param NSString* const         `SHKVideoInputDeviceResolutionStandard, SHKVideoInputDeviceResolution720p, SHKVideoInputDeviceResolutionLow`
 
 */

SHK_EXTERN NSString * const     SHKVideoInputDeviceResolutionKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoInputDeviceResolutionStandard;
SHK_EXTERN NSString * const         SHKVideoInputDeviceResolution720p;
SHK_EXTERN NSString * const         SHKVideoInputDeviceResolutionLow; /*! @endcond */

/*!
 
 @var SHKVideoInputDeviceFPSKey

 @brief Set the preferred video frame rate.
 
 Single-core devices are locked at 15FPS. All others can do 30FPS.

 This value must be set before a call is made or received.
 
 @param NSString* const         `SHKVideoInputDeviceFPS30, SHKVideoInputDeviceFPS15`
 
 */

SHK_EXTERN NSString * const     SHKVideoInputDeviceFPSKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoInputDeviceFPS30;
SHK_EXTERN NSString * const         SHKVideoInputDeviceFPS15; /*! @endcond */


/*!

 @var SHKVideoPlaybackLatencyKey
 
 @brief Set the preferred playback latency.  
 
 Higher latency will leave more CPU resources available for your app, while lower latency
 will provide more immediate playback at the expense of CPU resources.  Latency may increase or decrease depending on CPU activity.

 This value must be set before a call is made or received.
 
 @param NSString* const         `SHKVideoPlaybackLatencyMedium, SHKVideoPlaybackLatencyHigh, SHKVideoPlaybackLatencyLow`

 */

SHK_EXTERN NSString * const     SHKVideoPlaybackLatencyKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoPlaybackLatencyMedium;
SHK_EXTERN NSString * const         SHKVideoPlaybackLatencyHigh;
SHK_EXTERN NSString * const         SHKVideoPlaybackLatencyLow; /*! @endcond */


/*!

 @var SHKVideoInputDeviceScreenModeKey
 
 @brief Set the video input device.

 If you are sharing OpenGLES content and do not wish to share UIKit content, SHKVideoInputDeviceScreenModeGLESAccelerated will
 provide GLES sharing at lower CPU and GPU cost.

 @param NSString* const         `SHKVideoInputDeviceScreenModeNormal, SHKVideoInputDeviceScreenModeGLESAccelerated`
 
 */

SHK_EXTERN NSString * const     SHKVideoInputDeviceScreenModeKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoInputDeviceScreenModeNormal;            // Capture UIKit and GLES.
SHK_EXTERN NSString * const         SHKVideoInputDeviceScreenModeGLESAccelerated;   // Do not attempt to capture UIKit data.
/*! @endcond */

/*!
 
 @var SHKVideoLocalPreviewModeKey
 
 @brief Enable or disable showing a preview of the local user's camera in the Main Display view when not in a call.

 @param NSString* const         `SHKVideoLocalPreviewEnabled, SHKVideoLocalPreviewDisabled`
 
 */

SHK_EXTERN NSString * const     SHKVideoLocalPreviewModeKey; /*! @cond */
SHK_EXTERN NSString * const         SHKVideoLocalPreviewEnabled;
SHK_EXTERN NSString * const         SHKVideoLocalPreviewDisabled; /*! @endcond */

/*!
 
 @var SHKGestureCaptureModeKey
 
 @brief Set the gesture sharing to either broadcast touches the local user is making, receive touches broadcast by the remote user, or disable.
 
 @param NSString * const        `SHKGestureCaptureModeOff, SHKGestureCaptureModeBroadcast, SHKGestureCaptureModeReceive`
 
 */

SHK_EXTERN NSString * const     SHKGestureCaptureModeKey; /*! @cond */
SHK_EXTERN NSString * const         SHKGestureCaptureModeOff;
SHK_EXTERN NSString * const         SHKGestureCaptureModeBroadcast;
SHK_EXTERN NSString * const         SHKGestureCaptureModeReceive; /*! @endcond */

/*!
 
 @var SHKGestureCaptureNeedsUpdateKey

 @brief Force the gesture capture session to update its mapping of active UIKit controls.

 @param NSString * const            `SHKGestureCaptureNeedsUpdateTrue, SHKGestureCaptureNeedsUpdateFalse`
 

 */

SHK_EXTERN NSString * const     SHKGestureCaptureNeedsUpdateKey; /*! @cond */
SHK_EXTERN NSString * const         SHKGestureCaptureNeedsUpdateTrue;
SHK_EXTERN NSString * const         SHKGestureCaptureNeedsUpdateFalse; /*! @endcond */


/*!
 
 @var SHKGestureCaptureLocalIndicatorsModeKey

 @brief Enable or disable displaying local and remote touches on screen.
 
 @param NSString* const             `SHKGestureCaptureLocalIndicatorsOff, SHKGestureCaptureLocalIndicatorsOn`

 
 */

SHK_EXTERN NSString * const     SHKGestureCaptureLocalIndicatorsModeKey; /*! @cond */
SHK_EXTERN NSString * const         SHKGestureCaptureLocalIndicatorsOff;
SHK_EXTERN NSString * const         SHKGestureCaptureLocalIndicatorsOn; /*! @endcond */



/*!
 
 @var SHKTorchModeKey


 @brief Enable or disable the torch associated with a particular camera.  
 If the camera does not have a torch, it will be set to `SHKTorchModeUnsupported` if
 attempting to enable the torch.  `SHKTorchModeAuto` will automatically enable or disable torch depending on lighting conditions.

 @param NSString* const         `SHKTorchModeOff, SHKTorchModeOn, SHKTorchModeAuto, SHKTorchModeUnsupported`
 
 */

SHK_EXTERN NSString * const     SHKTorchModeKey; /*! @cond */
SHK_EXTERN NSString * const         SHKTorchModeOff;
SHK_EXTERN NSString * const         SHKTorchModeOn;
SHK_EXTERN NSString * const         SHKTorchModeAuto;
SHK_EXTERN NSString * const         SHKTorchModeUnsupported; /*! @endcond */


/*!
 
 @var SHKRemoteClientStateChangedNotification

 @brief Remote client has changed ShowKit state.
 
 These are remote client state updates.  The Key value will appear in the SHKNotification.Key field, and the state will be in the SHKNotification.Value field.
 You will receive initial state at the beginning of a call and any time the remote user changes state, you will be notified.  The following keys may be sent with the notification:
 
 - SHKRemoteClientVideoStateKey
    - SHKRemoteClientVideoStateStarted
    - SHKRemoteClientVideoStateStopped
 - SHKRemoteClientAudioStateKey
    - SHKRemoteClientAudioStateStarted
    - SHKRemoteClientAudioStateStopped
 - SHKRemoteClientGestureStateKey
    - SHKRemoteClientGestureStateStarted
    - SHKRemoteClientGestureStateStopped
 - SHKRemoteClientVideoInputKey
    - SHKRemoteClientVideoInputFront
    - SHKRemoteClientVideoInputBack
    - SHKRemoteClientVideoInputScreen
 - SHKRemoteClientDeviceOrientationKey
    - SHKRemoteClientDeviceOrientationPortrait
    - SHKRemoteClientDeviceOrientationPortraitUpsideDown
    - SHKRemoteClientDeviceOrientationLandscapeLeft
    - SHKRemoteClientDeviceOrientationLandscapeRight
 
 Additionally you may query each of the Keys with `[ShowKit getStateForKey:]`
*/
// read-only
SHK_EXTERN NSString * const     SHKRemoteClientStateChangedNotification;
/*! @cond */
// read-only
SHK_EXTERN NSString * const     SHKRemoteClientVideoStateKey;
SHK_EXTERN NSString * const         SHKRemoteClientVideoStateStopped;
SHK_EXTERN NSString * const         SHKRemoteClientVideoStateStarted;

// read-only
SHK_EXTERN NSString * const     SHKRemoteClientAudioStateKey;
SHK_EXTERN NSString * const         SHKRemoteClientAudioStateStopped;
SHK_EXTERN NSString * const         SHKRemoteClientAudioStateStarted;
// read-only
SHK_EXTERN NSString * const     SHKRemoteClientGestureStateKey;
SHK_EXTERN NSString * const         SHKRemoteClientGestureStateStopped;
SHK_EXTERN NSString * const         SHKRemoteClientGestureStateStarted;
// read-only
SHK_EXTERN NSString * const     SHKRemoteClientVideoInputKey;
SHK_EXTERN NSString * const         SHKRemoteClientVideoInputFront;
SHK_EXTERN NSString * const         SHKRemoteClientVideoInputBack;
SHK_EXTERN NSString * const         SHKRemoteClientVideoInputScreen;

// read-only
SHK_EXTERN NSString * const     SHKRemoteClientDeviceOrientationKey;
SHK_EXTERN NSString * const         SHKRemoteClientDeviceOrientationPortrait;
SHK_EXTERN NSString * const         SHKRemoteClientDeviceOrientationPortraitUpsideDown;
SHK_EXTERN NSString * const         SHKRemoteClientDeviceOrientationLandscapeLeft;
SHK_EXTERN NSString * const         SHKRemoteClientDeviceOrientationLandscapeRight;

/*! @endcond */

#undef SHK_EXTERN