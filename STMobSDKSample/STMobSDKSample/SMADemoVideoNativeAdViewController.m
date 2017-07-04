//
//  SMADemoVideoNativeAdViewController.m
//  STMobSDKSample
//
//  Created by Joe on 2017/7/4.
//  Copyright © 2017年 sunteng. All rights reserved.
//

#import "SMADemoVideoNativeAdViewController.h"

#import "SuntengMobileAds.h"
#import "SMAVideoNativeAdTableViewCell.h"

@interface SMADemoVideoNativeAdViewController () <SMAVideoNativeAdDelegate>

@property (nonatomic, strong) SMAVideoNativeAd *videoNativeAd;
@property (nonatomic, assign) BOOL isLoaded;

@end

@implementation SMADemoVideoNativeAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // 注册列表 Cell
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"UITableViewCell"];
    [self.tableView registerClass:[SMAVideoNativeAdTableViewCell class] forCellReuseIdentifier:@"SMAVideoNativeAdTableViewCell"];
    
    // 创建视频信息流广告
    self.videoNativeAd = [[SMAVideoNativeAd alloc] initWithAdUnitID:@"2-36-184"];
    self.videoNativeAd.autoplayEnabled = YES;
    self.videoNativeAd.delegate = self;
    
    // 请求视频信息流广告
    [self.videoNativeAd loadAd];
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if (self.isLoaded) {
        return 21;
    }
    
    return 20;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (self.isLoaded && indexPath.row == 3) {
        SMAVideoNativeAdTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"SMAVideoNativeAdTableViewCell" forIndexPath:indexPath];
        
        [self.videoNativeAd unregisterView];
        cell.titleLabel.text = [NSString stringWithFormat:@"%@", self.videoNativeAd.title];
        [self.videoNativeAd setMediaView:cell.mediaView];
        [self.videoNativeAd registerAdView:cell withViewController:self];
        
        return cell;
    }
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"UITableViewCell" forIndexPath:indexPath];
    cell.textLabel.text = [NSString stringWithFormat:@"我是标题 %ld", (long)indexPath.row + 1];
    return cell;
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (self.isLoaded && indexPath.row == 3) {
        return 270;
    }
    
    return 44;
}

#pragma mark - SMAVideoNativeAdDelegate

- (void)videoNativeAdDidLoad:(SMAVideoNativeAd *)nativeAd {
    NSLog(@"视频信息流广告获取成功。");
    
    self.isLoaded = YES;
    
    // 动画插入广告 Cell
    [self.tableView beginUpdates];
    [self.tableView insertRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:3 inSection:0]] withRowAnimation:UITableViewRowAnimationRight];
    [self.tableView endUpdates];
}

- (void)videoNativeAd:(SMAVideoNativeAd *)nativeAd didLoadFailWithError:(NSError *)error {
    NSLog(@"视频信息流广告加载失败，错误日志：\n%@", error.localizedDescription);
}

- (void)videoNativeAdDidImpression:(SMAVideoNativeAd *)nativeAd {
    NSLog(@"视频信息流广告曝光。");
}

- (void)videoNativeAdDidTap:(SMAVideoNativeAd *)nativeAd {
    NSLog(@"视频信息流广告被点击。");
}

@end
