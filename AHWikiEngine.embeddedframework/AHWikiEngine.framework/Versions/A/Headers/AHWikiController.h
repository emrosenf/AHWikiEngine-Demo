//
//  AHWikiDelegate.h
//  Wiki
//
//  Created by Evan Rosenfeld on 10/14/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AHArticleController.h"
@protocol AHArticleController;

/** This protocol abstracts the interactions between the AHArticleController and performing operations on various Wikis. This protocol is useful when customizing AHWikiEngine framework to use a different Wiki backend. */
@protocol AHWikiController <NSObject>

@optional

/** Loads a random article from the Wiki */
- (void) loadRandom;

/** Loads an article with the given title from the Wiki. This method assumes that the standard subdomain is @"en", as in English Wikipedia. It does
 
        [self loadArticleNamed:title subdomain:@"en"];
 
 @param title The title of the article to load
 @warning *Note:* Create your own subclass if you wish to change the default domain
 */
- (void) loadArticleNamed:(NSString*)title;

/** Loads an article with the given title and subdomain from the Wiki.
 
 @param title The title of the article to load
 @param subdomain The subdomain of the article
 */
- (void) loadArticleNamed:(NSString*)title subdomain:(NSString*)subdomain;

/** Load an article 
 @param article Dictionary containing information about the article
 */
- (void)goToArticle:(NSDictionary*)article;

/** Load an article
 @param article Dictionary containing information about the article
 */
- (void)loadArticle:(NSDictionary*)article;

/** 
 Convert an image URL from an internal URL to an external URL
 
 For example, this might convert ahwikiengine://image/image1.png to http://mydomain.com/image1.png
 
 @param url URL of the image
 @return The absolute URL of the image
 */
- (NSString *) imageURL:(NSString *)url;

/** Called before a page is loaded to determine if loading should continue 
 @param title Title of the page to load
 @return Whether the page should load
 */
- (BOOL) shouldLoadPage:(NSString*)title;

/** Called when a page is loaded 
 @param title Title of the page being loaded
 */
- (void) loadPage:(NSString*)title;

/** A reference to the AHArticleController */
@property (nonatomic, unsafe_unretained) NSObject<AHArticleController> *articleController;


@end
