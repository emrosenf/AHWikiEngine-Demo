//
//  AHWebViewController.h
//  AHWikiEngine
//
//  Created by Evan Rosenfeld on 10/15/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AHArticleControllerProtocol.h"

/** UIViewController that wraps a UIWebView for displaying tables or other pages */
@interface AHWebViewController : UIViewController


/** Initialize with URL
 @param urlString the URL as a NSString *
 @return The initialized AHWebViewController
 */
- (id)initWithAddress:(NSString*)urlString;

/** Initialize with URL
 @param URL The URL as an NSURL *
 @return The initialized AHWebViewController
 */
- (id)initWithURL:(NSURL *)URL;

/** Load HTML string into UIWebView. Wraps
      [webView loadHTMLString:html baseURL:baseURL];
 
 @param html The HTML string to load
 @param baseURL The baseURL to use
 */
- (void) loadHTMLString:(NSString*)html baseURL:(NSURL *)baseURL;

/** Reference to the AHArticleController implementation */
@property (nonatomic, weak) id<AHArticleController> articleController;

@end
