//
//  ViewController.m
//  BiLuSDKDemo
//
//  Created by 李加建 on 2019/10/12.
//  Copyright © 2019 mobile. All rights reserved.
//

#import "ViewController.h"

#define BIScreenWidth       [UIScreen mainScreen].bounds.size.width

#define BIScreenHeight      [UIScreen mainScreen].bounds.size.height

#define BIScreenBounds      [UIScreen mainScreen].bounds

#define BIWeakSelf          __weak __typeof(self) weakSelf = self;

#define BIBottomBarHeight   (BIScreenHeight >= 812.0 ? 34 : 0)

#define BILog(msg,obj) NSLog(@"\n---------------BILU-----------------\n\n\n%@:%@\n\n\n------------------------------------",msg,obj)

#define BIMsgLog(msg) NSLog(@"\n---------------BILU-----------------\n\n\n%@\n\n\n------------------------------------",msg)


#import <BiLuSDK/BiLuSDK.h>

@interface ViewController ()

<BiLuAdsLoadingDelegate,BiLuAdsRewardedVideoDelegate,BiLuAdsInterstitialDelegate,BiLuAdsBannerDelegate>

//加载控件
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

@end

@implementation ViewController

- (void)viewDidLoad {

    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    [self creatBtns];
    [self.view addSubview:self.activityIndicator];
}

- (void)creatBtns {

    NSArray * array = @[@"分享",@"加载Banner",@"加载激励视频",@"加载插屏",@"显示Banner",@"显示激励视频",@"显示插屏"];
    CGFloat w = UIScreen.mainScreen.bounds.size.width;
    CGFloat x = (w - 150)/2;

    for(int i = 0; i<array.count; i++){
        NSString * title = array[i];
        UIButton * btn = [[UIButton alloc]initWithFrame:CGRectMake(x, 64 + 70*i, 150, 44)];
        btn.backgroundColor = [UIColor redColor];
        [btn setTitle:title forState:UIControlStateNormal];
        btn.tag = 2000+i;
        [self.view addSubview:btn];
        [btn addTarget:self action:@selector(btnAction:) forControlEvents:UIControlEventTouchUpInside];
    }
    
}

- (void)btnAction:(UIButton*)btn {

    NSInteger tag = btn.tag - 2000;

    if(tag == 0){

        [BiLuShare shareWithUIRespBlock:^(NSError *error, BiLuShareResponse state) {

            NSLog(@"%@",error.userInfo);

        }];

        return;
    }

    [self.activityIndicator startAnimating];

    if (tag == 1){
        [self loadBanner:btn];
    }else if (tag == 2){
        [self loadRewarded:btn];
    }else if (tag == 3){
        [self loadInter:btn];
    }else if (tag == 4){
        [self showBanner:btn];
    }else if (tag == 5){
        [self showRewarded:btn];
    }else if (tag == 6){
        [self showInter:btn];
    }else if (tag == 7){
        [self.activityIndicator stopAnimating];
        [[BiLuAdsManager sharedInstance] clearCache];
        [self showAlertMessage:[NSString stringWithFormat:@"清除所有广告缓存"]];
    }

}

- (void)loadBanner:(UIButton *)sender {

    CGFloat with = BIScreenWidth;
    [[BiLuAdsManager sharedInstance] loadADWithPlacementId:@"b5d9c296b43454" extra:@{kUPArpuAdLoadingExtraBannerAdSizeKey:[NSValue valueWithCGSize:CGSizeMake(with, with/6.4)]} type:BiLuAdsTypeBanner delegate:self];

}

- (void)loadRewarded:(UIButton *)sender {

    [[BiLuAdsManager sharedInstance] loadADWithPlacementId:@"b5d9c299664ad2" extra:@{} type:BiLuAdsTypeRewardedVideo delegate:self];

}

- (void)loadInter:(UIButton *)sender {

    [[BiLuAdsManager sharedInstance] loadADWithPlacementId:@"b5d9c29a079a32" extra:@{} type:BiLuAdsTypeInterstitial delegate:self];

}

- (void)showBanner:(UIButton *)sender {

    if ([[BiLuAdsManager sharedInstance] bannerAdReadyForPlacementId:@"b5d9c296b43454"]) {
        [self showBanner];
    }else{
        [self.activityIndicator stopAnimating];
        [self showAlertMessage:[NSString stringWithFormat:@"Banner广告已显示过了，点击加载Banner获取新的广告"]];
    }
}

