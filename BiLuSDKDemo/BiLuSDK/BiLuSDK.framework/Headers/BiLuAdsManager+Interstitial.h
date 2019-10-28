//
//  BiLuAdsManager+Interstitial.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import "BiLuAdsManager.h"
#import "BiLuAdsInterstitialDelegate.h"
#import <UIKit/UIKit.h>

extern NSString *const kUPArpuInterstitialExtraMediationNameKey;
extern NSString *const kUPArpuInterstitialExtraUserIDKey;
extern NSString *const kUPArpuInterstitialExtraUserFeatureKey;
extern NSString *const kUPArpuInterstitialExtraLocationEnabledFlagKey;
extern NSString *const kUPArpuInterstitialExtraMuteStartPlayingFlagKey;
extern NSString *const kUPArpuInterstitialExtraFallbackFullboardBackgroundColorKey;
extern NSString *const kUPArpuInterstitialExtraAdSizeKey;//Supported by TT interstitial, defaults to 600 X 600

extern NSString *const kUPArpuInterstitialExtraAdSize600_400;
extern NSString *const kUPArpuInterstitialExtraAdSize600_600;
extern NSString *const kUPArpuInterstitialExtraAdSize600_900;

@interface BiLuAdsManager (Interstitial)


/**
 返回横屏广告是否准备好显示

 @param placementId 广告位Id
 @return 如果YES表示横屏广告已经显示
 */
- (BOOL)interstitialReadyForPlacementId:(NSString *)placementId;


/**
 返回横屏广告视图

 @param placementId 广告位Id
 @param viewController 横屏广告需要加载的主视图
 @param delegate 回调代理
 */
- (void)showInterstitialWithPlacementId:(NSString *)placementId inViewController:(UIViewController *)viewController delegate:(id<BiLuAdsInterstitialDelegate>)delegate;

@end

 
