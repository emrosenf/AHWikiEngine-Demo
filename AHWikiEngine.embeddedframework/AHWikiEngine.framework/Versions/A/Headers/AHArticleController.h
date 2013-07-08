//
//  AHArticleController.h
//  Wiki
//
//  Created by Evan Rosenfeld on 6/28/11.
//  Copyright 2011 Avocado Hills. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AHArticleViewController.h"
#import "AHWebController.h"
#import "AHWikiController.h"
#import "AHArticleControllerProtocol.h"

@protocol AHWikiController;
@protocol AHWebController;

#define MAX_S_HIST 10

/** Base implementation of the AHArticleController protocol */
@interface AHArticleController : NSObject <AHArticleController> {
  
  /** An optional block to display status messages to the user upon loading */
  void (^statusBlock)(NSString*);
}


/** The implementation of AHWikiController */
@property (nonatomic, strong) NSObject<AHWikiController> *wikiController;

/** The implementation of AHWebController */
@property (nonatomic, strong) NSObject<AHWebController> *webController;

/** A weak reference to the underlying view controller */
@property (nonatomic, unsafe_unretained) id<AHArticleViewController> delegate;

/** An array that holds the session history */
@property (nonatomic, strong) NSMutableArray *sHistory;

/** The current index in the sHistory array */
@property (nonatomic, assign) NSUInteger sIndex;

/** Information about the current article */
@property (nonatomic, strong) NSMutableDictionary *currentArticle;


@end
