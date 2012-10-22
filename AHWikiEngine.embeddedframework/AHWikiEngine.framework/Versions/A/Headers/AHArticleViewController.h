//
//  AHArticleDelegate.h
//  AHWikiEngine
//
//  Created by Evan Rosenfeld on 10/15/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>

#if !(TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
#import <WebKit/WebKit.h>
#endif

#import "AHModalWebViewController.h"

/** This protocol describes the underlying view controller that displays articles. Although it has many similiarties to UIResponder and UIViewController, it has been written in this way to be platform agnostic. */ 
@protocol AHArticleViewController <NSObject>

/** The title of the current page
 @return title The title of the current page
 */
- (NSString*) title;

/** Setter for the title
 @param title The title to set
 */
- (void) setTitle:(NSString*)title;

- (void) updateArticleInfo:(NSDictionary*)dict;

/** Executes javascript string in the underlying web view
 @param javascript The javascript to run
 @return The result of the javascript execution
 */
- (NSString *) executeJS:(NSString *)javascript;

/** UIResponder method */
- (void) becomeFirstResponder;


#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
- (AHModalWebViewController*) modalWebView;

/** UIViewController method to present view controller modally 
 
 @param controller Controller to present
 @param animated Whether the presentation should be animated
 @param completion Block to execute on completion
 */
- (void) presentViewController:(UIViewController*)controller animated:(BOOL)animated completion:(void (^)(void))completion;

/** Either dismiss a modal view controller or dismiss a popup (iPad only) */
- (void) closeSubordinate;

/** The underlying UIWebView 
 
 @return The UIWebView
 */
- (UIWebView*) webView;
#else

- (WebView*) webView;
#endif

/** Open a URL string
 
 @param url NSString * of the url to open
 */
- (void) openURL:(NSString*)url;

@optional

/** Adjusts the state of the back navigation button
 
 @param enabled Whether the back button should be enabled
 */
- (void) setBackButtonEnabled:(BOOL)enabled;

/** Adjusts the state of the forward navigation button
 
 @param enabled Whether the forward button should be enabled
 */
- (void) setForwardButtonEnabled:(BOOL)enabled;


@end
