//
//  CustomArticleController.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/20/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "CustomArticleController.h"

@implementation CustomArticleController

- (NSArray*) imagesForArticle:(NSDictionary *)article {
    return article[@"images"];
}

@end
