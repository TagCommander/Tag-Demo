#import <CoreFoundation/CoreFoundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@interface TCRestaurants : NSObject<CLLocationManagerDelegate>

- (NSArray *) restaurantsWithFilters: (NSArray *) filters;
+ (UIImage *) getImage: (NSDictionary *) photo;

@property (retain, nonatomic) NSArray *restaurants;
@property (retain, nonatomic) CLLocationManager *locationManager;
@property (retain, nonatomic) NSMutableArray *typesFilter;

@end
