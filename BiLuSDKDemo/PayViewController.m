//
//  PayViewController.m
//  BiLuSDKDevDemo
//
//  Created by 李加建 on 2019/11/1.
//  Copyright © 2019 mobile. All rights reserved.
//

#import "PayViewController.h"

#import <BiLuSDK/BiLuVirtualCurrency.h>
#import "AppStorePay.h"


@interface PayViewController ()

@property (nonatomic ,strong)UITextField * tf1;
@property (nonatomic ,strong)UITextField * tf2;
@property (nonatomic ,strong)UITextField * tf3;
@property (nonatomic ,strong)UITextField * tf4;
@property (nonatomic ,strong)UITextField * tf5;
@property (nonatomic ,strong)UITextField * tf6;

@end

@implementation PayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    self.view.backgroundColor = [UIColor whiteColor];

    [self creatView];
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/


- (void)backBtnAction {

    [self dismissViewControllerAnimated:YES completion:nil];

}


- (void)creatView {

    UIButton * btn = [[UIButton alloc]initWithFrame:CGRectMake(10, 33, 60, 40)];
    btn.backgroundColor = [UIColor redColor];
    [btn setTitle:@"返回" forState:UIControlStateNormal];
    [self.view addSubview:btn];
    [btn addTarget:self action:@selector(backBtnAction) forControlEvents:UIControlEventTouchUpInside];


    [self creatList];
}



- (void)creatList {



    _tf1 = [[UITextField alloc]init];
    [self.view addSubview:_tf1];

    _tf2 = [[UITextField alloc]init];
    [self.view addSubview:_tf2];

    _tf3 = [[UITextField alloc]init];
    [self.view addSubview:_tf3];

    _tf4 = [[UITextField alloc]init];
    [self.view addSubview:_tf4];

    _tf5 = [[UITextField alloc]init];
    [self.view addSubview:_tf5];

    _tf6 = [[UITextField alloc]init];
    [self.view addSubview:_tf6];

    CGFloat w = 300;
    CGFloat h = 44;

    _tf1.frame = CGRectMake(15, 100, w, h);
    _tf2.frame = CGRectMake(15, CGRectGetMaxY(_tf1.frame) + 10, w, h);
    _tf3.frame = CGRectMake(15, CGRectGetMaxY(_tf2.frame) + 10, w, h);
    _tf4.frame = CGRectMake(15, CGRectGetMaxY(_tf3.frame) + 10, w, h);
    _tf5.frame = CGRectMake(15, CGRectGetMaxY(_tf4.frame) + 10, w, h);
    _tf6.frame = CGRectMake(15, CGRectGetMaxY(_tf5.frame) + 10, w, h);


    _tf1.placeholder = @"orderId 订单id 或者 AppStore 支付ID";
    _tf2.placeholder = @"iapId  充值包id  ";
    _tf3.placeholder = @"currencyAmount  现金金额 ";
    _tf4.placeholder = @"currencyType   币种 ";
    _tf5.placeholder = @"virtualCurrencyAmount 虚拟币金额 ";
    _tf6.placeholder = @"paymentType  支付类型 ";

    UIColor * color = [UIColor colorWithRed:0.93 green:0.93 blue:0.93 alpha:1];

    _tf1.backgroundColor = color;
    _tf2.backgroundColor = color;
    _tf3.backgroundColor = color;
    _tf4.backgroundColor = color;
    _tf5.backgroundColor = color;
    _tf6.backgroundColor = color;


    UIButton * btn = [[UIButton alloc]initWithFrame:CGRectMake(15, CGRectGetMaxY(_tf6.frame) + 30, 70, 40)];
    btn.backgroundColor = [UIColor redColor];
    [btn setTitle:@"确定" forState:UIControlStateNormal];
    [self.view addSubview:btn];
    [btn addTarget:self action:@selector(onChargeRequst) forControlEvents:UIControlEventTouchUpInside];

    UIButton * btn2 = [[UIButton alloc]initWithFrame:CGRectMake(100, CGRectGetMaxY(_tf6.frame) + 30, 70, 40)];
    btn2.backgroundColor = [UIColor redColor];
    [btn2 setTitle:@"完成" forState:UIControlStateNormal];
    [self.view addSubview:btn2];
    [btn2 addTarget:self action:@selector(onChargeSuccess) forControlEvents:UIControlEventTouchUpInside];

    UIButton * btn4 = [[UIButton alloc]initWithFrame:CGRectMake(180, CGRectGetMaxY(_tf6.frame) + 30, 70, 40)];
    btn4.backgroundColor = [UIColor redColor];
    [btn4 setTitle:@"内购" forState:UIControlStateNormal];
    [self.view addSubview:btn4];
    [btn4 addTarget:self action:@selector(IAPBtnAction) forControlEvents:UIControlEventTouchUpInside];
}


- (void)IAPBtnAction {

    AppStorePay *pay = [AppStorePay manager];
    pay.payid = _tf1.text;

    pay.verpay = ^{

        [BiLuVirtualCurrency appStoreReceipt:^(NSDictionary * _Nonnull json, NSError * _Nonnull error) {

            NSLog(@"%@",json);
        }];
    };


    NSLog(@"touch");


}


- (void)onChargeRequst {


    [BiLuVirtualCurrency onChargeRequst:_tf1.text
                                  iapId:_tf2.text
                         currencyAmount:[_tf3.text floatValue]
                           currencyType:_tf4.text
                  virtualCurrencyAmount:[_tf5.text floatValue]
                            paymentType:_tf6.text];
}

- (void)onChargeSuccess {


    [BiLuVirtualCurrency onChargeSuccess:_tf1.text];
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {

    [self.view endEditing:YES];
}

@end
