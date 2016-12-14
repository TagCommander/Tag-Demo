#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>
#import "TCRestaurants.h"

@interface TCMapViewController : UIViewController <MKMapViewDelegate, CLLocationManagerDelegate>

@property (assign, nonatomic) IBOutlet MKMapView *mapView;
@property (retain, nonatomic) IBOutlet NSArray *restaurants;
@property (strong, nonatomic) id<MKAnnotation> activeAnnotation;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *refreshButton;
@property (retain, nonatomic) CLLocationManager *locationManager;

@end
