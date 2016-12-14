#import <UIKit/UIKit.h>

@class TagCommander;

@interface TCAppDelegate : UIResponder <UIApplicationDelegate>
{
@public
    TagCommander *tc;
}

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) TagCommander *tc;

@end
