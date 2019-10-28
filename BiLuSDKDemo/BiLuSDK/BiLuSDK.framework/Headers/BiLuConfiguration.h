//
//  BiLuConfiguration.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/8.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface BiLuConfiguration : NSObject

@property (nonatomic ,copy)NSString * QQAppID;
@property (nonatomic ,copy)NSString * QQAppKey;
@property (nonatomic ,copy)NSString * WXAppID;
@property (nonatomic ,copy)NSString * WXAppKey;
/// 默认App Store
@property (nonatomic ,copy)NSString * channelID;
/// 默认iOS
@property (nonatomic ,copy)NSString * sdkType;


+ (instancetype)configuration;

@end


