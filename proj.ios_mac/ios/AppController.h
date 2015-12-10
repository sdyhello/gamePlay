#import <UIKit/UIKit.h>
#import "/Users/taowu/study/gamePlay/proj.ios_mac/GoogleMobileAds.framework/Versions/A/Headers/GoogleMobileAds.h"
@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate, GADBannerViewDelegate>
{
    UIWindow *window;
    RootViewController    *viewController;
}

@property(nonatomic, strong) GADBannerView *adBanner;

@property(nonatomic, readonly) RootViewController* viewController;

@end

