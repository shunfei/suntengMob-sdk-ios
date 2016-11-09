//
//  ViewController.m
//  STMobSDKSample
//
//  Created by East on 16/4/22.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import "STMInterstitialAdViewController.h"
#import "SuntengMobileAdsSDK.h"

@interface STMInterstitialAdViewController () <STMInterstitialAdControllerDelegate>

@property (nonatomic, weak) IBOutlet UITextView *logView;
@property (nonatomic, weak) STMInterstitialAdController *interstitialAdController;
@property (nonatomic, assign) BOOL isLoading;

@end

@implementation STMInterstitialAdViewController

#pragma mark - life cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - IBAction

- (IBAction)loadAd:(UIButton *)sender {
    if (self.isLoading) {
        return;
    }
    
    self.isLoading = YES;
    
    if (!self.interstitialAdController) {
        self.interstitialAdController = [STMInterstitialAdController interstitialAdControllerWithPublisherID:PUBLISHERID
                                                                                                       appID:APPID
                                                                                                 placementID:@"36"
                                                                                                      appKey:APPKEY];
        self.interstitialAdController.delegate = self;
    }
    
    [self.interstitialAdController loadAd];
    
    NSMutableString *logString = [NSMutableString stringWithString:@"Start to load ad ...\n--------\n"];
    [logString appendString:self.logView.text];
    self.logView.text = logString;
}

- (IBAction)showInterstitialAd:(UIButton *)sender {
    if (self.interstitialAdController.isLoaded) {
        [self.interstitialAdController presentFromViewController:self];
    } else {
        NSLog(@"The interstitial ad is not loaded yet.");
        
        NSMutableString *logString = [NSMutableString stringWithString:@"Ad is no loaded.\n"];
        [logString appendString:self.logView.text];
        self.logView.text = logString;
    }
}

#pragma mark - STMInterstitialAdControllerDelegate

- (void)interstitialDidLoad:(STMInterstitialAdController *)interstitial {
    NSLog(@"Now can present the interstitial ad.");
    
    NSMutableString *logString = [NSMutableString stringWithString:@"Success to load ad.\n"];
    [logString appendString:self.logView.text];
    self.logView.text = logString;
}

- (void)interstitialDidLoadFail:(STMInterstitialAdController *)interstitial {
    NSLog(@"The interstitial ad load fail.");
    
    NSMutableString *logString = [NSMutableString stringWithString:@"--------\nFail to load ad.\n"];
    [logString appendString:self.logView.text];
    self.logView.text = logString;
    
    self.isLoading = NO;
}

- (void)interstitialDidPresent:(STMInterstitialAdController *)interstitial {
    NSLog(@"The interstitial ad presented.");
    
    NSMutableString *logString = [NSMutableString stringWithString:@"Presented ad.\n"];
    [logString appendString:self.logView.text];
    self.logView.text = logString;
}

- (void)interstitialDidTap:(STMInterstitialAdController *)interstitial {
    NSLog(@"The interstitial ad taped.");
    
    NSMutableString *logString = [NSMutableString stringWithString:@"Ad taped.\n"];
    [logString appendString:self.logView.text];
    self.logView.text = logString;
}

- (void)interstitialDidDismiss:(STMInterstitialAdController *)interstitial {
    NSLog(@"The interstitial ad dismissed.");
    
    NSMutableString *logString = [NSMutableString stringWithString:@"--------\nDismiss ad.\n"];
    [logString appendString:self.logView.text];
    self.logView.text = logString;
    
    self.isLoading = NO;
}

@end
