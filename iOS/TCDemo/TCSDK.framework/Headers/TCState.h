//
//  TCState.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TCCore/TCSingleton.h>
#import <TCCore/ITCEventSenderDelegate.h>
#import <TCCore/TCMacros.h>
#import <TCCore/TCLog.h>

@class TCEventSender;
@class UIApplication;

@interface TCState : TCSingleton <ITCEventSenderDelegate>
{
@private
    BOOL locationAvailable;
    double tcLongitude;
    double tcLatitude;
}

SINGLETON_CLASS_H(TCState)

#pragma mark - Background delegates
- (void) didEnterBackground: (UIApplication *) application;
- (void) willEnterForeground: (UIApplication *) application;

#pragma mark - Location
- (void) setLocationAvailable: (BOOL) locationAvailable;
- (BOOL) isLocationAvailable;
- (void) setLongitude: (double) longitude andLatitude: (double) latitude;
- (double) longitude;
- (double) latitude;

#pragma mark - Date & Time Methods
- (NSDate *) date;

#pragma mark - Unit Tests Access
- (id) reinit;

@property (nonatomic, retain) TCEventSender *senderDelegate;

@end
