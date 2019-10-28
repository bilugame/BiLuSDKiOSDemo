//
//  UPArpuBannerDelegate.h
//  UpArpuSDK
//
//  Created by Martin Lau on 18/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef UPArpuBannerDelegate_h
#define UPArpuBannerDelegate_h
#import <UpArpuSDK/UpArpuSDK.h>
@class UPArpuBannerView;
@protocol UPArpuBannerDelegate<UPArpuAdLoadingDelegate>
-(void) bannerView:(UPArpuBannerView*)bannerView didShowAdWithPlacementID:(NSString*)placementID;
-(void) bannerView:(UPArpuBannerView*)bannerView didClickWithPlacementID:(NSString*)placementID;
-(void) bannerView:(UPArpuBannerView*)bannerView didCloseWithPlacementID:(NSString*)placementID;
-(void) bannerView:(UPArpuBannerView*)bannerView didAutoRefreshWithPlacement:(NSString*)placementID;
-(void) bannerView:(UPArpuBannerView*)bannerView failedToAutoRefreshWithPlacementID:(NSString*)placementID error:(NSError*)error;
@end
#endif /* UPArpuBannerDelegate_h */
