//
//  BiLuAdsInterstitialDelegate.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BiLuAdsInterstitialDelegate <BiLuAdsLoadingDelegate>


/**
 横屏广告显示成功

 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)interstitialDidShowForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 横屏广告显示失败

 @param placementId 广告位Id
 @param error 错误信息
 @param extra 附加信息
 */
- (void)interstitialFailedToShowForPlacementId:(NSString *)placementId error:(NSError *)error extra:(NSDictionary *)extra;


/**
 横屏视频广告播放成功

 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)interstitialDidStartPlayingVideoForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 横屏视频广告播放失败

 @param placementId 广告位Id
 @param error 错误信息
 @param extra 附加信息
 */
- (void)interstitialDidFailToPlayVideoForPlacementId:(NSString *)placementId error:(NSError *)error extra:(NSDictionary *)extra;


/**
 横屏视频广告播放结束

 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)interstitialDidEndPlayingVideoForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 横屏广告点击事件
 
 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)interstitialDidClickForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 横屏广告关闭事件

 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)interstitialDidCloseForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


@end

 
