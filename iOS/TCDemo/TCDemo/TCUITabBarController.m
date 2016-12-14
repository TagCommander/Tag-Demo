#import "TCUITabBarController.h"

@interface TCUITabBarController ()

@end

@implementation TCUITabBarController

- (id) initWithNibName: (NSString *) nibNameOrNil bundle: (NSBundle *) nibBundleOrNil
{
    self = [super initWithNibName: nibNameOrNil bundle: nibBundleOrNil];

    if (self)
    {
        // Custom initialization
    }

    return self;
}

- (void) viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void) viewDidAppear: (BOOL) animated
{
    [super viewDidAppear: animated];
}

- (BOOL) shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation) toInterfaceOrientation
{
    return YES;
}

- (void) tabBar: (UITabBar *) tabBar didSelectItem: (UITabBarItem *) item
{
}

@end
