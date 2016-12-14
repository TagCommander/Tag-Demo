#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "TCRestaurants.h"

@interface TCRestaurantDetailViewController : UIViewController<UIGestureRecognizerDelegate>

@property (assign, nonatomic) IBOutlet UITextField *detailTitleLabel;
@property (retain, nonatomic) IBOutlet UITextField *detailTypeLabel;
@property (retain, nonatomic) IBOutlet UISlider *detailRatingSlider;
@property (retain, nonatomic) IBOutlet UISlider *detailWaitingSlider;
@property (retain, nonatomic) IBOutlet UIButton *sendDetailButton;
@property (retain, nonatomic) IBOutlet UIButton *cancelDetailButton;
@property (retain, nonatomic) IBOutlet UIButton *locationDetailButton;
@property (retain, nonatomic) IBOutlet MKMapView *locationView;
@property (retain, nonatomic) UIView *smallPopupView;

@property (weak, nonatomic) IBOutlet UIImageView *imageView;

- (void) setDetailItem: (NSMutableDictionary *) newDetailItem;

- (IBAction) ratingSliderChanged: (UISlider *) sender;
- (IBAction) waitingSliderChanged: (UISlider *) sender;
- (IBAction) doneEditing: (id) sender;

- (void) releaseButAction: (UIGestureRecognizer *) gestureRecognizer;

@property (retain, nonatomic) NSMutableDictionary *detailItem;

@end
