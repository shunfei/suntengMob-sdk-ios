[toc]

# 舜飞移动广告 SDK iOS 版 v3.2.0 集成、使用文档

## 1、开发环境、账号获取

* Xcode 7.0 或更高版本
* 支持 iOS 6.0.0 或更高版本

请从 [官网](http://mbv.biddingx.com/main/) 注册并获取 **AdUnitID**、**AppSecret**。

## 2、SDK 集成

### 2.1、添加 SDK 文件

**将 SDK 文件夹加入项目中，包含以下头文件和静态库文件：**

```objc
-📂 SuntengMobileAds
 |-📄 SuntengMobileAds.h
 |-📄 SMAConstants.h
 |-📄 SMABannerView.h
 |-📄 SMAInterstitialAdController.h
 |-📄 SMASplashAd.h
 |-📄 SMAModalVideoAd.h
 |-📄 SMAWindowVideoAd.h
 |-📄 SMANativeAd.h
 |-📄 SMANativeAdView.h
 |-📄 SMANativeAdImage.h
 |-📄 SMAPreMovieAd.h
 |-📄 SMAVideoNativeAd.h
 |-📦 libSuntengMobileAds.a
```

### 2.2、添加所需的 Framework

```objc
AdSupport.framework
AVFoundation.framework
CoreLocation.framework
CoreTelephony.framework
Foundation.framework
StoreKit.framework
SystemConfiguration.framework
UIKit.framework
libz.tbd
```
	
### 2.3、设置编译选项

设置对应 **target** 的编译选项，在『Build Settings』->『Linking』->『Other Linker Flags』，添加 `-ObjC` 参数。

### 2.4、设置定位请求提示语

在 info.plist 里加入对应的定位请求字段，值填写获取定位请求提示框要显示的内容。

```XML
<key>NSLocationWhenInUseUsageDescription</key>
<string>iOS 8 定位权限请求提示语！</string>
<key>NSLocationUsageDescription</key>
<string>iOS 6 定位权限请求提示语！</string>
```

**说明：由于部分广告会定向投递到某些城市，SDK 需要获取地理位置以支持广告的定向投放。**

## 3、SDK 使用

### 3.1、公共设置

**在使用 SDK 的代码中加入头文件。**

```objc
#import "SuntengMobileAds.h"
```

**初始化 SDK**

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[SuntengMobileAds sharedSDK] registerSDKWithAppSecret:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"];
    return YES;
}
```

**其它公共方法**

```objc
// 获取当前 SDK 版本
- (NSString *)version;

// 关闭基于位置的广告投放
- (void)disableLocationService;

// 打开 log
- (void)enableLoger;
```

### 3.2、横幅广告

#### 3.2.1、创建横幅广告

```objc
self.bannerView = [[SMABannerView alloc] initWithAdUnitID:@"2-36-35"
                                                    frame:CGRectMake(0, 64, 320, 50)];
```

#### 3.2.2、请求横幅广告

```objc
[self.bannerView loadAd];
```

#### 3.2.3、展示横幅广告

当您需要展示横幅广告时，请在尝试展示之前检查它是否已准备就绪。

```objc
if (self.bannerView.isLoaded) {
    [self.view addSubview:self.bannerView];
}
```

#### 3.2.4、跟踪横幅广告生命周期

您可以通过实现 `SMABannerViewDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
// 当横幅广告被成功加载后，回调该方法
- (void)bannerViewDidLoadAd:(SMABannerView *)bannerView;

// 当横幅广告加载失败后，回调该方法
- (void)bannerView:(SMABannerView *)bannerView didFailToLoadAdWithError:(NSError *)error;

// 当用户点击广告，回调该方法
- (void)bannerViewDidTap:(SMABannerView *)bannerView;

// 当横幅广告被关闭后，回调该方法
- (void)bannerViewDidDismiss:(SMABannerView *)bannerView;
```

#### 3.2.5、优化横幅广告获取、展示

在横幅广告不在界面展示时，建议开发者使用以下两个方法暂停和恢复广告的自动刷新，减少在无展示时的刷新行为。

```objc
// 手动停止 Banner 自动刷新
- (void)stopAutomaticallyRefreshingAd;

// 恢复 Banner 自动刷新
- (void)startAutomaticallyRefreshingAd;
```

### 3.3、插屏广告

#### 3.3.1、创建插屏广告

```objc
self.interstitialAdController = [SMAInterstitialAdController interstitialAdControllerWithAdUnitID:@"2-36-36"];
```

#### 3.3.2、请求插屏广告

```objc
[self.interstitialAdController loadAd];
```

#### 3.3.3、展示插屏广告

当您需要展示插屏广告时，请在尝试展示之前检查它是否已准备就绪。

```objc
if (self.interstitialAdController.isLoaded) {
	[self.interstitialAdController presentFromViewController:self];
} 
```

#### 3.3.4、跟踪插屏广告生命周期

您可以通过实现 `SMAInterstitialAdControllerDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
// 当插屏广告被成功加载后，回调该方法
- (void)interstitialDidLoad:(SMAInterstitialAdController *)interstitial;

