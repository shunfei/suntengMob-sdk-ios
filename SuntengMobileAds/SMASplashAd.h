//
//  SMASplashAd.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "SMAConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SMASplashAdDelegate;

///------------------
/// @name SMASplashAd
///------------------

@interface SMASplashAd : NSObject

/**
 *  Create and return a `SMASplashAd` instance.
 *
 *  @param adUnitID The ad unit ID.
 *
 *  @return A `SMASplashAd` instance.
 */
+ (nullable instancetype)splashAdWithAdUnitID:(NSString *)adUnitID;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ initWithPublisherID:appID:placementID:appKey:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ initWithPublisherID:appID:placementID:appKey:` method")));

/**
 *  The ad unit ID.
 */
@property (nonatomic, copy, readonly) NSString *adUnitID;

/**
 *  The `SMASplashAd` delegate.
 */
@property (nullable, nonatomic, weak) id<SMASplashAdDelegate> delegate;

/**
 *  Check is ad loaded and ready to show.
 */
@property (nonatomic, assign, readonly, getter=isLoaded) BOOL loaded;

/**
 *  Present ad in the window.
 *
 *  @param window          Ad present in this window.
 *  @param backgroundColor Set a launch image for background color.
 */
- (void)presentInWindow:(UIWindow *)window backgroundColor:(nullable UIColor *)backgroundColor;

/**
 *  Set realtime splash timeout interval, default is 2.0s.
 *
 *  @param interval Timeout interval.
 */
- (void)setRealtimeSplashTimeoutInterval:(CGFloat)interval;

@end

///--------------------------
/// @name SMASplashAdDelegate
///--------------------------

@protocol SMASplashAdDelegate <NSObject>

@optional

/**
 *  The splash ad presented.
 *
 *  @param splash The `SMASplashAd` instance.
 */
- (void)splashDidPresent:(SMASplashAd *)splash;

/**
 *  The splash ad fail to present.
 *
 *  @param splash The `SMASplashAd` instance.
 */
- (void)splash:(SMASplashAd *)splash failPresentWithError:(NSError *)error;

/**
 *  The splash ad tapped.
 *
 *  @param splash The `SMASplashAd` instance.
 */
- (void)splashDidTap:(SMASplashAd *)splash;

/**
 *  The splash ad closed.
 *
 *  @param splash The `SMASplashAd` instance.
 */
- (void)splashDidDismiss:(SMASplashAd *)splash;

@end

NS_ASSUME_NONNULL_END
