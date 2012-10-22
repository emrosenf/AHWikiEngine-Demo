//
//  CustomCSSWikiConfiguration.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/21/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "CustomCSSWikiConfiguration.h"

@implementation CustomCSSWikiConfiguration

- (id)init {
    self = [super init];
    if (self) {
        self.cssFilename = @"custom.css";
    }
    return self;
}

@end
