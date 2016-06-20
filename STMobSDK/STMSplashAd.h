//
//  STMSplashAd.h
//  SuntengMobileAdsSDK
//
//  Created by Joe.
//  Copyright © 2016年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol STMSplashAdDelegate;

///------------------
/// @name STMSplashAd
///------------------

@interface STMSplashAd : NSObject

/**
 *  Create and return a `STMSplashAd` instance.
 *
 *  @param publishedId The published id.
 *  @param appId       The app id.
 *  @param placementId The placement id.
 *
 *  @return A `STMSplashAd` instance.
 */
+ (nullable instancetype)splashAdWithPublishedId:(NSString *)publishedId
                                           appId:(NSString *)appId
                                     placementId:(NSString *)placementId;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ initWithPublishedId:appId:placementId:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ initWithPublishedId:appId:placementId:` method")));

/**
 *  The placement Id
 */
@property (nonatomic, copy, readonly) NSString *adUnitID;

/**
 *  The `STMSplashAd` delegate.
 */
@property (nullable, nonatomic, weak) id<STMSplashAdDelegate> delegate;

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
/// @name STMSplashAdDelegate
///--------------------------

@protocol STMSplashAdDelegate <NSObject>

@optional

/**
 *  The splash ad presented.
 *
 *  @param splash The `STMSplashAd` instance.
 */
- (void)splashDidPresent:(STMSplashAd *)splash;

/**
 *  The splash ad fail to present.
 *
 *  @param splash The `STMSplashAd` instance.
 */
- (void)splashlFailPresent:(STMSplashAd *)splash;

/**
 *  The splash ad tapped.
 *
 *  @param splash The `STMSplashAd` instance.
 */
- (void)splashDidTap:(STMSplashAd *)splash;

/**
 *  The splash ad closed.
 *
 *  @param splash The `STMSplashAd` instance.
 */
- (void)splashDidDismiss:(STMSplashAd *)splash;

@end

NS_ASSUME_NONNULL_END