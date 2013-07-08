//
//  AHWikiConfiguration.h
//  AHWikiEngine
//
//  Created by Evan Rosenfeld on 10/17/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Set the progress with the circle animating to the progress. */
@interface AHWikiConfiguration : NSObject

/** Generate actual URL for an article given its title and subdomain
 
 Example: 
    [self urlFromTitle:@"USA" subdomain:@"en"]
 
 might return: @"http://en.wikipedia.org/wiki/USA"
 
 @param title The title of the article 
 @param subdomain The subdomain of the article
 @return The URL string
 */
- (NSString *)urlFromTitle:(NSString *)title subdomain:(NSString *)subdomain;


/** Generate host for subdomain
 
 Example:
    [self hostForSubdomain:@"en"]
 
 might return: @"http://en.wikipedia.org"
 @param subdomain Subdomain to use
 @return The URL host
 */
- (NSString *)hostForSubdomain:(NSString*)subdomain;

/** Generate URL for API
 
 Example:
 [self apiURLForSubdomain:@"en"]
 
 might return: @"http://en.wikipedia.org/w/api.php"
 @param subdomain Subdomain to use
 @return The API URL
 */
- (NSString *)apiURLForSubdomain:(NSString*)subdomain;

/** The web domain of the current Wiki (e.g. wikipedia.org) */
@property (nonatomic, strong) NSString *domain;

/** The path to the api of the current Wiki (e.g. w/api.php) */
@property (nonatomic, strong) NSString *apiPath;

/** The protocol to be hooked by AHURLProtocol
 
 The default protocol is ahwikiengine. This will hook URLs of the
 type ahwikiengine://article/<SUBDOMAIN>/<TITLE> */
@property (nonatomic, strong) NSString *protocol;

/** The path to Wiki articles in this domain (e.g. wiki/) 
 
 If a standard URL is http://en.wikipedia.org/wiki/USA
 
 Then the domain is @"wikipedia"
 
 The articlePath is @"wiki/"
 */
@property (nonatomic, strong) NSString *articlePath;

/** The class to be used for parsing articles
 
 This class must be a subclass of AHMediawikiParser
 */
@property (nonatomic, readwrite) Class parserClass;

/** The CSS file to be included in every displayed article
 
 The return value assumes the file is in the root directory of the bundle.
 */
@property (nonatomic, strong) NSString *cssFilename;

@end
