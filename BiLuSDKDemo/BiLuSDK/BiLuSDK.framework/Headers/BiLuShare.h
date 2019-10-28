//
//  BiLuShare.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BiLuConfiguration.h"

typedef NS_ENUM(NSInteger, BiLuShareScene) {
    /// QQ好友
    BiLuShareSceneQQ = 0,
    /// QQ空间
    BiLuShareSceneQZone,
    /// 微信聊天界面
    BiLuShareSceneWXSession,
    /// 微信朋友圈
    BiLuShareSceneWXTimeline
};

//分享结果
typedef NS_ENUM(NSUInteger, BiLuShareResponse){
    BiLuShareResponseSuccess = 0,
    BiLuShareResponseFail,
    BiLuShareResponseCancel,
    BiLuShareResponseParameterFail
};


/**
 分享回调block
 error 错误信息
 start 分享结果
 */
typedef void(^BiLuShareBlock)(NSError * error, BiLuShareResponse resp);


@interface BiLuShare : NSObject


/**
 带UI分享
 respBlock 分享结果
 */
+ (void)shareWithUIRespBlock:(BiLuShareBlock)respBlock;

/**
 自定义UI分享
 scene 分享场景
 respBlock 分享结果
 */
+ (void)shareWithScene:(BiLuShareScene)scene
             respBlock:(BiLuShareBlock)respBlock;

/**
 自定义UI分享，自定义内容
 scene 分享场景
 param 自定义参数
 respBlock 分享结果
 */
+ (void)shareWithScene:(BiLuShareScene)scene
                 param:(NSString*)param
             respBlock:(BiLuShareBlock)respBlock;

@end


