//
//  SuntengMobileAds.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SMAConstants.h"
#import "SMABannerView.h"
#import "SMAInterstitialAdController.h"
#import "SMASplashAd.h"
#import "SMAModalVideoAd.h"
#import "SMAWindowVideoAd.h"
#import "SMANativeAd.h"
#import "SMAPreMovieAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface SuntengMobileAds : NSObject

+ (instancetype)sharedSDK;

- (void)registerWithAppSecret:(NSString *)appSecret;

- (NSString *)version;

- (void)disableLocationService;

- (void)enableLoger;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ sharedSDK` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ sharedSDK` method")));

@end

NS_ASSUME_NONNULL_END
