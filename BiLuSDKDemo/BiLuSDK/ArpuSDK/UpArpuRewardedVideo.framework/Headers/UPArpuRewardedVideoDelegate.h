//
//  UPArpuRewardedVideoDelegate.h
//  UpArpuSDK
//
//  Created by Martin Lau on 05/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef UPArpuRewardedVideoDelegate_h
#define UPArpuRewardedVideoDelegate_h
#import <UpArpuSDK/UpArpuSDK.h>

extern NSString *const kUPArpuRewardedVideoCallbackExtraAdsourceIDKey;
extern NSString *const kUPArpuRewardedVideoCallbackExtraNetworkIDKey;
@protocol UPArpuRewardedVideoDelegate<UPArpuAdLoadingDelegate>
-(void) rewardedVideoDidStartPlayingForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;
-(void) rewardedVideoDidEndPlayingForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;
-(void) rewardedVideoDidFailToPlayForPlacementID:(NSString*)placementID error:(NSError*)error DEPRECATED_ATTRIBUTE;
-(void) rewardedVideoDidCloseForPlacementID:(NSString*)placementID rewarded:(BOOL)rewarded DEPRECATED_ATTRIBUTE;
-(void) rewardedVideoDidClickForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;

-(void) rewardedVideoDidStartPlayingForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
-(void) rewardedVideoDidEndPlayingForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
-(void) rewardedVideoDidFailToPlayForPlacementID:(NSString*)placementID error:(NSError*)error extra:(NSDictionary*)extra;
-(void) rewardedVideoDidCloseForPlacementID:(NSString*)placementID rewarded:(BOOL)rewarded extra:(NSDictionary*)extra;
-(void) rewardedVideoDidClickForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
@end
#endif /* UPArpuRewardedVideoDelegate_h */
