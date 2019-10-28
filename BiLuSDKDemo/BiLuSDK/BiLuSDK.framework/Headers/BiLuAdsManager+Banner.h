//
//  BiLuAdsManager+Banner.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import "BiLuAdsManager.h"
#import "BiLuAdsBannerDelegate.h"

//Supported by Nend banner only
extern NSString *const kUPArpuBannerLoadingExtraParameters;
extern NSString *const kUPArpuAdLoadingExtraBannerAdSizeKey;//defaults to 320 * 50
extern NSString *const kUPArpuAdLoadingExtraBannerSizeAdjustKey;//Currently supported by Nend

@interface BiLuAdsManager (Banner)


/**
 返回Banner广告是否准备好显示

 @param placementId 广告位Id
 @return 如果YES表示Banner广告已经显示
 */
- (BOOL)bannerAdReadyForPlacementId:(NSString *)placementId;

/**
 返回Banner广告视图

 @param placementId 广告位Id
 @param delegate 回调代理
 @return 如果你尝试为placementId显示Banner广告，如果它还没有准备好，nil将被返回。
 */
- (UPArpuBannerView *)retrieveBannerViewForPlacementId:(NSString *)placementId delegate:(id<BiLuAdsBannerDelegate>)delegate;

@end

 
