//
//  AppDelegate.m
//  STMobSDKSample
//
//  Created by East on 16/4/22.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import "AppDelegate.h"
#import "SuntengMobileAdsSDK.h"

@interface AppDelegate () <STMSplashAdDelegate>

@property (nonatomic, strong) STMSplashAd *splashAd;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    application.statusBarHidden = YES;
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    UIViewController *vc = [storyboard instantiateInitialViewController];
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    
    // splash SDK
    self.splashAd = [STMSplashAd splashAdWithPublisherID:PUBLISHERID
                                                   appID:APPID
                                             placementID:@"34"
                                                  appKey:APPKEY];
    self.splashAd.delegate = self;
    
    // 设置一个跟启动屏幕一致的图片作为背景图
    NSString *launchImageName;
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) {
        if ([UIScreen mainScreen].bounds.size.height == 480.0f) {
            launchImageName = @"LaunchImage";
        } else if ([UIScreen mainScreen].bounds.size.height == 568.0f) {
            launchImageName = @"LaunchImage4@2x";
        } else if ([UIScreen mainScreen].bounds.size.height == 667.0f) {
            launchImageName = @"LaunchImage4.7@2x";
        } else if ([UIScreen mainScreen].bounds.size.height == 736.0) {
            launchImageName = @"LaunchImage5.5@3x";
        }
    } else if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        if ([UIScreen mainScreen].bounds.size.height == 768.0f) {
            launchImageName = @"LaunchImage_Landscape";
        } else if ([UIScreen mainScreen].bounds.size.height == 1024.0f) {
            launchImageName = @"LaunchImage_Portrait";
        }
    }
    UIColor *backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:launchImageName]];
    [self.splashAd presentInWindow:self.window backgroundColor:backgroundColor];
    
    return YES;
}

#pragma mark - STMSplashAdDelegate

// 当开屏广告被成功展示后，回调该方法
- (void)splashDidPresent:(STMSplashAd *)splash {
    NSLog(@"%s", __func__);
}

// 当开屏广告展示失败后，回调该方法
- (void)splashlFailPresent:(STMSplashAd *)splash {
    NSLog(@"%s", __func__);
}

// 当用户点击广告，回调该方法
- (void)splashDidTap:(STMSplashAd *)splash {
    NSLog(@"%s", __func__);
}

// 当开屏广告被关闭后，回调该方法
- (void)splashDidDismiss:(STMSplashAd *)splash {
    NSLog(@"%s", __func__);
    [UIApplication sharedApplication].statusBarHidden = NO;
}

@end
