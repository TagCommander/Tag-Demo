#import <MacTypes.h>
#import "TCMapViewController.h"
#import "TCRestaurantDetailViewController.h"
#import "TCLocationModel.h"
#import "TagCommanderExample.h"

@interface TCMapViewController ()

@end

@implementation TCMapViewController
@synthesize locationManager;

- (IBAction) refreshMap: (id) sender
{
    [self updateMapWithFilters: @[]];
}

- (id) initWithNibName: (NSString *) nibNameOrNil bundle: (NSBundle *) nibBundleOrNil
{
    self = [super initWithNibName: nibNameOrNil bundle: nibBundleOrNil];
    if (self)
    {
        // Custom initialization
    }
    return self;
}

- (void) updateMapWithFilters: (NSArray *) filters;
{
    self.restaurants = [self getRestaurantsWithFilters: filters];
    [self plotRestaurantsPositions: self.restaurants];
    
    NSString *screenName = [TagCommanderExample buildPageNameWithChapter: @"Map"
                                                              subChapter: @""
                                                                  screen: @""
                                                                andClick: @"move"];
    
    [TagCommanderExample sendScreenEvent: screenName
                          withRestaurant: @""
                               andRating: @""];
}

- (void) viewDidLoad
{
}

- (void) viewDidAppear: (BOOL) animated
{
    [super viewDidAppear: animated];
    //[TagCommanderExample TCLaunchTiming];

    dispatch_async(dispatch_get_main_queue(), ^{
        // Create the location manager if this object does not
        // already have one.
        if (!self->locationManager)
        {
            self->locationManager = [[CLLocationManager alloc] init];
            self->locationManager.delegate = self;

            self->locationManager.desiredAccuracy = kCLLocationAccuracyThreeKilometers;
            //    Set a movement threshold for new events.
            self->locationManager.distanceFilter = 500; // meters

            if ([self->locationManager respondsToSelector: @selector(requestWhenInUseAuthorization)])
            {
                [self->locationManager requestWhenInUseAuthorization];
            }

            [self->locationManager setPausesLocationUpdatesAutomatically: NO];
            [self->locationManager startUpdatingLocation];
        }
    });

    [self updateMapWithFilters: nil];
    
    NSString *screenName = [TagCommanderExample buildPageNameWithChapter: @"Map"
                                                              subChapter: @""
                                                                  screen: @"Home"
                                                                andClick: @""];
    
    [TagCommanderExample sendScreenEvent: screenName
                          withRestaurant: @""
                               andRating: @""];
}

- (void) viewWillAppear: (BOOL) animated
{
    CLLocationCoordinate2D zoomLocation;
    zoomLocation.latitude = 48.8708;
    zoomLocation.longitude = 2.3245;
    MKCoordinateRegion viewRegion = MKCoordinateRegionMakeWithDistance(zoomLocation, 1000, 1000);
    MKCoordinateRegion adjustedRegion = [self.mapView regionThatFits: viewRegion];
    [self.mapView setRegion: adjustedRegion animated: YES];
}

- (void) mapUpdate
{
    CLLocationCoordinate2D location = [[[self.mapView userLocation] location] coordinate];
    BOOL animated = YES;

    MKCoordinateRegion viewRegion = MKCoordinateRegionMakeWithDistance(location, 100, 100);
    MKCoordinateRegion adjustedRegion = [self.mapView regionThatFits: viewRegion];

    [self.mapView setRegion: adjustedRegion animated: animated];
}

- (NSArray *) getRestaurantsWithFilters: (NSArray *) filters
{
    TCRestaurants *nearbyRestaurants = [[TCRestaurants alloc] init];
    return [nearbyRestaurants restaurantsWithFilters: filters];
}


- (void) addRestaurant: (NSDictionary *) restaurant toMapView: (MKMapView *) theMapView
{
    NSNumber *latitude = @([(NSString *) [[restaurant[@"geometry"] objectForKey:@"location"] objectForKey:@"lat"] floatValue]);
    NSNumber *longitude = @([(NSString *) [[restaurant[@"geometry"] objectForKey:@"location"] objectForKey:@"lng"] floatValue]);
    NSString *restaurantDescription = restaurant[@"name"];
    NSString *address = restaurant[@"vicinity"];

    CLLocationCoordinate2D coordinate;
    coordinate.latitude = latitude.doubleValue;
    coordinate.longitude = longitude.doubleValue;
    TCLocationModel *annotation = [[TCLocationModel alloc] initWithName: restaurantDescription address: address coordinate: coordinate];
    annotation.rating = [restaurant[@"rating"] intValue];
    annotation.waitingTime = arc4random() % 20;
    [theMapView addAnnotation: annotation];
}

// Add new method above refreshTapped
- (void) plotRestaurantsPositions: (NSArray *) newRestaurants
{

    for (id <MKAnnotation> annotation in self.mapView.annotations)
    {
        [self.mapView removeAnnotation: annotation];
    }

    for (NSDictionary *restaurant in newRestaurants)
    {
        [self addRestaurant: restaurant toMapView: self.mapView];
    }

}

- (MKAnnotationView *) mapView: (MKMapView *) mapView viewForAnnotation: (id <MKAnnotation>) annotation
{
    static NSString *identifier = @"TCLocationModel";

    if ([annotation isKindOfClass: [TCLocationModel class]])
    {
        MKPinAnnotationView *annotationView = (MKPinAnnotationView *) [self.mapView dequeueReusableAnnotationViewWithIdentifier: identifier];
        if (annotationView == nil)
        {
            annotationView = [[MKPinAnnotationView alloc] initWithAnnotation: annotation reuseIdentifier: identifier];
            //   annotationView.leftCalloutAccessoryView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)];

            UIButton *button = [UIButton buttonWithType: UIButtonTypeDetailDisclosure];
            button.frame = CGRectMake(0, 0, 24, 24);
            button.tag = 12;

            [button addTarget: self action: @selector(callOutPressed:) forControlEvents: UIControlEventTouchUpInside];
            annotationView.rightCalloutAccessoryView = button;
        }
        else
        {
            annotationView.annotation = annotation;
        }

        self.activeAnnotation = annotation;
        annotationView.enabled = YES;
        annotationView.canShowCallout = YES;
        annotationView.image = [UIImage imageNamed: @"push-pin.png"];

        return annotationView;
    }

    return nil;
}

- (void) callOutPressed: (id) sender
{
    [self performSegueWithIdentifier: @"showDetail" sender: self];
}

- (void) prepareForSegue: (UIStoryboardSegue *) segue sender: (NSIndexPath *) sender
{
    if ([[segue identifier] isEqualToString: @"showDetail"])
    {
        NSMutableDictionary *restaurant = [[NSMutableDictionary alloc] init];
        restaurant[@"name"] = [self.activeAnnotation title];
        restaurant[@"type"] = @"Health";
        restaurant[@"rating"] = @4;
        restaurant[@"waitingtime"] = @15;

        ((TCRestaurantDetailViewController *) [segue destinationViewController]).detailItem = restaurant;
    }
}

- (void) viewDidUnload
{
    [self setRefreshButton: nil];
    [super viewDidUnload];
}
@end
