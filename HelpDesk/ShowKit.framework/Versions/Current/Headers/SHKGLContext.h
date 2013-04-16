/*
 File:      SHKGLContext.h

 Framework: ShowKit

 Copyright 2013 Curious Minds Inc. All rights reserved.

 */

/*!
 @file  SHKGLContext.h
 @class SHKGLContext

 @brief Drop-in replacement for EAGLContext to share OpenGL ES content using Screen Sharing.

 Initializing this class will return `nil` if `EAGLRenderingAPI != kEAGLRenderingAPIOpenGLES2`
 
 Usage (i.e., with GLKit): 
 
     self.context = [[SHKGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES2];
 */
#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>

@interface SHKGLContext : EAGLContext
- (id) initWithAPI: (EAGLRenderingAPI) api;
- (id) initWithAPI: (EAGLRenderingAPI) api sharegroup: (EAGLSharegroup*) sharegroup;
- (BOOL) renderbufferStorage: (NSUInteger) target fromDrawable: (id<EAGLDrawable>) drawable;
- (BOOL) presentRenderbuffer:(NSUInteger)target;
@end