//
//  BiLuVirtualCurrency.h
//  BiLuSDKDevDemo
//
//  Created by ALLW on 2019/10/29.
//  Copyright © 2019 bilu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger,BiLuIAPResultType) {
    BiLuIAPResultSuccess = 0,       // 购买成功
    BiLuIAPResultFailed = 1,        // 购买失败
    BiLuIAPResultCancle = 2,        // 取消购买
    BiLuIAPResultVerFailed = 3,     // 订单校验失败
    BiLuIAPResultVerSuccess = 4,    // 订单校验成功
    BiLuIAPResultNotArrow = 5,      // 不允许内购
    BiLuIAPResultIDError = 6,       // 项目ID错误或不存在此项目
};

typedef void(^BiLuIAPCompletionHandle)(BiLuIAPResultType type, NSDictionary *data);


@interface BiLuVirtualCurrency : NSObject

/**
 单例模式

 @return BiLuVirtualCurrency
 */
+ (instancetype)shareIAPManager;


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


#pragma mark - 苹果内购调用
/// AppStore 内购（带二次验证回调）
/// @param productID 内购项目的产品ID
/// @param trackingcode  自定义追踪码（可放置需要绑定回调的数据）
/// @param type YES返回全部订单，NO返回当前商品订单（默认返回全部订单）
/// @param handle 内购的结果及二次验证回调
- (void)startIAPWithProductID:(NSString *)productID trackingcode:(NSDictionary *)trackingcode  type:(BOOL)type completeHandle: (BiLuIAPCompletionHandle)handle;
@end

NS_ASSUME_NONNULL_END
