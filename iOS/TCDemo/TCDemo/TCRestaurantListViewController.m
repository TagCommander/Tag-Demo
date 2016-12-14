#import <MacTypes.h>
#import "TCRestaurantListViewController.h"
#import "TCRestaurantDetailViewController.h"

@implementation TCRestaurantListViewController

- (void) viewWillAppear: (BOOL) animated
{
    self.tableView.contentOffset = CGPointMake(0.0, 44.0);
}

- (void) viewDidLoad
{
    [super viewDidLoad];
	[self initRestaurantsData];
}

- (void) viewDidDisappear: (BOOL) animated
{
    [super viewDidDisappear: animated];
}

- (IBAction) updateJob: (id) sender;
{
    BOOL isWaiting = YES;
    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible: YES];

    while (isWaiting)
    {
        [self refreshRestaurants];
        isWaiting = NO;
    }

    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible: NO];
    [self.tableView reloadData];
}

- (void) initRestaurantsData
{
    TCRestaurants *restaurants = [[TCRestaurants alloc] init];
    self.restaurantsData = [[restaurants restaurantsWithFilters: nil] mutableCopy];
}

- (void) refreshRestaurants
{
    TCRestaurants *restaurants = [[TCRestaurants alloc] init];
    self.restaurantsData = [[restaurants restaurantsWithFilters: @[@"123"]] mutableCopy];
    [self.tableView reloadData];
}

- (NSInteger) numberOfSectionsInTableView: (UITableView *) tableView
{
    return 1;
}

- (NSInteger) tableView: (UITableView *) tableView numberOfRowsInSection: (NSInteger) section
{
    return [self.restaurantsData count];
}

- (NSString *) tableView: (UITableView *) tableView titleForHeaderInSection: (NSInteger) section
{
    return @"Restaurants nearby";
}

- (UITableViewCell *) tableView: (UITableView *) tableView cellForRowAtIndexPath: (NSIndexPath *) indexPath
{
    static NSString *MyIdentifier = @"MyReuseIdentifier";
    UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier: MyIdentifier];

    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle: UITableViewCellStyleValue1  reuseIdentifier: MyIdentifier];
        cell.backgroundColor = [UIColor clearColor];
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }

    NSDictionary *restaurant = (self.restaurantsData)[(unsigned int) indexPath.row];
    cell.textLabel.text = restaurant[@"name"];
    cell.detailTextLabel.text = restaurant[@"type"];
    return cell;
}

- (BOOL) tableView: (UITableView *) tableView canEditRowAtIndexPath: (NSIndexPath *) indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}

- (void) tableView: (UITableView *) tableView didSelectRowAtIndexPath: (NSIndexPath *) indexPath
{
    [self performSegueWithIdentifier: @"showDetail" sender: indexPath];
}

- (void) prepareForSegue: (UIStoryboardSegue *) segue sender: (NSIndexPath *) sender
{
    if ([[segue identifier] isEqualToString:@"showDetail"])
    {
        NSMutableDictionary *restaurant = (self.restaurantsData)[(unsigned int) sender.row];
        [(TCRestaurantDetailViewController *)  [segue destinationViewController] setDetailItem:restaurant];
    }
}

@end
