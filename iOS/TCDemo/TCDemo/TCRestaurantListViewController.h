#import <UIKit/UIKit.h>
#import "TCRestaurants.h"

@class TCRestaurantListViewController;

@interface TCRestaurantListViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate>

- (IBAction)updateJob:(id)sender;

@property (retain, nonatomic) IBOutlet UITableView *tableView;
@property (retain, nonatomic) NSMutableArray *restaurantsData;

@end
