#import "TCRestaurants.h"

@implementation TCRestaurants
@synthesize restaurants;
@synthesize locationManager;
@synthesize typesFilter;

- (id) init
{
    self = [super init];
    if (self)
    {
        [self configureLocationManager];
        [self configureDefaults];
        restaurants = [self fetchRestaurantsWithFilters: nil];
    }
    
    return self;
}

- (NSArray *) fetchRestaurantsWithFilters: (NSArray *) filters
{
    //Nearby
    return [self loadJSONData: [self formatGeoURLWithFilters: filters]];
}

- (NSArray *) loadJSONData: (NSString *) URL
{
    NSArray *fetchedRestaurants = [NSArray array];
    NSURL *url = [NSURL URLWithString: URL];
    NSData *rawJsonData = [NSData dataWithContentsOfURL: url];
    
    if (rawJsonData)
    {
        NSError *error = nil;
        NSDictionary *jsonDictionary = [NSJSONSerialization JSONObjectWithData: rawJsonData options: NSJSONReadingMutableContainers error: &error];
        
        fetchedRestaurants = [jsonDictionary objectForKey: @"results"];
    }
    return fetchedRestaurants;
}

- (NSString *) formatGeoURLWithFilters: (NSArray *) filters
{
    NSString *baseURL = @"https://maps.googleapis.com/maps/api/place/nearbysearch/json";
    NSString *key = @"AIzaSyDz2gE-4xuZ0J0_TtD7IduclOSFcl2IOFY";
    NSString *location = @"48.872219,2.326563";
    NSString *radius = [[NSNumber numberWithInt:200] stringValue];
    NSString *sensor = @"false";
    
    NSString *stringTypes = @"meal_takeaway";
    if (filters)
    {
        stringTypes = @"meal_delivery%7Cmeal_takeaway%7Cfood%7Crestaurant";
    }
        
    NSString *URL = [NSString stringWithFormat: @"%@?key=%@&location=%@&radius=%@&sensor=%@&types=%@", baseURL, key, location, radius, sensor, stringTypes];
    return URL;
}

- (NSArray *) restaurantsWithFilters: (NSArray *) filters
{
    restaurants = [self fetchRestaurantsWithFilters: filters];
    return restaurants;
}

- (void) configureLocationManager
{
    locationManager = [[CLLocationManager alloc] init];
    locationManager.delegate = self;
    locationManager.distanceFilter = kCLDistanceFilterNone;
    locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    [locationManager startUpdatingLocation];
}

- (void) locationManager: (CLLocationManager *) manager didUpdateLocations: (NSArray *) locations
{
    CLLocation *location = (CLLocation *) [locations lastObject];
    NSLog(@"Last location %@", location);
    [locationManager stopUpdatingLocation];

    restaurants = [self loadJSONData: @""];

}

- (void) locationManager: (CLLocationManager *) manager didUpdateToLocation: (CLLocation *) newLocation fromLocation:(CLLocation *) oldLocation
{
    NSLog(@"OldLocation %f %f", oldLocation.coordinate.latitude, oldLocation.coordinate.longitude);
    NSLog(@"NewLocation %f %f", newLocation.coordinate.latitude, newLocation.coordinate.longitude);
}

- (void) configureDefaults
{
    typesFilter = [@[@"meal_takeway", @"meal_delivery", @"food", @"restaurant"] mutableCopy];
}

+ (UIImage *) getImage: (NSDictionary *) photo
{
    id path = [[self class] imageURL: photo];
    NSURL *url = [NSURL URLWithString: path];
    NSData *data = [NSData dataWithContentsOfURL: url];
    UIImage *img = [[UIImage alloc] initWithData: data];
    
    return img;
}

+ (NSString *) imageURL: (NSDictionary *) photo
{
    NSString *baseURL = @"https://maps.googleapis.com/maps/api/place/photo";
    NSString *key = @"AIzaSyDz2gE-4xuZ0J0_TtD7IduclOSFcl2IOFY";
    NSString *maxheight = [[NSNumber numberWithInt:400] stringValue];
    NSString *sensor = @"false";
    NSString *photoreference = [photo objectForKey: @"photo_reference"];
    
    NSString *URL = [NSString stringWithFormat: @"%@?key=%@&maxheight=%@&sensor=%@&photoreference=%@", baseURL, key, maxheight, sensor, photoreference];
    return URL;
}

@end
