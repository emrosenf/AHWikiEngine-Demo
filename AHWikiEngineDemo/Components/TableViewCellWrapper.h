//
//  TableViewCellWrapper.h
//  Wiki
//
//  Created by Evan on 9/24/10.
//  Copyright 2010 Avocado Hills. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef UITableViewCell* (^CellBlock)(void);
typedef void (^didSelectBlock)(void);


@interface TableViewCellWrapper : NSObject {
    
	
}

@property (nonatomic, copy) CellBlock cellBlock;
@property (nonatomic, copy) didSelectBlock selectBlock;

+ (id) cellWithBlock:(UITableViewCell*(^)(void))theCellBlock selectBlock:(void(^)(void))theSelectBlock;
- (id)initWithBlocks:(UITableViewCell*(^)(void))theCellBlock selectBlock:(void(^)(void))theSelectBlock;


@end
