//
//  STMInterstitialAdController.h
//  SuntengMobileAdsSDK
//
//  Created by Joe.
//  Copyright © 2016年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol STMInterstitialAdControllerDelegate;

///----------------------------------
/// @name STMInterstitialAdController
///----------------------------------

@interface STMInterstitialAdController : UIViewController

/**
 *  Create and return a `STMInterstitialAdController` instance.
 *
 *  @param publishedId The published id.
 *  @param appId       The app id.
 *  @param placementId The placement id.
 *
 *  @return A `STMInterstitialAdController` instance.
 */
+ (nullable instancetype)interstitialAdControllerWithPublishedId:(NSString *)publishedId
                                                           appId:(NSString *)appId
                                                     placementId:(NSString *)placementId;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ interstitialAdControllerWithPublishedId:appId:placementId:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ interstitialAdControllerWithPublishedId:appId:placementId:` method")));

/**
 *  The placement Id.
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
- (void)interstitialDidLoadFail:(STMInterstitialAdController *)interstitial;

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
