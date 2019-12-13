//
//  AppDelegate.m
//  BiLuSDKDemo
//
//  Created by 李加建 on 2019/10/12.
//  Copyright © 2019 mobile. All rights reserved.
//

#import "AppDelegate.h"

#import <BiLuSDK/BiLuSDK.h>
#import "ViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    ViewController * root = [[ViewController alloc]init];
    self.window.rootViewController = root;
    [self.window makeKeyAndVisible];

    BiLuConfiguration *configuration = [BiLuConfiguration configuration];

    configuration.WXAppID = @"wx1c7767afcfc969e9";
    configuration.WXAppKey = @"c7253e5289986cf4c4c74d1ccc185fb1";
    configuration.QQAppID = @"1108231232";
    configuration.QQAppKey = @"aed9b0303e3ed1e27bae87c33761161d";

//测试服
//    [BiLuSDKManager registerWithAppID:@"e4da3b7fbbce2345" appKey:@"9046e6e901fc87a3e6faec3907d07805" configuration:configuration];

    //正式服
//    [BiLuSDKManager registerWithAppID:@"66c7c15dacf008d8" appKey:@"7794001eb60d202c705e0dd3dda6b819" configuration:configuration];
//
    [BiLuSDKManager registerViewWithAppID:@"66c7c15dacf008d8" appKey:@"7794001eb60d202c705e0dd3dda6b819" configuration:configuration block:^(BiLuPlayer * _Nonnull player, NSError * _Nonnull error) {

    }];

    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
