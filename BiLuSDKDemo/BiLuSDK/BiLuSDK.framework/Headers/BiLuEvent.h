//
//  BiLuEvent.h
//  BiLuSDKDevDemo
//
//  Created by AJL on 2019/10/30.
//  Copyright © 2019 mobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BiLuEvent : NSObject

/// 自定义事件
/// @param eventId 事件ID    类型:NSString
/// @param eventData 事件参数   类型:键值对(key只支持NSString, value支持NSString和NSNumber)
+ (void)onbiLuEvent:(NSString *)eventId eventData:(NSDictionary *)eventData;
@end

NS_ASSUME_NONNULL_END
