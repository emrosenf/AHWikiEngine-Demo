//
//  WikiURLProtocol.h
//  Wiki
//
//  Created by Evan on 3/26/11.
//  Copyright 2011 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AHMediawikiParser.h"

/** NSURLProtocol subclass that handles the loading and parsing of Wiki articles
 */
@interface AHWikiURLProtocol : NSURLProtocol {

  NSString *_subdomain;
  NSString *query;
	
  float parsingTime;
  NSDate *startTime;
  NSDate *responseTime;
  AHMediawikiParser *parser;
}


/** Register this NSURLProtocol */
+ (void) registerProtocol;

/** Unregister this NSURLProtocol */
+ (void) unregisterProtocol;

/** Send data to the client
 @param data Data to send to the client
 */
- (void) sendData:(NSData*)data;

/** Cleanup process */
- (void) finish;

/** Begin fetching the article
 @param title Title of the article
 */
- (void) startOnlineFetch:(NSString*)title;

/** Send header HTML to the client
 @param title Title of the article
 */
- (void) sendHeaderHTML:(NSString*)title;

/** 
 Send the article metadata to the rest of the app by sending kArticleExtrasNotification
 */
- (void) sendArticleMetadata;

/** 
 @param progress Progress to set
 */
- (void) setProgress:(float)progress;

/** Create the HTML header of the page
 @param title Title of the article
 @return String containing the HTML header to return
 */
- (NSString*) makeHeader:(NSString*)title;


@end


