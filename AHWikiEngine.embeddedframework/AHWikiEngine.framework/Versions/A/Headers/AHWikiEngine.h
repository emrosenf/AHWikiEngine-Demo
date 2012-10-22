//
//  AHWikiEngineLoader.h
//  Wiki
//
//  Created by Evan Rosenfeld on 10/10/12.
//
//

#import <Foundation/Foundation.h>
#import "AHMediawikiParser.h"
#import "AHWikiConfiguration.h"
#import "AHArticleController.h"

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import "AHWikiViewController.h"
#import "AHBulletViewController.h"
#import "AHIOSWebController.h"
#import "Gallery/AHGalleryViewController.h"
#endif


/** This is the master class of the framework and handles some configurations.
 */

@interface AHWikiEngine : NSObject

/** Start AHWikiEngine and load necessary components */
+ (void) start;

/** Start AHWikiEngine and load necessary components using given configuration
 @param configuration Configuration instance to use
 */
+ (void) startWithConfiguration:(AHWikiConfiguration*)configuration;

/** Parser for AHWikiURLProtocol to use
 @return parser Parser to use
 */
+ (AHMediawikiParser *) parser;

/** CSS file name to be embedded in all pages
 
 @warning *Note:* Assumes the file is in the main bundle. For instance, return @"ahwikiengine.css" if this file is in the main bundle.
 @return The CSS file name
 */
+ (NSString *)cssFilename;

/** Convert a wikified phrase into a human readable phrase. For example:
      [self humanize:@"this_wiki_phrase"] 
 
 Outputs: 
      @"This wiki phrase"
 @param phrase A Wikified phrase
 @return The humanized phrase
 */
+ (NSString *)humanize:(NSString *)phrase;

/** Generate actual URL for an article given its title and subdomain
 
 Example:
 [self urlFromTitle:@"USA" subdomain:@"en"]
 
 might return: @"http://en.wikipedia.org/wiki/USA"
 
 @param title The title of the article
 @param subdomain The subdomain of the article
 @return The URL string
 */
+ (NSString *)urlFromTitle:(NSString *)title subdomain:(NSString *)subdomain;

/** Generate host for subdomain
 
 Example:
 [self hostForSubdomain:@"en"]
 
 might return: @"http://en.wikipedia.org
 @param subdomain Subdomain to use
 @return The URL host
 */
+ (NSString *) hostForSubdomain:(NSString *)subdomain;
/** Shared instance
 @return Shared Instance
 */
+ (AHWikiEngine *)sharedInstance;

/** Register an alternate URL protocol
 @param urlProtocolClass The NSURLProtocol subclass to replace AHWikiURLProtocol
 */
+ (void) registerURLProtocol:(Class)urlProtocolClass;


@end
