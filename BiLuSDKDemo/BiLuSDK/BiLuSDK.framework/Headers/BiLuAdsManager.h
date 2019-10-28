//
//  BiLuAdsManager.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BiLuAdsLoadingDelegate.h"

//广告类型
typedef NS_ENUM(NSUInteger, BiLuAdsType){
    BiLuAdsTypeBanner = 0,     //Banner广告
    BiLuAdsTypeInterstitial,   //插屏广告
    BiLuAdsTypeRewardedVideo   //激励视频
};

//附加信息设置广告尺寸大小Key
extern NSString *const kExtraInfoAdSizeKey;

@interface BiLuAdsManager : NSObject

@property(assign, nonatomic) BiLuAdsType type;

@property(nonatomic, strong) NSDictionary *extra;


/**
 获取BiLuAdsManager单例
 
 @return 返回BiLuAdsManager对象
 */
+ (instancetype)sharedInstance;


/**
 广告加载信息

 @param placementId 广告位Id
 @param extra 附加信息
 @param type 广告类型
 @param delegate 回调代理
 */
- (void)loadADWithPlacementId:(NSString *)placementId
                        extra:(NSDictionary *)extra
                         type:(BiLuAdsType )type
                     delegate:(id<BiLuAdsLoadingDelegate>)delegate;

/**
 广告清除缓存
 */
- (void)clearCache;

@end


