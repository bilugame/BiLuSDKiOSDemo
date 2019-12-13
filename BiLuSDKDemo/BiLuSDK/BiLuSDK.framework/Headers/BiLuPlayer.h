//
//  BiLuPlayer.h
//  BiLuSDKDevDemo
//
//  Created by 李加建 on 2019/11/5.
//  Copyright © 2019 mobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class BiLuPlayer;

typedef void(^AuthenticateHandler)(BiLuPlayer *player , NSError *error);

@interface BiLuPlayer : NSObject
/// 用户昵称
@property(nonatomic, copy) NSString *alias;
/// 用户id
@property(nonatomic, copy) NSString *playerID;
//登录注册回调消息（带注册界面的SDK初始化使用，其他忽略）
@property(nonatomic, copy) NSString *registerCode;
@end

NS_ASSUME_NONNULL_END
