//
//  BiLuAdsBannerDelegate.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UpArpuBanner/UpArpuBanner.h>

@protocol BiLuAdsBannerDelegate <BiLuAdsLoadingDelegate>


/**
 Banner广告显示成功

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(UPArpuBannerView *)bannerView didShowAdWithPlacementId:(NSString *)placementId;


/**
 Banner广告点击事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(UPArpuBannerView *)bannerView didClickWithPlacementId:(NSString *)placementId;


/**
 Banner广告关闭事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(UPArpuBannerView *)bannerView didCloseWithPlacementId:(NSString *)placementId;


/**
 Banner广告自动刷新事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 */
- (void)bannerView:(UPArpuBannerView *)bannerView didAutoRefreshWithPlacementId:(NSString *)placementId;


/**
 Banner广告自动刷新回调失败事件

 @param bannerView bannerView视图
 @param placementId 广告位Id
 @param error 错误信息
 */
- (void)bannerView:(UPArpuBannerView *)bannerView failedToAutoRefreshWithPlacementId:(NSString *)placementId error:(NSError*)error;

@end

 
