//
// Created by JeanJulien on 03/11/2016.
// Copyright (c) 2016 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ITCDynamicStore.h"
#import "TCSingleton.h"
#import "TCMacros.h"

@interface TCCoreVariables : TCSingleton <ITCDynamicStore>

SINGLETON_CLASS_H(TCCoreVariables)

- (void) initializeAllCoreVariables;
- (id) reinit;

@property (nonatomic, retain) TCDynamicStore *dynamicStore;

@end
