//
//  BiLuAdsBannerDelegate.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AnyThinkBanner/AnyThinkBanner.h>

@protocol BiLuAdsBannerDelegate <BiLuAdsLoadingDelegate>


/**
 Banner广告显示成功

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(ATBannerView *)bannerView didShowAdWithPlacementId:(NSString *)placementId;


/**
 Banner广告点击事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(ATBannerView *)bannerView didClickWithPlacementId:(NSString *)placementId;


/**
 Banner广告关闭事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(ATBannerView *)bannerView didCloseWithPlacementId:(NSString *)placementId;


/**
 Banner广告自动刷新事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(ATBannerView *)bannerView didAutoRefreshWithPlacementId:(NSString *)placementId;


/**
 Banner广告自动刷新回调失败事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 @param error 错误信息
 */
- (void)bannerView:(ATBannerView *)bannerView failedToAutoRefreshWithPlacementId:(NSString *)placementId error:(NSError*)error;

@end

 
