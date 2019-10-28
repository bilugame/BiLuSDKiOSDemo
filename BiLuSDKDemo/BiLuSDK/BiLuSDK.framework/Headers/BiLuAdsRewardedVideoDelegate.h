//
//  BiLuAdsRewardedVideoDelegate.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BiLuAdsLoadingDelegate.h"

@protocol BiLuAdsRewardedVideoDelegate <BiLuAdsLoadingDelegate>


/**
 激励视频广告播放成功

 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)rewardedVideoDidStartPlayingForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 激励视频广告播放失败
 
 @param placementId 广告位Id
 @param error 错误信息
 @param extra 附加信息
 */
- (void)rewardedVideoDidFailToPlayForPlacementId:(NSString *)placementId error:(NSError *)error extra:(NSDictionary *)extra;


/**
 激励视频广告播放结束

 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)rewardedVideoDidEndPlayingForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 激励视频广告点击事件
 
 @param placementId 广告位Id
 @param extra 附加信息
 */
- (void)rewardedVideoDidClickForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra;


/**
 激励视频广告关闭事件

 @param placementId 广告位Id
 @param rewarded 是否观看完广告获得奖励 YES 是 NO 不是
 @param extra 附加信息
 */
- (void)rewardedVideoDidCloseForPlacementId:(NSString *)placementId rewarded:(BOOL)rewarded extra:(NSDictionary *)extra;


@end


