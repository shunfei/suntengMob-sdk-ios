//
//  SMANativeAdImage.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMANativeAdImage : NSObject

@property (nullable, nonatomic, strong, readonly) UIImage *image;
@property (nullable, nonatomic, strong, readonly) NSURL *imageURL;

@end

NS_ASSUME_NONNULL_END
