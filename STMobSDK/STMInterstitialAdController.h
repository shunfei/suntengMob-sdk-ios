//
//  STMInterstitialAdController.h
//  SuntengMobileAdsSDK
//
//  Created by Joe.
//  Copyright © 2016年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STMConstants.h"

NS_ASSUME_NONNULL_BEGIN

@protocol STMInterstitialAdControllerDelegate;

///----------------------------------
/// @name STMInterstitialAdController
///----------------------------------

@interface STMInterstitialAdController : UIViewController

/**
 *  Create and return a `STMInterstitialAdController` instance.
 *
 *  @param adUnitID    The ad unit ID.
 *
 *  @return A `STMInterstitialAdController` instance.
 */
+ (nullable instancetype)interstitialAdControllerWithAdUnitID:(NSString *)adUnitID;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ interstitialAdControllerWithPublisherID:appID:placementID:appKey:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ interstitialAdControllerWithPublisherID:appID:placementID:appKey:` method")));

/**
 *  The ad unit ID.
 */
@property (nonatomic, copy, readonly) NSString *adUnitID;

/**
 *  The `STMInterstitialAdController` delegate.
 */
@property (nullable, nonatomic, weak) id<STMInterstitialAdControllerDelegate> delegate;

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
/// @name STMInterstitialAdControllerDelegate
///------------------------------------------

@protocol STMInterstitialAdControllerDelegate <NSObject>

@optional

/**
 *  The interstitial ad loaded.
 *
 *  @param interstitial The `STMInterstitialAdController` instance.
 */
- (void)interstitialDidLoad:(STMInterstitialAdController *)interstitial;

/**
 *  The interstitial ad load failed.
 *
 *  @param interstitial The `STMInterstitialAdController` instance.
 */
- (void)interstitial:(STMInterstitialAdController *)interstitial didLoadFailWithError:(NSError *)error;

/**
 *  The interstitial ad presented.
 *
 *  @param interstitial The `STMInterstitialAdController` instance.
 */
- (void)interstitialDidPresent:(STMInterstitialAdController *)interstitial;

/**
 *  The interstitial ad tapped.
 *
 *  @param interstitial The `STMInterstitialAdController` instance.
 */
- (void)interstitialDidTap:(STMInterstitialAdController *)interstitial;

/**
 *  The interstitial ad closed.
 *
 *  @param interstitial The `STMInterstitialAdController` instance.
 */
- (void)interstitialDidDismiss:(STMInterstitialAdController *)interstitial;

@end

NS_ASSUME_NONNULL_END
