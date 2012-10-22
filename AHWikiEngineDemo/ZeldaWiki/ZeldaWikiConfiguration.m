//
//  PlantWikiConfiguration.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/21/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "ZeldaWikiConfiguration.h"

@implementation ZeldaWikiConfiguration

- (id)init {
    self = [super init];
    if (self) {
        self.domain = @"zeldawiki.org";
        self.articlePath = @"";
    }
    return self;
}

- (NSString *)hostForSubdomain:(NSString*)subdomain {
    return [NSString stringWithFormat:@"http://www.%@", self.domain];
}
@end
