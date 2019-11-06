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

@end

NS_ASSUME_NONNULL_END
