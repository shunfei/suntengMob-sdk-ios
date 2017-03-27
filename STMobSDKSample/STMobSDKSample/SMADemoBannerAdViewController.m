//
//  SMADemoBannerAdViewController.m
//  STMobSDKSample
//
//  Created by samingzhong on 16/6/16.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import "SMADemoBannerAdViewController.h"
#import "SMABannerView.h"

@interface SMADemoBannerAdViewController () <SMABannerViewDelegate>

@property (weak, nonatomic) IBOutlet UIView *adViewContainer;
@property (nonatomic, strong) SMABannerView *bannerAdView;

@end

@implementation SMADemoBannerAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.bannerAdView = [[SMABannerView alloc] initWithAdUnitID:@"2-36-35"
                                                          frame:self.adViewContainer.bounds];
    
    self.bannerAdView.delegate = self;
    [self.adViewContainer addSubview:self.bannerAdView];
    [self.bannerAdView loadAd];
}

#pragma mark - SMABannerViewDelegate

// 当横幅广告被成功加载后，回调该方法
- (void)bannerViewDidLoadAd:(SMABannerView *)bannerView {
    NSLog(@"%s", __func__);
}

// 当横幅广告加载失败后，回调该方法
- (void)bannerView:(SMABannerView *)bannerView didFailToLoadAdWithError:(NSError *)error {
    NSLog(@"%s", __func__);
}

// 当用户点击广告，回调该方法
- (void)bannerViewDidTap:(SMABannerView *)bannerView {
    NSLog(@"%s", __func__);
}

// 当横幅广告被关闭后，回调该方法
- (void)bannerViewDidDismiss:(SMABannerView *)bannerView {
    NSLog(@"%s", __func__);
}

@end
