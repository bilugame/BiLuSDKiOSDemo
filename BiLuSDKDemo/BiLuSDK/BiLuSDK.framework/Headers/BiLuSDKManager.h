//
//  BiLuSDKManager.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/11.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "BiLuConfiguration.h"
#import "BiLuPlayer.h"


@interface BiLuSDKManager : NSObject

@property (nonatomic ,strong)BiLuConfiguration * configuration;
@property (nonatomic ,copy ,readonly)NSString * appID;
@property (nonatomic ,copy ,readonly)NSString * appKey;
/* 是否注册成功 */
@property (nonatomic ,assign ,readonly)BOOL isReg;

+ (instancetype)sharedInstance;


/**
 统计日志开关（可选）

 @param enable 默认是开启状态
 */
+ (void)setLogEnabled:(BOOL)enable;


/**
 SDK 版本信息

 @return 版本字符串
 */
+ (NSString *)SDKVersion;


/**
 注册SDK

 @param appID 应用id
 @param appKey 应用key
 @param configuration 配置信息
 */
+ (void)registerWithAppID:(NSString *)appID
                   appKey:(NSString *)appKey
                   configuration:(BiLuConfiguration *)configuration;



/// 带用户系统的 SDK注册
/// @param appID 应用id
/// @param appKey 应用key
/// @param configuration 配置信息
/// @param block 用户注册生成用户回调
+ (void)registerWithAppID:(NSString *)appID
                   appKey:(NSString *)appKey
            configuration:(BiLuConfiguration *)configuration
                    block:(AuthenticateHandler)block;



/// 带登录界面的SDK注册
/// @param appID 应用id
/// @param appKey 应用key
/// @param configuration 配置信息
/// @param block 用户注册生成用户回调
+ (void)registerViewWithAppID:(NSString *)appID
       appKey:(NSString *)appKey
configuration:(BiLuConfiguration *)configuration
        block:(AuthenticateHandler)block;


// 用户唯一字符串
+ (NSString *)getBilu_UUID ;

//设备唯一内部标志
+ (NSString *)getBilu_BLID ;


@end


