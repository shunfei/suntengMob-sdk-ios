//
//  SMADemoWindowVideoViewController.m
//  STMobSDKSample
//
//  Created by samingzhong on 2017/3/23.
//  Copyright © 2017年 sunteng. All rights reserved.
//

#import "SMADemoWindowVideoViewController.h"
#import "SMAWindowVideoAd.h"

@interface SMADemoWindowVideoViewController () <SMAWindowVideoAdDelegate>
@property (nonatomic, strong) SMAWindowVideoAd *windowVideoAd;
@property (nonatomic, strong) UIView *AdContainerView;
@end

@implementation SMADemoWindowVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.windowVideoAd = [[SMAWindowVideoAd alloc] initWithAdUnitID:@"2-36-40"];
    self.windowVideoAd.delegate = self;
    
    self.AdContainerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 150)];

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - IBAction
- (IBAction)loadWindowVideoAd:(id)sender {
    [self.windowVideoAd loadAd];
}

- (IBAction)disposeWindowVideoAd:(id)sender {
    if (!self.AdContainerView.superview) {
        [self.view addSubview:self.AdContainerView];
        self.AdContainerView.center = self.view.center;
    }
    
    if (self.windowVideoAd.isReady) {
        [self.windowVideoAd disposeInView:self.AdContainerView presentFromViewController:self];
        NSLog(@"%s, 窗口视频广告已被成功部署.", __FUNCTION__);
        return;
    }
    
    NSLog(@"%s, 视频资源尚未准备好或已被消耗.", __FUNCTION__);
    
}

- (IBAction)playVideo:(id)sender {
    [self.windowVideoAd playVideo];
}

- (IBAction)pauseVideo:(id)sender {
    [self.windowVideoAd pauseVideo];
}

#pragma mark - SMAWindowVideoAdDelegate
- (void)windowVideoAdDidLoad:(SMAWindowVideoAd *)windowVideoAd {
    NSLog(@"%s", __FUNCTION__);
}

- (void)windowVideoAd:(SMAWindowVideoAd *)windowVideoAd didFailToLoadWithError:(NSError *)error {
    NSLog(@"%s, error:%@", __FUNCTION__, error);
}

- (void)windowVideoAdDidTap:(SMAWindowVideoAd *)windowVideoAd {
   NSLog(@"%s", __FUNCTION__);
}

- (void)windowVideoAdDidPlayFinished:(SMAWindowVideoAd *)windowVideoAd {
    NSLog(@"%s", __FUNCTION__);
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
