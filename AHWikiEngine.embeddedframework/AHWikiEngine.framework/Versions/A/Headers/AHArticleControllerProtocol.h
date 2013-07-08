//
//  AHArticleControllerProtocol.h
//  AHWikiEngine
//
//  Created by Evan Rosenfeld on 10/18/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>

/** This protocol describes an AHArticleController implementation */
@protocol AHArticleController <NSObject>

/** Current article dictionary 
 @return Current article dictionary 
 */
@property (nonatomic, strong) NSMutableDictionary *currentArticle;

- (void) prepareToLoadArticle:(NSString *)urlString;
- (void) saveScrollPosition;

/** External link to the current article
 @return Link to current article
 */
- (NSString *) currentLink;

/** Title of the current article
 @return Title of the current article
 */
- (NSString*) currentTitle;

/** Go to the previous article
 @param sender Sender of the action
 */
- (void) goBack:(id)sender;

/** Go to the next article
 @param sender Sender of the action
 */
- (void) goForward:(id)sender;

/** Search the current article for a query
 @param query Search query
 */
- (void)searchCurrentArticle:(NSString*)query;

/** Load a request in the web view
 @param request Request to load
 */
- (void) loadRequest:(NSURLRequest*)request;

/** Execute Javascript in web view
 @param script Script to execute
 @return Returned text from javascript
 */
- (NSString*) executeJS:(NSString*)script;

/** Loads HTML string in web view
 @param html HTML to load
 @param url Base URL 
 */
- (void) loadHTML:(NSString*)html withBaseURL:(NSURL*)url;

/** Loads random article from Wiki */
- (void)loadRandom;

/** Loads article with given name from Wiki
 @param title Title of article to load
 @warning Assumes subdomain is @"en"
 */
- (void) loadArticleNamed:(NSString*)title;

/** Loads article with given name and subdomain from Wiki
 @param title Title of article to load
 @param subdomain Subdomain to use
 */
- (void) loadArticleNamed:(NSString*)title subdomain:(NSString*)subdomain;

/** Adds article to history
 @param article Article to add
 */
- (void) addToHistory:(NSDictionary *)article;

/** Switch article and update UI
 @param title Title of new article
 */
- (void) switchArticle:(NSString*)title;

/** Gets the history array
 @return NSArray* of article objects
 */
- (NSArray *)getHistory;

/** Sets the history array
 @param history New history array */
- (void) setHistory:(NSArray *)history;

/** Configures the UI for the current article
 @param article New article
 */
- (void) configureUI:(NSDictionary*)article;

/** Gets the article for the given title
 @param title Title of article to fetch
 @return NSDictionary* of article
 */
- (NSDictionary*) getArticle:(NSString*)title;

/** Returns list of found images for a given article.
 This method allows the author to filter by size or other
 criteria.
 @param article Article to get images for
 @return Array of images
 */
- (NSArray *)imagesForArticle:(NSDictionary *)article;

@optional

- (void) viewOnline;
- (void)goToArticle:(NSDictionary*)article;

- (void) viewOnline:(void (^)(NSString *viewOnline))displayBlock noInternetBlock:(void (^)(void))noInternetBlock;
- (void) onlineUpdate:(NSString*)title notUserGuideBlock:(void (^)(void))notUserGuideBlock noInternetBlock:(void (^)(void))noInternetBlock;


- (void)loadArticle:(NSDictionary*)article;



/** WebView delegate to process web view event
 @param url URL string that finished loading
 */
- (void) webViewFinishedLoading:(NSString *)url;

/** WebView delegate to process web view event
 @param webView web view loading
 @param request Request that should be loading
 @param tableBlock Block to display tables
 @param linkBlock Block to display external links
 @return Whether request should load
 */
- (BOOL) webView:(id)webView shouldLoadRequest:(NSURLRequest*)request
      tableBlock:(void(^)(NSString*, NSURL*))tableBlock linkBlock:(void(^)(NSString*))linkBlock;


/** Allows for cleanup when memory is low */
- (void) didReceiveMemoryWarning;
@end

