//
//  SMAInterstitialAdController.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SMAConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SMAInterstitialAdControllerDelegate;

///----------------------------------
/// @name SMAInterstitialAdController
///----------------------------------

@interface SMAInterstitialAdController : UIViewController

/**
 *  Create and return a `SMAInterstitialAdController` instance.
 *
 *  @param adUnitID    The ad unit ID.
 *
 *  @return A `SMAInterstitialAdController` instance.
 */
+ (nullable instancetype)interstitialAdControllerWithAdUnitID:(NSString *)adUnitID;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ interstitialAdControllerWithPublisherID:appID:placementID:appKey:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ interstitialAdControllerWithPublisherID:appID:placementID:appKey:` method")));

/**
 *  The ad unit ID.
 */
@property (nonatomic, copy, readonly) NSString *adUnitID;

/**
 *  The `SMAInterstitialAdController` delegate.
 */
@property (nullable, nonatomic, weak) id<SMAInterstitialAdControllerDelegate> delegate;

/**
 *  Load ad.
 */
- (void)loadAd;

/**
 *  Check is ad loaded and ready to show.
 */
@property (nonatomic, assign, readonly, getter=isLoaded) BOOL loaded;

/**
 *  Present ad from the given controller.
 *
 *  @param controller Ad present from this controller.
 */
- (void)presentFromViewController:(UIViewController *)controller;

@end

///------------------------------------------
/// @name SMAInterstitialAdControllerDelegate
///------------------------------------------

@protocol SMAInterstitialAdControllerDelegate <NSObject>

@optional

/**
 *  The interstitial ad loaded.
 *
 *  @param interstitial The `SMAInterstitialAdController` instance.
 */
- (void)interstitialDidLoad:(SMAInterstitialAdController *)interstitial;

/**
 *  The interstitial ad load failed.
 *
 *  @param interstitial The `SMAInterstitialAdController` instance.
 */
- (void)interstitial:(SMAInterstitialAdController *)interstitial didLoadFailWithError:(NSError *)error;

/**
 *  The interstitial ad presented.
 *
 *  @param interstitial The `SMAInterstitialAdController` instance.
 */
- (void)interstitialDidPresent:(SMAInterstitialAdController *)interstitial;

/**
 *  The interstitial ad tapped.
 *
 *  @param interstitial The `SMAInterstitialAdController` instance.
 */
- (void)interstitialDidTap:(SMAInterstitialAdController *)interstitial;

/**
 *  The interstitial ad closed.
 *
 *  @param interstitial The `SMAInterstitialAdController` instance.
 */
- (void)interstitialDidDismiss:(SMAInterstitialAdController *)interstitial;

@end

NS_ASSUME_NONNULL_END
