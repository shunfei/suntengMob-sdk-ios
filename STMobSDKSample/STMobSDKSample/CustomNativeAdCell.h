//
//  CustomNativeAdCell.h
//  STMobSDKSample
//
//  Created by samingzhong on 2016/11/23.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import <UIKit/UIKit.h>
@class SMANativeAdView;

@interface CustomNativeAdCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UIImageView *iconImageView;
@property (weak, nonatomic) IBOutlet UILabel *adTitleLabel;
@property (weak, nonatomic) IBOutlet UILabel *adDetailLabel;
@property (weak, nonatomic) IBOutlet UIImageView *adLogoImageView;

@property (weak, nonatomic) IBOutlet SMANativeAdView *nativeAdView;
@end
