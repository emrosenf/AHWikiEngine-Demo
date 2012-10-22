//
//  AHWikiViewController.h
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/18/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AHBulletViewController.h"
/** UIViewController used to display Wiki articles and user interface for
 navigating them (back button, forward button, table of contents, actions)
 */
@interface AHWikiViewController : UIViewController<UIPopoverControllerDelegate,AHArticleViewController, UIActionSheetDelegate>

/** Reference to the AHArticleController implementation */
@property (nonatomic, strong) AHArticleController *articleController;

/** Popover to display Table of Contents on iPad */
@property (nonatomic, strong) UIPopoverController *popover;

/** Underlying UIWebView */
@property (nonatomic, strong) UIWebView *webView;

/** Modal controller to displaying tables on iPhone */
@property (nonatomic, strong) AHModalWebViewController *modalWebView;

/** Table of Contents view controller */
@property (nonatomic, strong) AHBulletViewController *bulletController;

/** Back button */
@property (nonatomic, strong) UIBarButtonItem *backButton;

/** Forward button */
@property (nonatomic, strong) UIBarButtonItem *forwardButton;

/** Table of Contents button */
@property (nonatomic, strong) UIBarButtonItem *tocButton;

/** Action button */
@property (nonatomic, strong) UIBarButtonItem *actionButton;


/** Show possible actions when action button is pressed 
 @param sender Sender of the action
 */
-(void) actionActions:(id)sender;

/** Load Request in webView
 @param request Request to load
 */
- (void) loadRequest:(NSURLRequest *)request;

/** Load article in webView
 @param title Title of article to load
 */
- (void) loadArticleNamed:(NSString*)title;

/** Load article with title and subdomain in webView
 @param title Title of article to load
 @param subdomain subdomain of the article
 */
- (void) loadArticleNamed:(NSString *)title subdomain:(NSString *)subdomain;
@end