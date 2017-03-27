//
//  SMAConstants.h
//  SuntengMobileAds
//
//  Created by Joe.
//  Copyright © 2017年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const SMAErrorDomain;

typedef NS_ENUM(NSInteger, SMAErrorCode) {
    SMAErrorCodeNone = 0,                           // bidding success
    SMAErrorCodeNetworkError,                       // network error
    SMAErrorCodeResponseError,                      // response is not a HTTP URL response
    SMAErrorCodeSystemError,                        // server system error
    SMAErrorCodeNoAd,                               // no ad
    SMAErrorCodeNoData,                             // no response data
    SMAErrorCodeDeserializationError,               // deserialize JSON error
    SMAErrorCodeLoadHTMLFail,                       // load HTML fail
    SMAErrorCodeErrorRequest,                       // error request - HTTP code 204
    SMAErrorCodeRefund,                             // no ad - refund
    SMAErrorCodeBlank,                              // no ad - keep blank
    SMAErrorCodeTimeout,                            // timeout
    SMAErrorCodeLoadResourceFail,                   // load resource fail
    
    SMAErrorCodeDownloadAdResourcesFail,            // download ad resources fail
    SMAErrorCodeUnzipAdResourcesFail,               // unzip ad resources fail
    SMAErrorCodeLoadAdVideoFail,                    // load ad video fail
    
    SMAErrorCodePresentingViewControllerNil,        // presenting view controller nil
    SMAErrorCodeAlreadyHaveAPresentedViewController,// presenting view controller already have a presented view controller
    SMAErrorCodeAlreadyShowingAModalVideoAd,        // already showing a modal video ad
    
    SMAErrorCodeOther = -1                          // other error
};

@interface SMAConstants : NSObject

@end

NS_ASSUME_NONNULL_END
