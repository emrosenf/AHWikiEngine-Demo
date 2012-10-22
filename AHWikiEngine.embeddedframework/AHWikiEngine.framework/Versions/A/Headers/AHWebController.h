//
//  AHWebControllerProtocol.h
//  Wiki
//
//  Created by Evan Rosenfeld on 10/13/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>

/** This protocol abstracts the interaction between the AHArticleController and
 the underlying web view that displays the article.
 */
@protocol AHWebController <NSObject>

/** The title of the current article
 @return The title of the current article
 */
- (NSString*) title;

/** Searches the current article for a string
 @param query The string to search for
 */
- (void)searchCurrentArticle:(NSString*)query;

/** Loads specified HTML into the current web view
 @param html The HTML to load
 @param url The base URL to use. This is usually:
 (usually [NSBundle mainBundle].bundleURL
 */
- (void) loadHTML:(NSString*)html withBaseURL:(NSURL*)url;

/** Load a NSURLRequest into the current web view
 @param request The request to load
 */
- (void) loadRequest:(NSURLRequest*)request;

/** Runs javascript string on the current web view
 @param script The javascript to run
 */
- (NSString*) executeJS:(NSString*)script;

/** Loads the image gallery with an array of images and navigates to 
 a specific image.
 
 @param images The array of images to queue up
 @param name The URL of the image to jump to
 @warning *Note:* The images param should be a subset of the images found by the AHMediawikiParser class. The name param should be an entry in this array
 */
- (void) launchGallery:(NSArray*)images name:(NSString*)name;
@end
