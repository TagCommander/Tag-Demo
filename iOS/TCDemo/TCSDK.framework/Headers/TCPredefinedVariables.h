//
// Created by Jean-Julien ZEIL on 31/10/14.
// Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TCCore/ITCDynamicStore.h>
#import <TCCore/TCDynamicStore.h>

#import <TCCore/TCSingleton.h>
#import <TCCore/TCMacros.h>

@interface TCPredefinedVariables : TCSingleton <ITCDynamicStore>

SINGLETON_CLASS_H(TCPredefinedVariables)

- (id) reinit;

- (void) predefinedVariableInitialisation;
- (unsigned long long) now;
- (unsigned long long) nowMs;
- (NSString *) nowString;
- (NSString *) nowMsString;

- (void) computeTimeChangingVariables;

#pragma mark - random Methods
- (int) randomInt;
- (NSString *) randomString;

#pragma mark - Generic info
- (NSString *) IP;
- (NSString *) phoneModel;
- (NSString *) systemName;
- (NSString *) systemVersion;
- (NSString *) tagCommanderVersion;
- (NSString *) applicationVersion;
- (NSString *) applicationBuild;
- (NSString *) language;
- (NSString *) charset;
- (NSString *) currencySymbol;
- (NSString *) currencyCode;
- (NSString *) uniqueIdentifier;
- (NSString *) screenSize;
- (NSString *) orientation;
- (NSString *) userAgent;
- (NSString *) manufacturer;
- (NSString *) localConnexion;
- (NSString *) navNumberVisit;
- (NSString *) numberSession;
- (NSString *) nav_TimestampCurrentVisit;
- (NSString *) nav_TimestampCurrentVisitMs;
- (NSString *) timestampCurrentVisit;
- (NSString *) timestampCurrentVisitMs;
- (NSString *) timestampLastCall;
- (NSString *) timestampLastCallMs;

@property (nonatomic, retain) TCDynamicStore *dynamicStore;
- (void) firstExecute;

@property (nonatomic, assign) bool isBackground;
@property (nonatomic, assign) int totalForegroundTransitions;
@property (nonatomic, assign) unsigned long long totalForegroundTime;
@property (nonatomic, assign) unsigned long long deltaForeground;
@property (nonatomic, assign) unsigned long long totalBackgroundTime;
@property (nonatomic, assign) unsigned long long deltaBackground;
@property (nonatomic, assign) unsigned long long lastTime;
@property (nonatomic, assign) unsigned long long startUsage;
@property (nonatomic, retain) NSString *pid;

@property (nonatomic, assign) unsigned long long visitDuration;

@end
