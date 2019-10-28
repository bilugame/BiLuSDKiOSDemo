//
//  UPArpuInterstitialDelegate.h
//  UpArpuInterstitial
//
//  Created by Martin Lau on 21/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef UPArpuInterstitialDelegate_h
#define UPArpuInterstitialDelegate_h
#import <UpArpuSDK/UpArpuSDK.h>

extern NSString *const kUPArpuInterstitialDelegateExtraNetworkIDKey;
extern NSString *const kUPArpuInterstitialDelegateExtraAdSourceIDKey;
@protocol UPArpuInterstitialDelegate<UPArpuAdLoadingDelegate>
-(void) interstitialDidShowForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;
-(void) interstitialFailedToShowForPlacementID:(NSString*)placementID error:(NSError*)error DEPRECATED_ATTRIBUTE;
-(void) interstitialDidStartPlayingVideoForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;
-(void) interstitialDidEndPlayingVideoForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;
-(void) interstitialDidFailToPlayVideoForPlacementID:(NSString*)placementID error:(NSError*)error DEPRECATED_ATTRIBUTE;
-(void) interstitialDidCloseForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;
-(void) interstitialDidClickForPlacementID:(NSString*)placementID DEPRECATED_ATTRIBUTE;

-(void) interstitialDidShowForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
-(void) interstitialFailedToShowForPlacementID:(NSString*)placementID error:(NSError*)error extra:(NSDictionary*)extra;
-(void) interstitialDidStartPlayingVideoForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
-(void) interstitialDidEndPlayingVideoForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
-(void) interstitialDidFailToPlayVideoForPlacementID:(NSString*)placementID error:(NSError*)error extra:(NSDictionary*)extra;
-(void) interstitialDidCloseForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
-(void) interstitialDidClickForPlacementID:(NSString*)placementID extra:(NSDictionary*)extra;
@end

#endif /* UPArpuInterstitialDelegate_h */
