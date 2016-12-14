//
//  TagCommander.h
//  TagCommander
//
//  Created by Damien TERRIER on 03/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <TCCore/TCMacros.h>
#import <TCCore/ITCDynamicStore.h>
#import <TCCore/TCEventSender.h>

@class TCSDKInitialisation;
@class TCDynamicStore;
@class TCAppVars;
@class TCProduct;

@interface TagCommander : NSObject <ITCDynamicStore, ITCEventSenderDelegate>

/**
* Designated initializer.
*
* @param siteID The TagCommander Side ID.
* @param containerID The TagCommander Container ID.
*/
- (id) initWithSiteID: (int) siteID andContainerID: (int) containerID;
- (id) initWithSiteID: (int) siteID andContainerID: (int) containerID andNotificationCenter: (NSNotificationCenter *) notificationCenter;

- (void) sendData;
- (void) execute: (TCAppVars *) appVars;
- (void) addPermanentData: (NSString *) key withValue: (NSString *) value;
- (NSString *) getPermanentData: (NSString *) key;
- (NSString *) removePermanentData: (NSString *) key;
- (void) addData: (NSString *) key withProduct: (TCProduct *) product;

- (NSString *) getPostData: (TCAppVars *) appVars;

#pragma mark - public properties
@property (nonatomic, assign) int containerID;
@property (nonatomic, assign) int siteID;
@property (nonatomic, assign) int numberOfProducts;
@property (nonatomic, retain) NSString *url;

@property (nonatomic, retain) TCDynamicStore *dynamicStore;
@property (nonatomic, retain) TCDynamicStore *permanentStore;
@property (nonatomic, retain) TCEventSender *senderDelegate;

@property (nonatomic, retain) NSOperationQueue *queue;
@property (nonatomic, strong) TCSDKInitialisation *initialisation;

@end
