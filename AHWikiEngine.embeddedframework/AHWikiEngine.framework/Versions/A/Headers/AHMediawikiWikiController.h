//
//  AHWikimediaWikiDelegate.h
//  Wiki
//
//  Created by Evan Rosenfeld on 10/14/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AHWikiController.h"
#import "AHArticleController.h"

/** Implementation of the AHWikiController protocol for Mediawiki sites */
@interface AHMediawikiWikiController : NSObject<AHWikiController>

/** Weak reference to the linked AHArticleController implementation */
@property (nonatomic, unsafe_unretained) NSObject<AHArticleController> *articleController;

@end
