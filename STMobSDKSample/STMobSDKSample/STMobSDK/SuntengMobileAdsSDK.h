//
//  SuntengMobileAdsSDK.h
//  SuntengMobileAdsSDK
//
//  Created by Joe.
//  Copyright © 2016年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STMInterstitialAdController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Sunteng mobile ad SDK version.
 */
extern NSString * const STMAdsSDKVersion;

@interface SuntengMobileAdsSDK : NSObject

/**
 *  The sunteng mobile ads SDK singleton object.
 *
 *  @return The sunteng mobile ads SDK singleton object.
 */
+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
