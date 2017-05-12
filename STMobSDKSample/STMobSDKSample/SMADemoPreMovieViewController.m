//
//  SMADemoPreMovieViewController.m
//  STMobSDKSample
//
//  Created by Joe on 17/5/12.
//  Copyright © 2017年 sunteng. All rights reserved.
//

#import "SMADemoPreMovieViewController.h"
#import "SuntengMobileAds.h"

@interface SMADemoPreMovieViewController () <SMAPreMovieAdDelegate>

@property (weak, nonatomic) IBOutlet UIView *playerView;
@property (nonatomic, strong) SMAPreMovieAd *preMovieAd;

@end

@implementation SMADemoPreMovieViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.preMovieAd = [[SMAPreMovieAd alloc] initWithAdUnitID:@"2-36-143"];
    self.preMovieAd.delegate = self;
}

#pragma mark - IBAction

- (IBAction)loadAd:(id)sender {
    [self.preMovieAd loadAd];
}

- (IBAction)disposeAd:(id)sender {
    if (self.preMovieAd.isReady) {
        [self.preMovieAd disposeInView:self.playerView presentFromViewController:self];
    }
}

#pragma mark - SMAPreMovieAdDelegate

- (void)preMovieAdDidLoad:(SMAPreMovieAd *)preMovieAd {
    NSLog(@"%s", __func__);
}

- (void)preMovieAd:(SMAPreMovieAd *)preMovieAd didFailToLoadWithError:(NSError *)error {
    NSLog(@"%s", __func__);
}

- (void)preMovieAdDidTap:(SMAPreMovieAd *)preMovieAd {
    NSLog(@"%s", __func__);
}

- (void)preMovieAdDidPlayFinished:(SMAPreMovieAd *)preMovieAd {
    NSLog(@"%s", __func__);
}

- (void)updatePreMovieAdPlayCurrentTime:(NSTimeInterval)time duration:(NSTimeInterval)duration {
    NSLog(@"%s", __func__);
}

@end
