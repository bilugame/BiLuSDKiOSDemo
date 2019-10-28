//
//  UPArpuAdManager+RewardedVideo.h
//  UpArpuSDK
//
//  Created by Martin Lau on 05/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UpArpuSDK/UpArpuSDK.h>
#import "UPArpuRewardedVideoDelegate.h"
/*
 * Third-party extra data
 */
extern NSString *const kUPArpuAdLoadingExtraKeywordKey;
extern NSString *const kUPArpuAdLoadingExtraUserDataKeywordKey;
extern NSString *const kUPArpuAdLoadingExtraUserIDKey;
extern NSString *const kUPArpuAdLoadingExtraLocationKey;

extern NSString *const kUPArpuRewardedVideoCallbackExtraAdsourceIDKey;
extern NSString *const kUPArpuRewardedVideoCallbackExtraNetworkIDKey;
@interface UPArpuAdManager (RewardedVideo)
-(BOOL) rewardedVideoReadyForPlacementID:(NSString*)placementID;
-(void) showRewardedVideoWithPlacementID:(NSString*)placementID inViewController:(UIViewController*)viewController delegate:(id<UPArpuRewardedVideoDelegate>)delegate;

@end
