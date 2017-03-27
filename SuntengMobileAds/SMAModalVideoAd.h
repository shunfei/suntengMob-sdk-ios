//
//  SMAModalVideoAd.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@protocol SMAModalVideoAdDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface SMAModalVideoAd : NSObject

- (instancetype)initWithAdUnitID:(NSString *)adUnitID NS_DESIGNATED_INITIALIZER;

@property (nonatomic, copy, readonly) NSString *adUnitID;

@property (nullable, nonatomic, weak) id<SMAModalVideoAdDelegate> delegate;

- (void)loadAd;

@property (nonatomic, assign, readonly, getter=isReady) BOOL ready;

- (void)presentFromViewController:(UIViewController *)viewController;

- (void)showCloseVideoButton:(BOOL)yesOrNo;

- (void)customizeAlertViewContents:(NSString *)contents;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `+ sharedInstance` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `+ sharedInstance` method")));

@end

@protocol SMAModalVideoAdDelegate <NSObject>
@optional

- (void)modalVideoAdDidLoad:(SMAModalVideoAd *)modalVideoAd;

- (void)modalVideoAd:(SMAModalVideoAd *)modalVideoAd didFailToLoadWithError:(NSError *)error;

- (void)modalVideoAd:(SMAModalVideoAd *)modalVideoAd didFailToPlayWithError:(NSError *)error;

- (void)modalVideoAdDidTap:(SMAModalVideoAd *)modalVideoAd;

- (void)modalVideoAdDidPlayFinished:(SMAModalVideoAd *)modalVideoAd;

- (void)modalVideoAdDidClose:(SMAModalVideoAd *)modalVideoAd;

@end

NS_ASSUME_NONNULL_END
