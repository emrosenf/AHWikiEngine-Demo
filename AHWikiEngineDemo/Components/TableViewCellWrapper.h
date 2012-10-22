//
//  TableViewCellWrapper.h
//  Wiki
//
//  Created by Evan on 9/24/10.
//  Copyright 2010 Avocado Hills. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void (^CellBlock)(UITableViewCell *cell);
typedef void (^didSelectBlock)(void);


@interface TableViewCellWrapper : NSObject {

	
}

@property (nonatomic, copy) CellBlock cellBlock;
@property (nonatomic, copy) didSelectBlock selectBlock;

+ (id) cellWithBlock:(CellBlock)theCellBleck selectBlock:(didSelectBlock)theSelectBlock;
- (id)initWithBlocks:(CellBlock)theCellBlock selectBlock:(didSelectBlock)theSelectBlock;


@end
