//
//  TCProduct.h
//  TagCommander
//
//  Created by Damien Terrier on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCProduct : NSObject

- (id) init;

- (NSDictionary *) dictionaryValue;

@property (nonatomic, retain) NSMutableDictionary *customProperties;

@property (nonatomic, retain) NSString *ID;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, assign) NSString *quantity;
@property (nonatomic, assign) NSString *category;
@property (nonatomic, assign) NSString *price;
@property (nonatomic, retain) NSString *priceATI;
@property (nonatomic, retain) NSString *discountATI;
@property (nonatomic, retain) NSString *priceTF;
@property (nonatomic, retain) NSString *discountTF;
@property (nonatomic, retain) NSString *trademark;
@property (nonatomic, retain) NSString *URLPage;
@property (nonatomic, retain) NSString *URLPicture;
@property (nonatomic, retain) NSString *rating;
@property (nonatomic, retain) NSString *inStock;

    extern NSString *const kTCProductIDKey;
extern NSString *const kTCProductNameKey;
extern NSString *const kTCProductQuantityKey;
extern NSString *const kTCProductCategoryKey;
extern NSString *const kTCProductPriceKey;
extern NSString *const kTCProductUnitPriceATIKey;
extern NSString *const kTCProductUnitDiscountATIKey;
extern NSString *const kTCProductUnitPriceTFKey;
extern NSString *const kTCProductUnitDiscountTFKey;
extern NSString *const kTCProductTrademark;
extern NSString *const kTCProductURLPage;
extern NSString *const kTCProductURLPicture;
extern NSString *const kTCProductRating;
extern NSString *const kTCProductInStock;

@end
