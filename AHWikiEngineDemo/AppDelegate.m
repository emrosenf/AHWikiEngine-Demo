//
//  AppDelegate.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/18/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "AppDelegate.h"
#import <AHWikiEngine/AHWikiEngine.h>
#import "WoWWikiConfiguration.h"
@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    //[AHWikiEngine start];
    [AHWikiEngine startWithConfiguration:[WoWWikiConfiguration new]];
    // Override point for customization after application launch.
    return YES;
}

@end
