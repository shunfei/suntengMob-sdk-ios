//
//  SMAVideoNativeAd.h
//  SuntengMobileAds
//
//  Created by Joe on 2017/6/19.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMANativeAdImage.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SMAVideoNativeAdDelegate;

@interface SMAVideoNativeAd : NSObject

- (nullable instancetype)initWithAdUnitID:(NSString *)adUnitID;

@property (nonatomic, strong, readonly) NSString *adUnitID;

@property (nullable, nonatomic, weak) id<SMAVideoNativeAdDelegate> delegate;

@property (nonatomic, assign, getter=isMuted) BOOL muted;

@property (nonatomic, assign, getter=isAutoplayEnabled) BOOL autoplayEnabled;

- (void)loadAd;

- (BOOL)isValid;

- (void)setMediaView:(UIView *)mediaView;

- (void)registerAdView:(UIView *)adView withViewController:(UIViewController *)viewController;

- (void)unregisterView;

@property (nullable, nonatomic, strong, readonly) SMANativeAdImage *logo;
@property (nullable, nonatomic, strong, readonly) NSString *title;
@property (nullable, nonatomic, strong, readonly) NSString *detail;
@property (nullable, nonatomic, strong, readonly) SMANativeAdImage *icon;
@property (nullable, nonatomic, strong, readonly) NSString *action;


- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `-initWithAdUnitID:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `-initWithAdUnitID:` method")));

@end


@protocol SMAVideoNativeAdDelegate <NSObject>

@optional

- (void)videoNativeAdDidLoad:(SMAVideoNativeAd *)nativeAd;

- (void)videoNativeAd:(SMAVideoNativeAd *)nativeAd didLoadFailWithError:(NSError *)error;

- (void)videoNativeAdDidImpression:(SMAVideoNativeAd *)nativeAd;

- (void)videoNativeAdDidTap:(SMAVideoNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
