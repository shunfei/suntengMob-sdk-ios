//
//  SMANativeAd.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMAConstants.h"
#import "SMANativeAdView.h"
#import "SMANativeAdImage.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SMANativeAdDelegate;

///------------------
/// @name SMANativeAd
///------------------

@interface SMANativeAd : NSObject


/**
 *  Create and return a `SMANativeAd` instance.
 *
 *  @param adUnitID The ad unit ID.
 *  @return A `SMANativeAd` instance.
 */
- (nullable instancetype)initWithAdUnitID:(NSString *)adUnitID;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `-initWithAdUnitID:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `-initWithAdUnitID:` method")));

/**
 *  The ad unit ID.
 */
@property (nonatomic, strong, readonly) NSString *adUnitID;

/**
 *  The `SMANativeAd` delegate.
 */
@property (nullable, nonatomic, weak) id<SMANativeAdDelegate> delegate;


/**
 Disable automatically download native ad images.
 */
- (void)disableImageLoading;


/**
 Register native ad view.

 @param nativeAdView The native ad view.
 @param viewController Ad present from this controller.
 */
- (void)registerNativeAdView:(SMANativeAdView *)nativeAdView withViewController:(UIViewController *)viewController;

/**
 *  Load ad.
 */
- (void)loadAd;

/**
 *  Check is ad loaded and ready to show.
 */
- (BOOL)isValid;

@property (nullable, nonatomic, strong, readonly) SMANativeAdImage *logo;
@property (nullable, nonatomic, strong, readonly) NSString *title;
@property (nullable, nonatomic, strong, readonly) NSString *detail;
@property (nullable, nonatomic, strong, readonly) SMANativeAdImage *icon;
@property (nullable, nonatomic, strong, readonly) NSString *action;
@property (nullable, nonatomic, strong, readonly) NSArray<SMANativeAdImage *> *images;

@end

///--------------------------
/// @name SMANativeAdDelegate
///--------------------------

@protocol SMANativeAdDelegate <NSObject>

@optional


/**
 The native ad loaded.

 @param nativeAd The `SMANativeAd` instance.
 */
- (void)nativeAdDidLoad:(SMANativeAd *)nativeAd;


/**
 The native ad load failed.

 @param nativeAd The `SMANativeAd` instance.
 @param error Error show why native ad load failed.
 */
- (void)nativeAd:(SMANativeAd *)nativeAd didLoadFailWithError:(NSError *)error;


/**
 The native ad presented.

 @param nativeAd The `SMANativeAd` instance.
 */
- (void)nativeAdDidPresent:(SMANativeAd *)nativeAd;


/**
 The native ad tapped.

 @param nativeAd The `SMANativeAd` instance.
 */
- (void)nativeAdDidTap:(SMANativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
