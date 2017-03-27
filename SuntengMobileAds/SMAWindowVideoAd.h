//
//  SMAWindowVideoAd.h
//  SuntengMobileAds
//
//  Created by Joe on 17/3/8.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@protocol SMAWindowVideoAdDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface SMAWindowVideoAd : NSObject

- (instancetype)initWithAdUnitID:(NSString *)adUnitID NS_DESIGNATED_INITIALIZER;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `- initWithAdUnitID:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `- initWithAdUnitID:` method")));

@property (nonatomic, copy, readonly) NSString *adUnitID;

- (void)loadAd;

@property (nonatomic, assign, readonly, getter=isReady) BOOL ready;

@property (nullable, nonatomic, weak) id<SMAWindowVideoAdDelegate> delegate;

- (void)disposeInView:(UIView *)view presentFromViewController:(UIViewController *)viewController;

- (void)playVideo;

- (void)pauseVideo;

@end

@protocol SMAWindowVideoAdDelegate <NSObject>
@optional

- (void)windowVideoAdDidLoad:(SMAWindowVideoAd *)windowVideoAd;

- (void)windowVideoAd:(SMAWindowVideoAd *)windowVideoAd didFailToLoadWithError:(NSError *)error;

- (void)windowVideoAdDidTap:(SMAWindowVideoAd *)windowVideoAd;

- (void)windowVideoAdDidPlayFinished:(SMAWindowVideoAd *)windowVideoAd;

@end

NS_ASSUME_NONNULL_END
