# 舜飞广告 iOS SDK 1.x 开发文档

## 开发环境

* Xcode 7.0 或更高版本
* 支持 iOS 6.0.0 或更高版本

## PublisherID、PlacementID、AppID

从 [官网](http://mbv.biddingx.com/main/) 获取 PublisherID、PlacementID、AppID。

## SDK 集成

1、将最新的 SDK 头文件 `SuntengMobileAdsSDK.h` 、 `STMInterstitialAdController.h` 和静态库 `libSuntengMobileAdsSDK.a` 加入项目中。

2、添加需要的 Framework：

```objc
AdSupport.framework
CoreFoundation.framework
CoreGraphics.framework
CoreLocation.framework
CoreTelephony.framework
Foundation.framework
SystemConfiguration.framework
UIKit.framework
```
	
3、设置对应 **target** 的编译选项，在『Build Settings』->『Linking』->『Other Linker Flags』，添加 `-ObjC` 参数。

4、iOS 8.0+ 中获取地理位置方法，在 info.plist 里加入对应的定位请求字段，值可以为空或者填写获取定位请求提示框要显示的内容。

```objc
NSLocationWhenInUseUsageDescription   // 允许在前台获取GPS的描述
```

**说明：由于部分广告会定向投递到某些城市，SDK 需要获取地理位置以支持广告的定向投放。**

5、Xcode 7.0+ 、iOS 9.0+ 适配

* 关于 [*ATS*](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240)

	**解决方案：禁用 ATS。**

	在应用的 Info.plist 中添加禁用 ATS 代码。代码如下：

```XML
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
</dict>
```

* 关于 Bitcode

	Xcode 7.0 默认开启 **Bitcode** 编译选项（无 **Bitcode** 配置，默认为开启）， SDK 1.0.0+ 版本开始支持 **Bitcode** ，如果您的工程中有其它不支持 **Bitcode** 特性的库可能编译不过。

	**解决方案：请将项目对应『Target』->『Build Settings』->『Build Options』->『Enable Bitcode』选项设置为 No 。**

## SDK 使用

### 初始化 SDK

```objc
#import "SuntengMobileAdsSDK.h"

@interface ViewController ()

@property(nonatomic, weak) STMInterstitialAdController *interstitialAdController;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.interstitialAdController = [STMInterstitialAdController interstitialAdControllerWithPublishedId:@"1"
                                                                                                   appId:@"2"
                                                                                             placementId:@"3"];
}

@end
```

### 展示插屏广告

当您需要展示插屏广告时，请在尝试展示之前检查它是否已准备就绪。

```objc
if (self.interstitialAdController.isLoaded) {
	[self.interstitialAdController presentFromViewController:self];
} 
```

### 跟踪广告生命周期

您可以通过实现 `STMInterstitialAdControllerDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
@protocol STMInterstitialAdControllerDelegate <NSObject>

@optional

// 当插屏广告被成功加载后，回调该方法
- (void)interstitialDidLoad:(STMInterstitialAdController *)interstitial;

// 当插屏广告加载失败后，回调该方法
- (void)interstitialDidLoadFail:(STMInterstitialAdController *)interstitial;

// 当插屏广告展示出来时，回调该方法
- (void)interstitialDidPresent:(STMInterstitialAdController *)interstitial;

// 当用户点击广告，回调该方法
- (void)interstitialDidTap:(STMInterstitialAdController *)interstitial;

// 当插屏广告被关闭后，回调该方法
- (void)interstitialDidDismiss:(STMInterstitialAdController *)interstitial;

@end
```

