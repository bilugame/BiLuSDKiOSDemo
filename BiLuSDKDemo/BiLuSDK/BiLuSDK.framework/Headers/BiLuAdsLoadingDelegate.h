//
//  BiLuAdsLoadingDelegate.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BiLuAdsLoadingDelegate <NSObject>

/**
 广告加载完成

 @param placementId 广告位Id
 */
- (void)didFinishLoadingADWithPlacementId:(NSString *)placementId;


/**
 广告加载失败

 @param placementId 广告位Id
 @param error 错误信息
 */
- (void)didFailToLoadADWithPlacementId:(NSString*)placementId error:(NSError*)error;

@end


