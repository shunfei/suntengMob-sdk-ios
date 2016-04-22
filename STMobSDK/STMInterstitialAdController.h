//
//  STMInterstitialAdController.h
//  SuntengMobileAdsSDK
//
//  Created by Joe.
//  Copyright © 2016年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol STMInterstitialAdControllerDelegate;

@interface STMInterstitialAdController : UIViewController

/**
 *  Create and return a `STMInterstitialAdController` instance
 *
 *  @param adUnitID The ad unit ID
 *
 *  @return A `STMInterstitialAdController` instance
 */
+ (instancetype)interstitialAdControllerWithPublishedId:(NSString *)publishedId
                                                  appId:(NSString *)appId
                                            placementId:(NSString *)placementId;

/**
 *  The ad unit ID
 */
@property (nonatomic, copy, readonly) NSString *adUnitID;

/**
 *  `STMInterstitialAdController` delegate
 */
@property (nonatomic, weak) id<STMInterstitialAdControllerDelegate> delegate;

/**
 *  Load ad
 */
- (void)loadAd;

/**
 *  check is ad loaded and ready to show
 */
@property (nonatomic, assign, readonly, getter=isLoaded) BOOL loaded;

/**
 *  Present ad from the given controller
 *
 *  @param controller Ad present from this controller
 */
- (void)presentFromViewController:(UIViewController *)controller;

@end

///------------------------------------------
/// @name STMInterstitialAdControllerDelegate
///------------------------------------------

@protocol STMInterstitialAdControllerDelegate <NSObject>

@optional

- (void)interstitialDidLoad:(STMInterstitialAdController *)interstitial;

- (void)interstitialDidLoadFail:(STMInterstitialAdController *)interstitial;

- (void)interstitialDidPresent:(STMInterstitialAdController *)interstitial;

- (void)interstitialDidTap:(STMInterstitialAdController *)interstitial;

- (void)interstitialDidDismiss:(STMInterstitialAdController *)interstitial;

@end
