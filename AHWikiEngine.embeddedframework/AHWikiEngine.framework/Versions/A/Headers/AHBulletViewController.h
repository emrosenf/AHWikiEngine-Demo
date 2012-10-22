//
//  AHBulletViewController.h
//  Wiki
//
//  Created by Evan Rosenfeld on 10/9/12.
//
//

#import <UIKit/UIKit.h>
#import "AHArticleViewController.h"

/** A class for display Table of Contents data and navigating to the 
 proper anchor tag*/
@interface AHBulletViewController : UITableViewController

/** Weak reference to the AHArticleViewController implementation */
@property (nonatomic, weak) id<AHArticleViewController> delegate;

/** Table of Contents data */
@property (nonatomic, strong) NSMutableArray *data;

@end
