//
//  AHIOSWebController.h
//  Wiki
//
//  Created by Evan Rosenfeld on 10/13/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AHWebController.h"
#import "AHArticleController.h"

@class AHGalleryViewController;

/** AHWebController implementation for iOS */
@interface AHIOSWebController : NSObject<AHWebController, UIWebViewDelegate>


/** The AHGalleryViewController instance to be used as the image gallery */
- (AHGalleryViewController *) gallery;

/** Weak reference to the AHArticleController instance */
@property (nonatomic, weak) AHArticleController *articleController;

@end
