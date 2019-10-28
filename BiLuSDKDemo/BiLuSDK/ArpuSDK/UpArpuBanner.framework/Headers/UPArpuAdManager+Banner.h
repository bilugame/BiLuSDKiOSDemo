//
//  UPArpuAdManager+Banner.h
//  UpArpuBanner
//
//  Created by Martin Lau on 18/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UpArpuSDK/UpArpuSDK.h>
//Supported by Nend banner only
extern NSString *const kUPArpuBannerLoadingExtraParameters;
extern NSString *const kUPArpuAdLoadingExtraBannerAdSizeKey;//defaults to 320 * 50
extern NSString *const kUPArpuAdLoadingExtraBannerSizeAdjustKey;//Currently supported by Nend
@class UPArpuBannerView;
@interface UPArpuAdManager (Banner)
-(BOOL) bannerAdReadyForPlacementID:(NSString*)placementID;
/*
 nil will be returned if you try to show banner ad for the placementID if it's not ready.
 */
-(nullable UPArpuBannerView*)retrieveBannerViewForPlacementID:(NSString*)placementID;
@end
