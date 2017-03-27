//
//  SMADemoNativeAdViewController.m
//  STMobSDKSample
//
//  Created by samingzhong on 2016/11/23.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import "SMADemoNativeAdViewController.h"
#import "SuntengMobileAds.h"
#import "CustomNativeAdView.h"

@interface SMADemoNativeAdViewController () <SMANativeAdDelegate>
@property (nonatomic, strong) SMANativeAd *nativeAd;
@property (nonatomic, strong) CustomNativeAdView *myCustomeNativeAdView;
@end

@implementation SMADemoNativeAdViewController

#pragma mark - IBAction

- (IBAction)loadNativeAdButtonPressed:(UIButton *)button {
    // 初始化一个原生广告对象
    self.nativeAd = [[SMANativeAd alloc] initWithAdUnitID:@"2-36-53"];
    self.nativeAd.delegate = self;
    [self.nativeAd loadAd];
}

#pragma mark - SMANativeAdDelegate

// 当原生广告曝光后，回调此方法。
- (void)nativeAdDidPresent:(SMANativeAd *)nativeAd {
    NSLog(@"%s", __FUNCTION__);
}

// 原生广告成功加载到广告数据后，回调此方法。
- (void)nativeAdDidLoad:(SMANativeAd *)nativeAd {
    NSLog(@"%s", __FUNCTION__);
    // 移除当前广告视图
    [self.myCustomeNativeAdView removeFromSuperview];
    
    // 创建自定义广告视图
    self.myCustomeNativeAdView = [[NSBundle mainBundle] loadNibNamed:@"CustomNativeAdView" owner:nil options:nil][0];

    
    // 将nativeAd与SMANativeAdView绑定，广告才能正确曝光、被统计。
    [nativeAd registerNativeAdView:self.myCustomeNativeAdView.adContainerView withViewController:self];
    
    // 设置自定义的广告视图内容
    self.myCustomeNativeAdView.nativeAdIconImageView.image = nativeAd.icon.image;
    self.myCustomeNativeAdView.nativeAdTitleLabel.text = nativeAd.title;
    self.myCustomeNativeAdView.nativeAdDetailLabel.text = nativeAd.detail;
    [nativeAd.images enumerateObjectsUsingBlock:^(SMANativeAdImage * _Nonnull image, NSUInteger idx, BOOL * _Nonnull stop) {
        switch (idx) {
            case 0:
                self.myCustomeNativeAdView.nativeAdImageView1.image = ((SMANativeAdImage *)nativeAd.images[idx]).image;
                break;
                
            case 1:
                self.myCustomeNativeAdView.nativeAdImageView2.image = ((SMANativeAdImage *)nativeAd.images[idx]).image;
                break;
                
            case 2:
                self.myCustomeNativeAdView.nativeAdImageView3.image = ((SMANativeAdImage *)nativeAd.images[idx]).image;
                break;
                
            default:
                break;
        }
    }];
    self.myCustomeNativeAdView.nativeAdProviderImageView.image = nativeAd.logo.image;
    
    // 设置好自定义广告视图尺寸位置，并添加到容器视图上
    self.myCustomeNativeAdView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width -20, 170);
    self.myCustomeNativeAdView.center = self.view.center;
    [self.view addSubview:self.myCustomeNativeAdView];

}

// 原生广告加载广告数据失败后，回调此方法。
- (void)nativeAd:(SMANativeAd *)nativeAd didLoadFailWithError:(NSError *)error {
    NSLog(@"%s", __FUNCTION__);
}

// 原生广告被点击，回调此方法。
- (void)nativeAdDidTap:(SMANativeAd *)nativeAd {
    NSLog(@"%s", __FUNCTION__);
}

@end