// 当插屏广告加载失败后，回调该方法
- (void)interstitialDidLoadFail:(SMAInterstitialAdController *)interstitial;

// 当插屏广告展示出来时，回调该方法
- (void)interstitialDidPresent:(SMAInterstitialAdController *)interstitial;

// 当用户点击广告，回调该方法
- (void)interstitialDidTap:(SMAInterstitialAdController *)interstitial;

// 当插屏广告被关闭后，回调该方法
- (void)interstitialDidDismiss:(SMAInterstitialAdController *)interstitial;
```

### 3.4、开屏广告

#### 3.4.1、初始化开屏广告、展示开屏广告

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // 初始化 SDK
    [[SuntengMobileAds sharedSDK] registerSDKWithAppSecret:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"];
    
    // 从 MainStoryboard 加载 rootViewController
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    UIViewController *vc = [storyboard instantiateInitialViewController];
    
    // 手动创建 window
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    
    // 初始化开屏广告
    self.splashAd = [SMASplashAd splashAdWithAdUnitID:@"2-36-34"];
    
    self.splashAd.delegate = self;
    
    // 展示开屏广告
    [self.splashAd presentInWindow:self.window
                   backgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"LaunchImage"]]];
    
    return YES;
}
```

#### 3.4.2、跟踪开屏广告生命周期

您可以通过实现 `SMASplashAdDelegate ` 中定义的协议，来跟踪广告生命周期中的各个阶段。所有方法定义如下：

```objc
// 当开屏广告被成功展示后，回调该方法
- (void)splashDidPresent:(SMASplashAd *)splash;

// 当开屏广告展示失败后，回调该方法
- (void)splashFailPresent:(SMASplashAd *)splash;

// 当用户点击广告，回调该方法
- (void)splashDidTap:(SMASplashAd *)splash;

// 当开屏广告被关闭后，回调该方法
- (void)splashDidDismiss:(SMASplashAd *)splash;
```

#### 3.4.3、设置实时开屏广告请求超时时间

开屏广告混合了缓存的开屏广告和实时获取功能。当本地没有缓存的开屏广告或者本地已缓存广告超时时， SDK 会发起实时开屏广告请求，实时开屏广告超时时间内默认设定为 2 秒，以提高用户体验。您可以通过以下方法自定义超时时间，以提高实时开屏广告展示的成功几率。

```objc
- (void)setRealtimeSplashTimeoutInterval:(CGFloat)interval;
```

### 3.5、原生广告

#### 3.5.1、创建原生广告

```objc
self.nativeAd = [[SMANativeAd alloc] initWithAdUnitID:@"2-36-53"];
```

#### 3.5.2、请求原生广告

```objc
[self.nativeAd loadAd];
```

#### 3.5.3、展示原生广告

从 `SMANativeAdView` 子类化一个视图，并根据自己的样式需求使用 `SMANativeAd` 提供的元素：

```objc
@property (nullable, nonatomic, strong, readonly) SMANativeAdImage *logo;
@property (nullable, nonatomic, strong, readonly) NSString *title;
@property (nullable, nonatomic, strong, readonly) NSString *detail;
@property (nullable, nonatomic, strong, readonly) SMANativeAdImage *icon;
@property (nullable, nonatomic, strong, readonly) NSString *action;
@property (nullable, nonatomic, strong, readonly) NSArray<SMANativeAdImage *> *images;
```

添加到视图上，并布局好。

添加展示视图前，先调用 `- (void)registerNativeAdView:(SMANativeAdView *)nativeAdView withViewController:(UIViewController *)viewController;` 方法将视图和广告绑定起来。

#### 3.5.4、跟踪原生广告生命周期

```objc
// 当原生广告被成功加载后，回调该方法
- (void)nativeAdDidLoad:(SMANativeAd *)nativeAd;

// 当原生广告加载失败后，回调该方法
- (void)nativeAd:(SMANativeAd *)nativeAd didLoadFailWithError:(NSError *)error;

// 当原生广告展示出来时，回调该方法
- (void)nativeAdDidPresent:(SMANativeAd *)nativeAd;

// 当用户点击广告，回调该方法
- (void)nativeAdDidTap:(SMANativeAd *)nativeAd;
```

### 3.6、全屏视频广告

#### 3.6.1、创建全屏视频广告

```objc
self.modalVideoAd = [[SMAModalVideoAd alloc] initWithAdUnitID:@"2-36-41"];
```

#### 3.6.2、请求全屏视频广告

```objc
[self.modalVideoAd loadAd];
```

#### 3.6.3、展示全屏视频广告

当您需要展示全屏视频广告时，请在尝试展示之前检查它是否已准备就绪。

```objc
if (self.modalVideoAd.isReady) {
    [self.modalVideoAd presentFromViewController:rootViewController];
}
```

#### 3.6.4、跟踪全屏视频广告生命周期

