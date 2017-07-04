//
//  SMAVideoNativeAdTableViewCell.m
//  SuntengMobileAdsSample
//
//  Created by Joe on 2017/6/26.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import "SMAVideoNativeAdTableViewCell.h"

@implementation SMAVideoNativeAdTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(nullable NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.titleLabel = [[UILabel alloc] initWithFrame:CGRectZero];
        self.titleLabel.font = [UIFont systemFontOfSize:17.0f];
        self.titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
        [self.contentView addSubview:self.titleLabel];
        [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-8-[titleLabel]|" options:0 metrics:nil views:@{@"titleLabel": self.titleLabel}]];
        [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-8-[titleLabel]" options:0 metrics:nil views:@{@"titleLabel": self.titleLabel}]];
        
        self.mediaView = [[UIView alloc] initWithFrame:CGRectZero];
        self.mediaView.translatesAutoresizingMaskIntoConstraints = NO;
        [self.contentView addSubview:self.mediaView];
        [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-37-[mediaView]" options:0 metrics:nil views:@{@"mediaView": self.mediaView}]];
        [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:self.mediaView attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self.contentView attribute:NSLayoutAttributeCenterX multiplier:1.0 constant:0.0]];
        [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:[mediaView(==300)]" options:0 metrics:nil views:@{@"mediaView": self.mediaView}]];
        [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:self.mediaView attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:self.mediaView attribute:NSLayoutAttributeWidth multiplier:0.75 constant:0.0]];
    }
    return self;
}

@end
