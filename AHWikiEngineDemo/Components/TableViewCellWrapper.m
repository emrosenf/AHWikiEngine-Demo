//
//  TableViewCellWrapper.m
//  Wiki
//
//  Created by Evan on 9/24/10.
//  Copyright 2010 Avocado Hills. All rights reserved.
//

#import "TableViewCellWrapper.h"


@implementation TableViewCellWrapper
@synthesize cellBlock, selectBlock;

+ (id)cellWithBlock:(CellBlock)theCellBleck selectBlock:(didSelectBlock)theSelectBlock {
    TableViewCellWrapper *wrapper = [[self alloc] initWithBlocks:theCellBleck selectBlock:theSelectBlock];
    return wrapper;
}

- (id)initWithBlocks:(CellBlock)theCellBlock selectBlock:(didSelectBlock)theSelectBlock
{
	if (self = [super init])
	{
		self.cellBlock = theCellBlock;
		self.selectBlock = theSelectBlock;
	}
	return self;
}
@end
