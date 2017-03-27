//
//  SMADemoModalVideoViewController.m
//  STMobSDKSample
//
//  Created by samingzhong on 2017/3/23.
//  Copyright © 2017年 sunteng. All rights reserved.
//

#import "SMADemoModalVideoViewController.h"
#import "SMAModalVideoAd.h"

@interface SMADemoModalVideoViewController () <SMAModalVideoAdDelegate>
@property (nonatomic, strong) SMAModalVideoAd *modalVideoAd;
@end

@implementation SMADemoModalVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.modalVideoAd = [[SMAModalVideoAd alloc] initWithAdUnitID:@"2-36-41"];
    self.modalVideoAd.delegate = self;
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - IBAction
- (IBAction)loadModalVideoAd:(id)sender {
    [self.modalVideoAd loadAd];
}
- (IBAction)showAd:(id)sender {
    if (self.modalVideoAd.isReady) {
        [self.modalVideoAd presentFromViewController:self];
    } else {
        NSLog(@"%s, 广告资源尚未准备好。", __FUNCTION__);
    }
}

#pragma mark - SMAModalVideoAdDelegate
- (void)modalVideoAdDidLoad:(SMAModalVideoAd *)modalVideoAd {
    NSLog(@"%s", __FUNCTION__);
    [[[UIAlertView alloc] initWithTitle:@"广告已经准备就绪"
                               message:@"广告已经准备就绪，可以随时播放"
                              delegate:nil
                     cancelButtonTitle:@"OK"
                     otherButtonTitles:nil, nil] show];
}

- (void)modalVideoAdDidPlayFinished:(SMAModalVideoAd *)modalVideoAd {
    NSLog(@"%s", __FUNCTION__);
}

- (void)modalVideoAd:(SMAModalVideoAd *)modalVideoAd didFailToPlayWithError:(NSError *)error {
    NSLog(@"%s, error:%@", __FUNCTION__, error);
}

- (void)modalVideoAdDidTap:(SMAModalVideoAd *)modalVideoAd {
    NSLog(@"%s", __FUNCTION__);
}

- (void)modalVideoAdDidClose:(SMAModalVideoAd *)modalVideoAd {
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
