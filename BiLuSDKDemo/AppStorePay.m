//
//  AppStorePay.m
//  TSTSShareSDK
//
//  Created by 李加建 on 2019/11/6.
//  Copyright © 2019 mobile. All rights reserved.
//

#import "AppStorePay.h"

#import <StoreKit/StoreKit.h>

@interface AppStorePay ()
<SKProductsRequestDelegate,SKPaymentTransactionObserver>
@end

@implementation AppStorePay


+ (instancetype)manager {
    static AppStorePay *instance = nil;
    static dispatch_once_t oneToken;
    dispatch_once(&oneToken,^{
        instance = [[[self class] alloc] init];
    });
    return instance;
}

- (void)payment {

    _dict = [NSMutableDictionary dictionary];

    [[SKPaymentQueue defaultQueue] addTransactionObserver:self];


    if(_payid == nil){
        _payid = @"";
    }


    SKProductsRequest * req = [[SKProductsRequest alloc]initWithProductIdentifiers:[NSSet setWithArray:@[_payid]]];
    req.delegate = self;
    [req start];

    _dict[@"1"] = @"请求商品";
    if(self.update != nil){
        self.update(self.dict);
    }
}

- (void)productsRequest:(nonnull SKProductsRequest *)request didReceiveResponse:(nonnull SKProductsResponse *)response {

    NSArray *product = response.products;

    if(product.count > 0){

        SKProduct * pro = product[0];

        SKPayment *payment = [SKPayment paymentWithProduct:pro];
        NSLog(@"发送购买请求");
        _dict[@"2"] = @"发送购买请求";
        dispatch_sync(dispatch_get_main_queue(), ^{

            if(self.update != nil){
                self.update(self.dict);
            }
        });
        [[SKPaymentQueue defaultQueue] addPayment:payment];
    }

}




- (void)paymentQueue:(nonnull SKPaymentQueue *)queue updatedTransactions:(nonnull NSArray<SKPaymentTransaction *> *)transactions {

    for(SKPaymentTransaction *tran in transactions){

        NSString * text = @"";
        switch(tran.transactionState) {


            case SKPaymentTransactionStatePurchased:{
                NSLog(@"交易完成");

                text = @"交易完成";

                [self verifyPurchaseWithPaymentTransaction:tran];
            }
                break;
            case SKPaymentTransactionStatePurchasing:
                NSLog(@"商品添加进列表");
                text = @"商品添加进列表";
                break;
            case SKPaymentTransactionStateRestored:{

                NSLog(@"已经购买过该商品");
                text = @"已经购买过该商品";
                [self verifyPurchaseWithPaymentTransaction:tran];
//                [[SKPaymentQueue defaultQueue] finishTransaction:tran];
            }
                break;
            case SKPaymentTransactionStateFailed:{
                NSLog(@"交易失败");
                text = @"交易失败";
                [[SKPaymentQueue defaultQueue] finishTransaction:tran];

            }
                break;
            default:
                break;
        }
        NSString * key = [NSString stringWithFormat:@"3+%@",@(tran.transactionState)];
        _dict[key] = text;
        if(self.update != nil){
            self.update(self.dict);
        }
    }
}

- (void)verifyPurchaseWithPaymentTransaction:(SKPaymentTransaction*)tran{

    [[SKPaymentQueue defaultQueue] finishTransaction:tran];


    if(_verpay != nil){
        _verpay();
    }

}


- (void)verPay {

    //从沙盒中获取交易凭证并且拼接成请求体数据
        NSURL *receiptUrl = [[NSBundle mainBundle] appStoreReceiptURL];
        NSData *receiptData = [NSData dataWithContentsOfURL:receiptUrl];

    //    sandboxReceipt

        [receiptUrl.absoluteString containsString:@"sandboxReceipt"];

        if(receiptData == nil){
            return;
        }


    //    NSString *encodeStr = [receiptData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
    //
    //    NSString *baseString = [[NSString alloc]initWithData:base64Data encoding:NSUTF8StringEncoding];


        NSString * ss = @"";
        self.dict[@"4"] = ss;
        if(self.update != nil){
            self.update(self.dict);
        }

        [self post22222:receiptData];

    //    NSString *encodeStr = [receiptData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
    //    [self post:encodeStr];
}


- (void)post:(NSString*)receipt {

    self.dict[@"4"] = receipt;
    if(self.update != nil){
        self.update(self.dict);
    }

    NSString *payload = [NSString stringWithFormat:@"{\"receipt-data\" : \"%@\"}", receipt];

    NSData *payloadData = [payload dataUsingEncoding:NSUTF8StringEncoding];

    NSURL *url = [NSURL URLWithString:@"https://sandbox.itunes.apple.com/verifyReceipt"];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];

    request.HTTPMethod = @"POST";
    request.HTTPBody = payloadData;

    NSURLSession *session = [NSURLSession sharedSession];
    // 由于要先对request先行处理,我们通过request初始化task
    NSURLSessionTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {

        NSLog(@"%@", [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil]);

        NSDictionary * json = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];

        self.dict[@"5"] = json;

        dispatch_sync(dispatch_get_main_queue(), ^{

            if(self.update != nil){
                self.update(self.dict);
            }
        });


    }];


    [task resume];
}



- (void)post22222:(NSData*)receiptData {

    if(receiptData == nil){
        return;
    }

    NSMutableData * mtdata = [NSMutableData data];
    [mtdata appendData:[@"apple_receipt=" dataUsingEncoding:NSUTF8StringEncoding]];
    [mtdata appendData:receiptData];
    [mtdata appendData:[@"&sandbox=1" dataUsingEncoding:NSUTF8StringEncoding]];

    NSString *encodeStr = [receiptData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];

    encodeStr = [encodeStr stringByReplacingOccurrencesOfString:@"+" withString:@"%2B"];

    encodeStr = [encodeStr stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];

    NSString * payload = [NSString stringWithFormat:@"apple_receipt=%@&sandbox=1",encodeStr];


    NSURL *url = [NSURL URLWithString:@"http://test.bilu.com/v1/web/verify_apple_receipt"];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];

    request.HTTPMethod = @"POST";
    request.HTTPBody = [payload dataUsingEncoding:NSUTF8StringEncoding];;


    NSURLSession *session = [NSURLSession sharedSession];
    // 由于要先对request先行处理,我们通过request初始化task
    NSURLSessionTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {

        NSLog(@"%@", [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil]);

        NSString * ss = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];

        self.dict[@"5"] = ss;

        dispatch_sync(dispatch_get_main_queue(), ^{

            if(self.update != nil){
                self.update(self.dict);
            }
        });

    }];


    [task resume];
}

@end
