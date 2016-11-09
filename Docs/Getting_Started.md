# 舜飞移动广告 SDK iOS 版 v2.x.x 开发文档

## 1、开发环境

* Xcode 7.0 或更高版本
* 支持 iOS 6.0.0 或更高版本

关于 **PublisherID** 、 **PlacementID** 、 **AppID** 。请从 [官网](http://mbv.biddingx.com/main/) 获取 PublisherID、PlacementID、AppID。

## 2、SDK 集成

2.1、将最新的 SDK 文件夹，包含头文件 `SuntengMobileAdsSDK.h` 、 `STMConstants.h` 、 `STMBannerView.h` 、 `STMInterstitialAdController.h` 、 `STMSplashAd.h` 和静态库 `libSuntengMobileAdsSDK.a` 加入项目中。

2.2、添加需要的 Framework：

```objc
AdSupport.framework
CoreGraphics.framework
CoreLocation.framework
CoreTelephony.framework
Foundation.framework
StoreKit.framework
SystemConfiguration.framework
UIKit.framework
```
	
2.3、设置对应 **target** 的编译选项，在『Build Settings』->『Linking』->『Other Linker Flags』，添加 `-ObjC` 参数。

2.4、iOS 8.0+ 获取地理位置适配

在 info.plist 里加入对应的定位请求字段，值可以为空或者填写获取定位请求提示框要显示的内容。

```XML
<key>NSLocationWhenInUseUsageDescription</key>
<string>iOS 8 定位权限请求提示语！</string>
<key>NSLocationUsageDescription</key>
<string>iOS 10 定位权限请求提示语！</string>
```

**说明：由于部分广告会定向投递到某些城市，SDK 需要获取地理位置以支持广告的定向投放。**

2.5、Xcode 7.0+ 、iOS 9.0+ 适配

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

	Xcode 7.0 默认开启 **Bitcode** 编译选项（无 **Bitcode** 配置，默认为开启）， SDK 支持 **Bitcode** ，如果您的工程中有其它不支持 **Bitcode** 特性的库可能编译不过。

	**解决方案：请将项目对应『Target』->『Build Settings』->『Build Options』->『Enable Bitcode』选项设置为 No 。**

## 3、SDK 使用

### 3.1、横幅 SDK

在使用 SDK 的代码中加入头文件。

```objc
#import "SuntengMobileAdsSDK.h"
```

#### 3.1.1、初始化横幅 SDK

```objc
self.bannerView = [[STMBannerView alloc] initWithPublisherID:@"2"
                                                           appID:@"36"
                                                     placementID:@"35"
                                                           appKey:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"
                                                           frame:CGRectMake(0, 64, 320, 50)];
[self.bannerView loadAd];
```

#### 3.1.2、展示横幅广告

```objc
if (self.bannerView.isLoaded) {
    [self.view addSubview:self.bannerView];
}
```

#### 3.1.3、跟踪横幅广告生命周期

您可以通过实现 `STMBannerViewDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
// 当横幅广告被成功加载后，回调该方法
- (void)bannerViewDidLoadAd:(STMBannerView *)bannerView;

// 当横幅广告加载失败后，回调该方法
- (void)bannerView:(STMBannerView *)bannerView didFailToLoadAdWithError:(NSError *)error;

// 当用户点击广告，回调该方法
- (void)bannerViewDidTap:(STMBannerView *)bannerView;

// 当横幅广告被关闭后，回调该方法
- (void)bannerViewDidDismiss:(STMBannerView *)bannerView;
```

#### 3.1.4、优化横幅广告获取、展示

在横幅广告不在界面展示时，建议开发者使用以下两个方法暂停和恢复广告的自动刷新，减少在无展示时的刷新行为。

```objc
// 手动停止 Banner 自动刷新
- (void)stopAutomaticallyRefreshingAd;

// 恢复 Banner 自动刷新
- (void)startAutomaticallyRefreshingAd;
```

### 3.2、插屏 SDK

在使用 SDK 的代码中加入头文件。

```objc
#import "SuntengMobileAdsSDK.h"
```

#### 3.2.1、初始化插屏 SDK

```objc
self.interstitialAdController = [STMInterstitialAdController interstitialAdControllerWithPublisherID:@"2"
                                                                                                   appID:@"36"
                                                                                             placementID:@"36"
                                                                                                  appKey:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"];
```

#### 3.2.2、展示插屏广告

当您需要展示插屏广告时，请在尝试展示之前检查它是否已准备就绪。

```objc
if (self.interstitialAdController.isLoaded) {
	[self.interstitialAdController presentFromViewController:self];
} 
```

#### 3.2.3、跟踪插屏广告生命周期

您可以通过实现 `STMInterstitialAdControllerDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
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
```

### 3.3、开屏 SDK

在使用 SDK 的代码中加入头文件。

```objc
#import "SuntengMobileAdsSDK.h"
```

#### 3.3.1、初始化开屏 SDK、展示开屏广告

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //Override point for customization after application launch.
    
    // 从 MainStoryboard 加载 rootViewController
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    UIViewController *vc = [storyboard instantiateInitialViewController];
    
    // 手动创建 window
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    
    // 初始化开屏 SDK
    self.splashAd = [STMSplashAd splashAdWithPublisherID:@"2"
                                                   appID:@"36"
                                             placementID:@"34"
                                                  appKey:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"];
    
    self.splashAd.delegate = self;
    
    // 展示开屏广告
    [self.splashAd presentInWindow:self.window
                   backgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"LaunchImage"]]];
    
    return YES;
}
```

#### 3.3.2、跟踪开屏广告生命周期

您可以通过实现 `STMSplashAdDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
// 当开屏广告被成功展示后，回调该方法
- (void)splashDidPresent:(STMSplashAd *)splash;

// 当开屏广告展示失败后，回调该方法
- (void)splashFailPresent:(STMSplashAd *)splash;

// 当用户点击广告，回调该方法
- (void)splashDidTap:(STMSplashAd *)splash;

// 当开屏广告被关闭后，回调该方法
- (void)splashDidDismiss:(STMSplashAd *)splash;
```

#### 3.3.2、设置实时开屏广告请求超时时间

开屏广告混合了缓存的开屏广告和实时获取功能。当本地没有缓存的开屏广告或者本地已缓存广告超时时， SDK 会发起实时开屏广告请求，实时开屏广告超时时间内默认设定为 2 秒，以提高用户体验。您可以通过以下方法自定义超时时间，以提高实时开屏广告展示的成功几率。

```objc
- (void)setRealtimeSplashTimeoutInterval:(CGFloat)interval;
```


