//
//  STMBannerAdViewController.m
//  STMobSDKSample
//
//  Created by samingzhong on 16/6/16.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import "STMBannerAdViewController.h"
#import "STMBannerView.h"

@interface STMBannerAdViewController () <STMBannerViewDelegate>

@property (weak, nonatomic) IBOutlet UIView *adViewContainer;
@property (nonatomic, strong) STMBannerView *bannerAdView;

@end

@implementation STMBannerAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.bannerAdView = [[STMBannerView alloc] initWithPublisherID:PUBLISHERID
                                                             appID:APPID
                                                       placementID:@"35"
                                                            appKey:APPKEY
                                                             frame:self.adViewContainer.bounds];
    
    self.bannerAdView.delegate = self;
    [self.adViewContainer addSubview:self.bannerAdView];
    [self.bannerAdView loadAd];
}

#pragma mark - STMBannerViewDelegate

// 当横幅广告被成功加载后，回调该方法
- (void)bannerViewDidLoadAd:(STMBannerView *)bannerView {
    NSLog(@"%s", __func__);
}

// 当横幅广告加载失败后，回调该方法
- (void)bannerView:(STMBannerView *)bannerView didFailToLoadAdWithError:(NSError *)error {
    NSLog(@"%s", __func__);
}

// 当用户点击广告，回调该方法
- (void)bannerViewDidTap:(STMBannerView *)bannerView {
    NSLog(@"%s", __func__);
}

// 当横幅广告被关闭后，回调该方法
- (void)bannerViewDidDismiss:(STMBannerView *)bannerView {
    NSLog(@"%s", __func__);
}

@end