- (void)showBanner{

    NSInteger tag = 3333;

    [[self.view viewWithTag:tag] removeFromSuperview];

    UPArpuBannerView *bannerView = [[BiLuAdsManager sharedInstance] retrieveBannerViewForPlacementId:@"b5d9c296b43454" delegate:self];
    bannerView.translatesAutoresizingMaskIntoConstraints = NO;
    bannerView.tag = tag;
    [self.view addSubview:bannerView];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:self.view attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:bannerView attribute:NSLayoutAttributeBottom multiplier:1.0f constant:BIBottomBarHeight]];
    //    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:bannerView attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeWidth multiplier:1.0f constant:self.view.frame.size.width]];
    //    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:bannerView attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeWidth multiplier:1.0f constant:64.0f]];
}

- (void)showRewarded:(UIButton *)sender {

    if ([[BiLuAdsManager sharedInstance] rewardedVideoReadyForPlacementId:@"b5d9c299664ad2"]) {
        [[BiLuAdsManager sharedInstance] showRewardedVideoWithPlacementId:@"b5d9c299664ad2" inViewController:self delegate:self];
    }else{
        [self.activityIndicator stopAnimating];
        [self showAlertMessage:[NSString stringWithFormat:@"激励视频广告已显示过了，点击加载激励视频获取新的广告"]];
    }
}

- (void)showInter:(UIButton *)sender {

    if ([[BiLuAdsManager sharedInstance] interstitialReadyForPlacementId:@"b5d9c29a079a32"]) {
        [[BiLuAdsManager sharedInstance] showInterstitialWithPlacementId:@"b5d9c29a079a32" inViewController:self delegate:self];
    }else{
        [self.activityIndicator stopAnimating];
        [self showAlertMessage:[NSString stringWithFormat:@"插屏广告已显示过了，点击加载插屏获取新的广告"]];
    }
}

#pragma mark - BiluAdLoadingDelegate

- (void)didFinishLoadingADWithPlacementId:(NSString *)placementId{

    [self showAlertMessage:[NSString stringWithFormat:@"加载广告成功\nPlacementId:%@",placementId]];
    [self.activityIndicator stopAnimating];
    BILog(@"广告加载成功 PlacementId",placementId);
}

- (void)didFailToLoadADWithPlacementId:(NSString*)placementId error:(NSError*)error{

    [self showAlertMessage:[NSString stringWithFormat:@"加载广告失败\nPlacementId:%@\nerror:%@",placementId,error]];
    [self.activityIndicator stopAnimating];
    NSLog(@"广告加载失败 PlacementId：%@ error:%@",placementId,error);
}

#pragma mark - BiluAdBannerDelegate

- (void)bannerView:(UPArpuBannerView *)bannerView didShowAdWithPlacementId:(NSString *)placementId{

    [self.activityIndicator stopAnimating];
    [self showAlertMessage:[NSString stringWithFormat:@"显示Banner成功 PlacementId:%@",placementId]];
    BILog(@"bannerView didShowAdWithPlacementId",placementId);
}
- (void)bannerView:(UPArpuBannerView *)bannerView didClickWithPlacementId:(NSString *)placementId{

    [self.activityIndicator stopAnimating];
    BILog(@"bannerView didClickWithPlacementId",placementId);
}
- (void)bannerView:(UPArpuBannerView *)bannerView didCloseWithPlacementId:(NSString *)placementId{

    [self.activityIndicator stopAnimating];
    BILog(@"bannerView didCloseWithPlacementId",placementId);
}
- (void)bannerView:(UPArpuBannerView *)bannerView didAutoRefreshWithPlacementId:(NSString *)placementId{

    [self.activityIndicator stopAnimating];
    BILog(@"bannerView didAutoRefreshWithPlacementId",placementId);
}
- (void)bannerView:(UPArpuBannerView *)bannerView failedToAutoRefreshWithPlacementId:(NSString *)placementId error:(NSError*)error{

    [self.activityIndicator stopAnimating];
    NSLog(@"bannerView failedToAutoRefreshWithPlacementId：%@ error：%@",placementId,error);
}

