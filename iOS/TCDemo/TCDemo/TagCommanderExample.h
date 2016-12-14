//
//  TagCommanderExample.h
//  TCDemo Test App
//
//  Created by Damien TERRIER on 4/25/13.
//  Copyright (c) 2013 Damien TERRIER. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TC_SITE_ID 3311
#define TC_CONTAINER_ID 2

@class TagCommander;

@interface TagCommanderExample : NSObject

+ (TagCommander *) getTagcommander;
+ (TagCommander *) tagcommander;

+ (NSString *) buildPageNameWithChapter: (NSString *) chapter subChapter: (NSString *) subChapter screen: (NSString *) screen andClick: (NSString *) click;

+ (void) sendScreenEvent: (NSString *) screenName withRestaurant: (NSString *)restaurant andRating: (NSString *) rating;
+ (void) sendClickEvent: (NSString *) screenName forClick: (NSString *) clickType withRestaurant: (NSString *) restaurant andRating: (NSString *) rating;

@end
