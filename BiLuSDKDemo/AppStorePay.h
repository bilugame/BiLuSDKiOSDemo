//
//  AppStorePay.h
//  TSTSShareSDK
//
//  Created by 李加建 on 2019/11/6.
//  Copyright © 2019 mobile. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppStorePay : NSObject

@property (nonatomic ,strong)NSMutableDictionary * dict;

@property (nonatomic ,copy)NSString * payid;
@property (nonatomic ,copy)void (^update)(NSDictionary *dict);
@property (nonatomic ,copy)void (^verpay)(void);

+ (instancetype)manager;

- (void)payment;

@end

NS_ASSUME_NONNULL_END
