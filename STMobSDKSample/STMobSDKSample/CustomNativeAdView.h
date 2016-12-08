//
//  CustomNativeAdView.h
//  STMobSDKSample
//
//  Created by samingzhong on 2016/11/23.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STMNativeAdView.h"
@interface CustomNativeAdView : UIView
@property (weak, nonatomic) IBOutlet UIImageView *nativeAdIconImageView;
@property (weak, nonatomic) IBOutlet UILabel *nativeAdTitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *nativeAdDetailLabel;
@property (weak, nonatomic) IBOutlet UIImageView *nativeAdImageView1;
@property (weak, nonatomic) IBOutlet UIImageView *nativeAdImageView2;
@property (weak, nonatomic) IBOutlet UIImageView *nativeAdImageView3;
@property (weak, nonatomic) IBOutlet UIImageView *nativeAdProviderImageView;
@property (weak, nonatomic) IBOutlet STMNativeAdView *adContainerView;
@end
