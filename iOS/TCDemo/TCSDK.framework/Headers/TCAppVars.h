//
//  TCAppVars.h
//  TagCommander
//
//  Created by Damien Terrier on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TCCore/ITCDynamicStore.h>

@class TCDynamicStore;

@interface TCAppVars : NSObject<ITCDynamicStore, NSCoding>

- (id) initWithDictionary: (NSDictionary *) dictionary;

- (void) addData: (NSString *) variableName withProducts: (NSArray *) products;
- (void) addData: (TCDynamicStore *) store;
- (void) addData: (NSString *) key withValue: (NSString *) value;
- (NSString *) getData: (NSString *) key;
- (NSString *) removeData: (NSString *) key;

@property (nonatomic, retain) TCDynamicStore *dynamicStore;

@end
