//
//  AHWikimediaParser.h
//  AHWikiEngine
//
//  Created by Evan Rosenfeld on 10/16/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <libxml/tree.h>
#import <libxml/HTMLparser.h>

#define BODYTEXT_FINISHED   1
#define IN_BODYTEXT         1
#define CATLINKS_FINISHED   2
#define IN_CATLINKS         2
#define LANGUAGES_FINISHED  4
#define IN_LANGUAGES        4
#define IN_TOC              8
#define IN_CATLINKS_DIV     16
#define IN_TABLE            32
#define IN_LICENSE          64
#define LICENSE_FINISHED    64

/** SAX-style parser for Wiki pages. This class is responsible for parsing
 incoming data from AHWikiURLProtocol.
 
 This class returns the parsed data through flushData.
 
 It also keeps a record of the entire parsed article in entireArticle.
 
 It has multiple properties that hold metadata found in the article.
 
 
 */
@interface AHMediawikiParser : NSObject {
  unsigned int locationIndicator;
  int travelTocLevel;
}


/** Allows for custom processing of nodes
 
 @param name The name of the element that has just begun
 @param attributes HTML attributes array
 */
- (void) foundElementInBodyText:(const char*)name attributes:(xmlChar **)attributes;

/** Allows for custom processing of nodes
 
 @param name The name of the element that has just ended
 */
- (void) endElementInBodyText:(const char*)name;

/** The CSS class name for the text of table of contents line items
 
 The default is @"toctext"
 
 This can be useful when customizing for other types of Wikis
 @return The CSS class name to be used
 */
- (NSString *) tableOfContentsClassName;

/** Allows for additional processing when a Table of Contents line-item is found 
 
 @param className The name of the CSS class found
 */
- (void) foundTableOfContentsLineItem:(NSString *)className;

/** Allows the rewriting of links to other Wiki pages
 
 This can be useful if you want images to be handled by a separate NSURLProtocol
 
 @param tag String that contains the A tag
 */
- (void) rewriteInternalLink:(NSMutableString*)tag;

/** Allows the rewriting of image src URLs
 
 This can be useful if you want images to be handled by a separate URLProtocol
 
 @param tag String that contains the IMG tag
 */
- (void) rewriteImageLink:(NSMutableString*)tag;


/** Finds the value of an HTML attribute from the given array
 
 Example: 
     [self getAttribute:"href" attributes:attributes]
 
 Might return: @"http://www.google.com"
 
 @param name The name of the attribute to search for
 @param attributes The array of attributes
 @return The attribute, if found. */
- (NSString*) getAttribute:(const char*)name inArray:(xmlChar **)attributes;


/** Returns TRUE if the parser is currently in the middle of a table */
- (BOOL) isParsingTable;

/** Clears data buffer and pushes parsed data to entireArticle 
 @return Returns newly processed data using NSUTF8StringEncoding
 */
- (NSData *) flushData;


/** Pushes a chunk of data to be parsed
 @param data Data to be parsed
 */
- (void) parseChunk:(NSData *)data;


/** Subdomain of the page being parsed
 
 Used to help reconstruct links
 
 For example, the subdomain of an English Wikipedia article would be @"en"
 */
@property (nonatomic, strong) NSString *subdomain;

/** The ultimate output of the parser */
@property (nonatomic, readonly) NSMutableString *entireArticle;

/** Array containing the Table of Contents
 
 Each entry in the Table of Contents has three entries
 
 - level (NSNumber) = The level of nesting for this entry
 - link (NSString *) = The anchor tag of the section represented by this item
 - text (NSString *) = The text of this item
 */
@property (nonatomic, readonly) NSMutableArray *toc;

/** Array containing URLs of the images in the article
 */
@property (nonatomic, readonly) NSMutableArray *images;

/** Array containing captions for the images in the article
 
 Captions is meant to correspond 1-to-1 to images.
 */
@property (nonatomic, readonly) NSMutableArray *captions;

/** Array containing the HTML of the tables in the article
 */
@property (nonatomic, readonly) NSMutableArray *tables;

/** Array containing the categories the article belongs to
 
 Each entry has two parts:
 
 - header (NSString *) = the title of the category
 - link (NSString *) = the Wiki link to this category
 */
@property (nonatomic, readonly) NSMutableArray *categories;

/** Array containing links to this article in other languages
 
 Each entry has two parts:
 
 - code (NSString *) = the language code (e.g. @"zh" for Chinese)
 - link (NSString *) = the encoded URL for the article in this language
 */
@property (nonatomic, readonly) NSMutableArray *langlinks;

/** URL of the first image in the article
 */
@property (nonatomic, readonly) NSString *representativeImg;

/** Allows AHWikiURLProtocol to finish the request early if all
 parsing has been completed
 */
@property (nonatomic, readonly) BOOL parsingFinishedEarly;
@end
