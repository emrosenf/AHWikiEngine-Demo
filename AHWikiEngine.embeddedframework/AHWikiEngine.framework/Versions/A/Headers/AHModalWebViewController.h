//
//  AHModalWebViewController.h
//  AHWikiEngine
//
//  Created by Evan Rosenfeld on 10/15/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "AHWebViewController.h"

/** UINavigationController subclass that wraps a UIViewController with a UIWebView for loading tables or other pages */
@interface AHModalWebViewController : UINavigationController


/** Initialize with URL
 @param URL The URL as an NSURL *
 @return The initialized AHModalWebViewController
 */
- (id)initWithURL:(NSURL *)URL;

/** The underlying view controller subclass */
@property (nonatomic, strong) AHWebViewController *webViewController;

@end
