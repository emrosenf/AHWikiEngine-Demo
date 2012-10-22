//
//  CustomWikiConfiguration.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/20/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "WoWWikiConfiguration.h"
@implementation WoWWikiConfiguration

- (id)init {
    self = [super init];
    if (self) {
        self.domain = @"wowpedia.org";
        self.articlePath = @"";
    }
    return self;
} 

- (NSString *)hostForSubdomain:(NSString*)subdomain {
    return [NSString stringWithFormat:@"http://www.%@", self.domain];
}


@end
