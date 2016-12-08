//
//  STMNativeAdTableViewController.m
//  STMobSDKSample
//
//  Created by samingzhong on 2016/11/23.
//  Copyright © 2016年 sunteng. All rights reserved.
//

#import "STMNativeAdTableViewController.h"
#import "STMNativeAd.h"
#import "CustomNativeAdCell.h"

@interface STMNativeAdTableViewController () <STMNativeAdDelegate>
@property (nonatomic, strong) NSMutableArray *tableViewContentArray;
@property (nonatomic, strong) STMNativeAd *topPlaceNativeAd;

@end

@implementation STMNativeAdTableViewController

- (NSMutableArray *)tableViewContentArray {
    if (!_tableViewContentArray) {
        _tableViewContentArray = [NSMutableArray array];
        for (NSUInteger i = 0; i < 20; i++) {
            [_tableViewContentArray addObject:[NSString stringWithFormat:@"TableView Cell #%lu", (unsigned long)(i + 1)]];
        }
    }
    
    return _tableViewContentArray;
}

- (IBAction)fetchAd:(id)sender {
    self.topPlaceNativeAd = [[STMNativeAd alloc] initWithPublisherID:PUBLISHERID
                                                               appID:APPID
                                                         placementID:@"53"
                                                              appKey:APPKEY];
    self.topPlaceNativeAd.delegate = self;
    [self.topPlaceNativeAd loadAd];
}

#pragma mark - STMNativeAdDelegate

- (void)nativeAdDidLoad:(STMNativeAd *)nativeAd {
    NSLog(@"%s", __FUNCTION__);
    
    NSDictionary *adDict = @{@"isAd" : @YES,
                             @"ad" : nativeAd};
    
    [self.tableViewContentArray insertObject:adDict atIndex:0];
    NSIndexPath *indexPath = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.tableView insertRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationLeft];
}

- (void)nativeAd:(STMNativeAd *)nativeAd didLoadFailWithError:(NSError *)error {
    NSLog(@"%s", __FUNCTION__);
}

- (void)nativeAdDidPresent:(STMNativeAd *)nativeAd {
    NSLog(@"%s", __FUNCTION__);
}

- (void)nativeAdDidTap:(STMNativeAd *)nativeAd {
    NSLog(@"%s", __FUNCTION__);
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.tableViewContentArray.count;
}

#pragma mark - UITableViewDelegate

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    id data = self.tableViewContentArray[indexPath.row];
    
    if ([data isKindOfClass:[NSString class]]) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MyCellIdentifier" forIndexPath:indexPath];
        
        // Configure the cell...
        cell.textLabel.text = self.tableViewContentArray[indexPath.row];
        return cell;
    } else if([data isKindOfClass:[NSDictionary class]] && ((NSNumber *)data[@"isAd"]).boolValue){
        CustomNativeAdCell *cell = (CustomNativeAdCell *)[tableView dequeueReusableCellWithIdentifier:@"MyCellIdentifier1" forIndexPath:indexPath];
        // 获取nativeAd
        STMNativeAd *nativeAd = self.tableViewContentArray[indexPath.row][@"ad"];
        [nativeAd registerNativeAdView:cell.nativeAdView withViewController:self];
        
        cell.iconImageView.image = nativeAd.icon.image;
        cell.adTitleLabel.text = nativeAd.title;
        cell.adDetailLabel.text = nativeAd.detail;
        cell.adLogoImageView.image = nativeAd.logo.image;
        
        return cell;
    } else {
        // 未定义数据
        return nil;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    id data = self.tableViewContentArray[indexPath.row];
    
    if ([data isKindOfClass:[NSString class]]) {
        return 44;
    } else if([data isKindOfClass:[NSDictionary class]] && ((NSNumber *)data[@"isAd"]).boolValue){
        return 117;
    } else {
        return 44;
    }
}

@end
