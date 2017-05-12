//
//  SMAPreMovieAd.h
//  SuntengMobileAds
//
//  Created by samingzhong on 2017/3/29.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SMASupportedNetworkOptions) {
    SMASupportedNetworkOptionNone           = 0,
    SMASupportedNetworkOptionWiFi           = (1 << 0),
    SMASupportedNetworkOption2G             = (1 << 1),
    SMASupportedNetworkOption3G             = (1 << 2),
    SMASupportedNetworkOption4G             = (1 << 3),
    SMASupportedNetworkOptionAll            = (SMASupportedNetworkOptionWiFi | SMASupportedNetworkOption2G | SMASupportedNetworkOption3G |SMASupportedNetworkOption4G),// Default value
    SMASupportedNetworkOptionCellular = (SMASupportedNetworkOption2G | SMASupportedNetworkOption3G |SMASupportedNetworkOption4G)
};

@protocol SMAPreMovieAdDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface SMAPreMovieAd : NSObject

- (instancetype)initWithAdUnitID:(NSString *)adUnitID NS_DESIGNATED_INITIALIZER;

- (instancetype)init __attribute__((unavailable("can not use `- init` method, please use `- initWithAdUnitID:` method")));
+ (instancetype)new __attribute__((unavailable("can not use `+ new` method, please use `- initWithAdUnitID:` method")));

@property (nonatomic, copy, readonly) NSString *adUnitID;

@property (nonatomic, assign, readonly, getter=isReady) BOOL ready;

@property (nullable, nonatomic, weak) id <SMAPreMovieAdDelegate> delegate;

// 设置计时器/查看详情按钮的可见与否。
@property(nonatomic, assign, getter=isTimeCounterHidden) BOOL timeCounterHidden;

@property(nonatomic, assign, getter=isCheckDetailButtonHidden) BOOL checkDetailButtonHidden;

// 设置允许加载广告的网络环境
@property (nonatomic, assign) SMASupportedNetworkOptions supportedNetwork;

- (void)loadAd;

// 部署贴片广告到指定视图容器上
- (void)disposeInView:(UIView *)view presentFromViewController:(UIViewController *)viewController;

- (void)setMuteEnable:(BOOL)muteEnable;

@end

@protocol SMAPreMovieAdDelegate <NSObject>
@optional

- (void)preMovieAdDidLoad:(SMAPreMovieAd *)preMovieAd;

- (void)preMovieAd:(SMAPreMovieAd *)preMovieAd didFailToLoadWithError:(NSError *)error;

- (void)preMovieAdDidTap:(SMAPreMovieAd *)preMovieAd;

- (void)preMovieAdDidPlayFinished:(SMAPreMovieAd *)preMovieAd;

// 贴片广告播放进度的delegate methods
- (void)updatePreMovieAdPlayCurrentTime:(NSTimeInterval)time duration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