```objc
- (void)modalVideoAdDidLoad:(SMAModalVideoAd *)modalVideoAd;

- (void)modalVideoAd:(SMAModalVideoAd *)modalVideoAd didFailToLoadWithError:(NSError *)error;

- (void)modalVideoAd:(SMAModalVideoAd *)modalVideoAd didFailToPlayWithError:(NSError *)error;

- (void)modalVideoAdDidTap:(SMAModalVideoAd *)modalVideoAd;

- (void)modalVideoAdDidPlayFinished:(SMAModalVideoAd *)modalVideoAd;

- (void)modalVideoAdDidClose:(SMAModalVideoAd *)modalVideoAd;
```
#### 3.6.5、全屏视频其它 API

```objc
// 是否展示广告关闭按钮
- (void)showCloseVideoButton:(BOOL)yesOrNo;

// 自定义关闭提示语
- (void)customizeAlertViewContents:(NSString *)contents;
```

### 3.7、窗口视频广告

#### 3.7.1、创建窗口视频广告

```objc
self.windowVideoAd = [[SMAWindowVideoAd alloc] initWithAdUnitID:@"2-36-41"];
```

#### 3.7.2、请求窗口视频广告

```objc
[self.windowVideoAd loadAd];
```

#### 3.7.3、展示窗口视频广告

当您需要展示窗口视频广告时（**请提前获取广告，并在广告资源下载成功后再展示**），请在展示之前检查它是否已准备就绪。

```objc
if (self.windowVideoAd.isReady) {
    [self.windowVideoAd disposeInView:containerView presentFromViewController:rootViewController];
}
```

#### 3.7.4、跟踪窗口视频广告生命周期

```objc
- (void)windowVideoAdDidLoad:(SMAWindowVideoAd *)windowVideoAd;

- (void)windowVideoAd:(SMAWindowVideoAd *)windowVideoAd didFailToLoadWithError:(NSError *)error;

- (void)windowVideoAdDidTap:(SMAWindowVideoAd *)windowVideoAd;

- (void)windowVideoAdDidPlayFinished:(SMAWindowVideoAd *)windowVideoAd;
```

### 3.8、贴片视频广告

#### 3.8.1、创建贴片视频广告

```objc
self.preMovieAd = [[SMAPreMovieAd alloc] initWithAdUnitID:@"2-36-143"];
```

#### 3.8.2、请求贴片视频广告

```objc
[self.preMovieAd loadAd];
```

#### 3.8.3、展示贴片视频广告

当您需要展示贴片视频广告时（**请提前获取广告，并在广告资源下载成功后再展示**），请在展示之前检查它是否已准备就绪。

```objc
if (self.preMovieAd.isReady) {
    [self.preMovieAd disposeInView:self.preMovieAdContainerView presentFromViewController:rootViewController];
}
```

#### 3.8.4、跟踪贴片视频广告生命周期

```objc
- (void)preMovieAdDidLoad:(SMAPreMovieAd *)preMovieAd;

- (void)preMovieAd:(SMAPreMovieAd *)preMovieAd didFailToLoadWithError:(NSError *)error;

- (void)preMovieAdDidTap:(SMAPreMovieAd *)preMovieAd;

- (void)preMovieAdDidPlayFinished:(SMAPreMovieAd *)preMovieAd;

- (void)updatePreMovieAdPlayCurrentTime:(NSTimeInterval)time duration:(NSTimeInterval)duration;
```

#### 3.8.5、贴片视频其它 API

```objc
// 是否展示贴片广告进度倒计时
@property(nonatomic, assign, getter=isTimeCounterHidden) BOOL timeCounterHidden;

// 是否展示“查看详情”按钮
@property(nonatomic, assign, getter=isCheckDetailButtonHidden) BOOL checkDetailButtonHidden;

// 设置贴片广告支持的网络环境，默认支持 2G、3G、4G、Wi-Fi 网络环境下下载广告资源。
@property (nonatomic, assign) SMASupportedNetworkOptions supportedNetwork;

- (void)setMuteEnable:(BOOL)muteEnable;
```

### 3.9 视频信息流广告

#### 3.9.1、创建视频信息流广告

```objc
self.videoNativeAd = [[SMAVideoNativeAd alloc] initWithAdUnitID:@"2-36-184"];
```

#### 3.9.2、请求视频信息流广告

```objc
[self.videoNativeAd loadAd];
```

#### 3.9.3、展示视频信息流广告

```objc
[self.videoNativeAd unregisterView];
[self.videoNativeAd setMediaView:mediaView];
[self.videoNativeAd registerAdView:containerView withViewController:rootViewController];
```

#### 3.9.4、跟踪视频信息流广告生命周期

```objc
- (void)videoNativeAdDidLoad:(SMAVideoNativeAd *)nativeAd;

- (void)videoNativeAd:(SMAVideoNativeAd *)nativeAd didLoadFailWithError:(NSError *)error;

- (void)videoNativeAdDidImpression:(SMAVideoNativeAd *)nativeAd;

- (void)videoNativeAdDidTap:(SMAVideoNativeAd *)nativeAd;
```

#### 3.9.5、视频信息流广告其它 API

```objc
@property (nonatomic, assign, getter=isMuted) BOOL muted;

@property (nonatomic, assign, getter=isAutoplayEnabled) BOOL autoplayEnabled;
```