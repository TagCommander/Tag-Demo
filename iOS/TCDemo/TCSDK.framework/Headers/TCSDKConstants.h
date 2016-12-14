//
//  TCConstants.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#ifndef TagCommander_TCSDKConstants_h
#define TagCommander_TCSDKConstants_h

#import <Foundation/Foundation.h>

extern NSString *const kTCArrayFormat;

extern unsigned long long const kTCVisitDurationDefaultValue;

extern NSString *const kTCManufacturerName;

#pragma mark ComScore
extern NSString *const kTCTimeSinceLastMeasurement;
extern NSString *const kTCSessionStartTimestamp;
extern NSString *const kTCLastSessionStartTimestamp;
extern NSString *const kTCExitTimestamp;
extern NSString *const kTCUsageDuration;
extern NSString *const kTCLastForegroundTime;
extern NSString *const kTCLastBackgroundTime;

#pragma mark HTTP Hit Notifications
extern NSString *const kTCNotification_HitSent;

#pragma mark - configuration
extern NSString *const kTCServerSideURL;

#pragma mark - predefined dynamic variables
extern NSString *const kTCPredefinedVariable_IP;
extern NSString *const kTCPredefinedVariable_Empty;
extern NSString *const kTCPredefinedVariable_Random;

extern NSString *const kTCPredefinedVariable_Language;
extern NSString *const kTCPredefinedVariable_LanguageGA;
extern NSString *const kTCPredefinedVariable_LanguageCS;
extern NSString *const kTCPredefinedVariable_SystemName;
extern NSString *const kTCPredefinedVariable_SystemVersion;
extern NSString *const kTCPredefinedVariable_Model;
extern NSString *const kTCPredefinedVariable_ModelAndVersion;
extern NSString *const kTCPredefinedVariable_Device;

extern NSString *const kTCPredefinedVariable_ScreenResolution;
extern NSString *const kTCPredefinedVariable_Charset;
extern NSString *const kTCPredefinedVariable_CurrencyCode;
extern NSString *const kTCPredefinedVariable_CurrencySymbol;
extern NSString *const kTCPredefinedVariable_ApplicationVersion;
extern NSString *const kTCPredefinedVariable_ApplicationPreviousVersion;
extern NSString *const kTCPredefinedVariable_ApplicationBuild;
extern NSString *const kTCPredefinedVariable_TagCommanderVersion;
extern NSString *const kTCPredefinedVariable_Manufacturer;
extern NSString *const kTCPredefinedVariable_UserAgent;

extern NSString *const kTCPredefinedVariable_JailBroken;
extern NSString *const kTCPredefinedVariable_ColdStarts;
extern NSString *const kTCPredefinedVariable_ForegroundTransitions;
extern NSString *const kTCPredefinedVariable_ForegroundTime;
extern NSString *const kTCPredefinedVariable_DeltaForegroundTime;
extern NSString *const kTCPredefinedVariable_BackgroundTime;
extern NSString *const kTCPredefinedVariable_DeltaBackgroundTime;
extern NSString *const kTCPredefinedVariable_BackgroundUxTime;
extern NSString *const kTCPredefinedVariable_DeltaBackgroundUxTime;

extern NSString *const kTCPredefinedVariable_CurrentCall;
extern NSString *const kTCPredefinedVariable_CurrentCallMs;
extern NSString *const kTCPredefinedVariable_LastCall;
extern NSString *const kTCPredefinedVariable_LastCallMs;
extern NSString *const kTCPredefinedVariable_LastSessionStartMs;
extern NSString *const kTCPredefinedVariable_LastSessionLastHit;
extern NSString *const kTCPredefinedVariable_LastSessionLastHitMs;

extern NSString *const kTCPredefinedVariable_Now;
extern NSString *const kTCPredefinedVariable_NowMs;

extern NSString *const kTCPredefinedVariable_Longitude;
extern NSString *const kTCPredefinedVariable_Latitude;

extern NSString *const kTCPredefinedVariable_BundleID;
extern NSString *const kTCPredefinedVariable_ApplicationName;
extern NSString *const kTCPredefinedVariable_RuntimeName;

extern NSString *const kTCUserDefaultsKey_UniqueID;

extern NSString *const kTCPredefinedVariable_FirstVisit;
extern NSString *const kTCPredefinedVariable_FirstVisitMs;
extern NSString *const kTCPredefinedVariable_LastVisit;
extern NSString *const kTCPredefinedVariable_LastVisitMs;
extern NSString *const kTCPredefinedVariable_CurrentVisit;
extern NSString *const kTCPredefinedVariable_CurrentSession;
extern NSString *const kTCPredefinedVariable_CurrentVisitMs;
extern NSString *const kTCPredefinedVariable_CurrentSessionMs;
extern NSString *const kTCPredefinedVariable_SessionDuration;
extern NSString *const kTCPredefinedVariable_SessionDurationMs;
extern NSString *const kTCPredefinedVariable_CurVersionFirstVisitMs;

extern NSString *const kTCPredefinedVariable_NumberVisits;
extern NSString *const kTCPredefinedVariable_NumberSessions;
extern NSString *const kTCPredefinedVariable_IsFirstVisit;

extern NSString *const kTCPredefinedVariable_IsNewSession;
extern NSString *const kTCPredefinedVariable_UserSessionDurationMs;
extern NSString *const kTCPredefinedVariable_UsageSessionDurationMs;
extern NSString *const kTCPredefinedVariable_AccumulatedBackgroundTime;
extern NSString *const kTCPredefinedVariable_TimeSinceLastExit;
extern NSString *const kTCPredefinedVariable_AccumulatedForegroundTimeWithoutMeasurement;
extern NSString *const kTCPredefinedVariable_LastForegroundTimeWithoutMeasurement;

extern NSString *const kTCPredefinedVariable_EmptyVariableRemoveEqual;
extern NSString *const kTCPredefinedVariable_FirstExecute;

#pragma mark - Timestamp formats
extern NSString *const kTCDateFirstVisitFormat;
extern NSString *const kTCDateLastVisitFormat;
extern NSString *const kTCDateCurrentVisitFormat;
extern NSString *const kTCNumberColdStarts;
extern NSString *const kTCNumberVisitsFormat;
extern NSString *const kTCLastPID;

#pragma mark - Battery level
extern const float kTCLowBatteryWarningLevel;
extern const float kTCBatteryAvailableWarningLevel;

#endif // #ifndef TagCommander_TCSDKConstants_h