#pragma mark - BiluAdRewardedVideoDelegate

- (void)rewardedVideoDidStartPlayingForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    //    [self showAlertMessage:[NSString stringWithFormat:@"播放激励视频广告成功 PlacementId:%@",placementId]];
    NSLog(@"rewardedVideoDidStartPlayingForPlacementId：%@ extra：%@",placementId,extra);
}
- (void)rewardedVideoDidEndPlayingForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"rewardedVideoDidEndPlayingForPlacementId：%@ extra：%@",placementId,extra);
}
- (void)rewardedVideoDidFailToPlayForPlacementId:(NSString *)placementId error:(NSError *)error extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    [self showAlertMessage:[NSString stringWithFormat:@"播放激励视频广告失败\nPlacementId:%@\nerror:%@\nextra:%@",placementId,error,extra]];
    NSLog(@"rewardedVideoDidFailToPlayForPlacementId：%@ error：%@ extra：%@",placementId,error,extra);
}
- (void)rewardedVideoDidCloseForPlacementId:(NSString *)placementId rewarded:(BOOL)rewarded extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"rewardedVideoDidCloseForPlacementId：%@ rewarded：%d extra：%@",placementId,rewarded,extra);
}
- (void)rewardedVideoDidClickForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"rewardedVideoDidClickForPlacementId：%@ extra：%@",placementId,extra);
}

#pragma mark - BiluAdInterstitialDelegate

- (void)interstitialDidShowForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"interstitialDidShowForPlacementId：%@ extra：%@",placementId,extra);
}
- (void)interstitialFailedToShowForPlacementId:(NSString *)placementId error:(NSError *)error extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    [self showAlertMessage:[NSString stringWithFormat:@"显示插屏广告失败\nPlacementId:%@\nerror:%@\nextra:%@",placementId,error,extra]];
    NSLog(@"interstitialFailedToShowForPlacementId：%@ error：%@ extra：%@",placementId,error,extra);
}
- (void)interstitialDidStartPlayingVideoForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"interstitialDidStartPlayingVideoForPlacementId：%@ extra：%@",placementId,extra);
}
- (void)interstitialDidEndPlayingVideoForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"interstitialDidEndPlayingVideoForPlacementId：%@ extra：%@",placementId,extra);
}
- (void)interstitialDidFailToPlayVideoForPlacementId:(NSString *)placementId error:(NSError *)error extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"interstitialDidFailToPlayVideoForPlacementId：%@ error：%@ extra：%@",placementId,error,extra);
}
- (void)interstitialDidCloseForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"interstitialDidCloseForPlacementId：%@ extra：%@",placementId,extra);
}
- (void)interstitialDidClickForPlacementId:(NSString *)placementId extra:(NSDictionary *)extra{

    [self.activityIndicator stopAnimating];
    NSLog(@"interstitialDidClickForPlacementId：%@ extra：%@",placementId,extra);
}

- (UIActivityIndicatorView *)activityIndicator{

    if (!_activityIndicator) {
        _activityIndicator = [[UIActivityIndicatorView alloc]initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        //设置小菊花的frame
        _activityIndicator.frame= CGRectMake((BIScreenWidth-100)*0.5, (BIScreenHeight-100)*0.5, 100, 100);
        //设置小菊花颜色
        _activityIndicator.color = [UIColor blackColor];
        //设置背景颜色
        _activityIndicator.backgroundColor = [UIColor clearColor];
        //刚进入这个界面会显示控件，并且停止旋转也会显示，只是没有在转动而已，没有设置或者设置为YES的时候，刚进入页面不会显示
        //        _activityIndicator.hidesWhenStopped = NO;
    }
    return _activityIndicator;
}

- (void)showAlertMessage:(NSString *)message {

    BIWeakSelf
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction* action = [UIAlertAction
                             actionWithTitle:@"取消" style:UIAlertActionStyleDefault
                             handler:^(UIAlertAction * _Nonnull action) {
                                 [weakSelf dismissViewControllerAnimated:YES completion:nil];
                                 [weakSelf.activityIndicator stopAnimating];
                             }];
    [alertController addAction:action];
    [self presentViewController:alertController
                       animated:YES completion:nil];
}


@end
