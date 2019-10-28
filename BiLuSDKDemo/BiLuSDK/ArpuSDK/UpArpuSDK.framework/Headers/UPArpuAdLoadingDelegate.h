//
//  UPArpuAdLoadingDelegate.h
//  UpArpuSDK
//
//  Created by Martin Lau on 04/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef UPArpuAdLoadingDelegate_h
#define UPArpuAdLoadingDelegate_h
@protocol UPArpuAdLoadingDelegate<NSObject>
-(void) didFinishLoadingADWithPlacementID:(NSString *)placementID;
-(void) didFailToLoadADWithPlacementID:(NSString*)placementID error:(NSError*)error;
@end
#endif /* UPArpuAdLoadingDelegate_h */
