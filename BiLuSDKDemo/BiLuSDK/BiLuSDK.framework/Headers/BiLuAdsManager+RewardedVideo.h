//
//  BiLuAdsManager+RewardedVideo.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import "BiLuAdsManager.h"
#import "BiLuAdsRewardedVideoDelegate.h"
#import <UIKit/UIKit.h>

extern NSString *const kUPArpuAdLoadingExtraKeywordKey;
extern NSString *const kUPArpuAdLoadingExtraUserDataKeywordKey;
extern NSString *const kUPArpuAdLoadingExtraUserIDKey;
extern NSString *const kUPArpuAdLoadingExtraLocationKey;

extern NSString *const kUPArpuRewardedVideoCallbackExtraAdsourceIDKey;
extern NSString *const kUPArpuRewardedVideoCallbackExtraNetworkIDKey;

@interface BiLuAdsManager (RewardedVideo)

/**
 返回激励视频广告是否准备好显示
 
 @param placementId 广告位Id
 @return 如果YES表示激励视频广告已经显示
 */
- (BOOL)rewardedVideoReadyForPlacementId:(NSString *)placementId;


/**
 返回激励视频广告视图
 
 @param placementId 广告位Id
 @param viewController 激励视频需要加载的主视图
 @param delegate 回调代理
 */
- (void)showRewardedVideoWithPlacementId:(NSString *)placementId inViewController:(UIViewController *)viewController delegate:(id<BiLuAdsRewardedVideoDelegate>)delegate;

@end

 
