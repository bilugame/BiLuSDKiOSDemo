//
//  BiLuVirtualCurrency.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/29.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BiLuVirtualCurrency : NSObject

/**
*    @method    onChargeRequst          虚拟币充值请求
*    @param     orderId                 订单id        类型:NSString
*    @param     iapId                   充值包id      类型:NSString
*    @param     currencyAmount          现金金额      类型:double
*    @param     currencyType            币种          类型:NSString
*    @param     virtualCurrencyAmount   虚拟币金额    类型:double
*    @param     paymentType             支付类型      类型:NSString
*/
+ (void)onChargeRequst:(NSString *)orderId
                 iapId:(NSString *)iapId
        currencyAmount:(double)currencyAmount
          currencyType:(NSString *)currencyType
 virtualCurrencyAmount:(double)virtualCurrencyAmount
           paymentType:(NSString *)paymentType;


/**
*    @method    onChargeRequst          虚拟币充值请求
*    @param     orderId                 订单id        类型:NSString
*/
+ (void)onChargeSuccess:(NSString *)orderId ;


/// AppStore 内购二次验证
/// @param response 二次验证 返回block
+ (void)appStoreReceipt:(void (^)(NSDictionary *json , NSError * error))response;

@end

NS_ASSUME_NONNULL_END
