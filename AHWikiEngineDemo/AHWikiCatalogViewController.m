//
//  AHWikiCatalogViewController.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/21/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "AHWikiCatalogViewController.h"
#import "TableViewCellWrapper.h"
#import <AHWikiEngine/AHWikiEngine.h>
#import "WoWWikiConfiguration.h"
#import "ZeldaWikiConfiguration.h"
#import "CustomCSSWikiConfiguration.h"
#import "CustomArticleController.h"
#import "CustomWebpageViewController.h"

@interface AHWikiCatalogViewController () {
    NSMutableArray *data;
    UINavigationController *navController;
    AHWikiViewController *wikiViewController;
}

@end

@implementation AHWikiCatalogViewController

- (id)init
{
    self = [super initWithStyle:UITableViewStyleGrouped];
    if (self) {
        // Custom initialization
        
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    data = [NSMutableArray arrayWithCapacity:10];
    
    navController = [UINavigationController new];
    wikiViewController = [AHWikiViewController new];

    TableViewCellWrapper *enUSA = [TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"USA (English)";
    } selectBlock:^{
        [AHWikiEngine start];
        wikiViewController.articleController = [AHArticleController new];
        [wikiViewController loadArticleNamed:@"USA"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }];
    
    TableViewCellWrapper *frUSA = [TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"USA (French)";
    } selectBlock:^{
        [AHWikiEngine start];
        wikiViewController.articleController = [AHArticleController new];
        [wikiViewController loadArticleNamed:@"USA" subdomain:@"fr"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }];
    
    TableViewCellWrapper *ruUSA = [TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"USA (Russian)";
    } selectBlock:^{
        [AHWikiEngine start];
        wikiViewController.articleController = [AHArticleController new];
        [wikiViewController loadArticleNamed:@"USA" subdomain:@"ru"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }];
    
    NSDictionary *wikipedia = @{@"title" : @"Wikipedia", @"rows": @[enUSA, frUSA, ruUSA] };
    [data addObject:wikipedia];
    
    [data addObject:@{@"title": @"World of Warcraft Wiki", @"rows": @[[TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"Mage";
    } selectBlock:^{
        [AHWikiEngine startWithConfiguration:[WoWWikiConfiguration new]];
        [wikiViewController loadArticleNamed:@"Mage" subdomain:@""];
        wikiViewController.articleController = [CustomArticleController new];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }]]}];
    
    
    [data addObject:@{@"title": @"The Zelda Wiki", @"rows": @[[TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"Princess Zelda";
    } selectBlock:^{
        [AHWikiEngine startWithConfiguration:[ZeldaWikiConfiguration new]];
        [wikiViewController loadArticleNamed:@"Princess Zelda" subdomain:@""];
        wikiViewController.articleController = [CustomArticleController new];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }]]}];
    
    
    [data addObject:@{@"title": @"Custom CSS", @"rows": @[[TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"USA (English)";
    } selectBlock:^{
        [AHWikiEngine startWithConfiguration:[CustomCSSWikiConfiguration new]];
        [wikiViewController loadArticleNamed:@"USA" subdomain:@"en"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
        [wikiViewController.articleController.webController performSelector:@selector(searchCurrentArticle:) withObject:@"united" afterDelay:3.0];
    }]]}];
    
    
    [data addObject:@{@"title": @"Using HTML", @"rows": @[[TableViewCellWrapper cellWithBlock:^(UITableViewCell *cell) {
        cell.textLabel.text = @"HTML";
    } selectBlock:^{
        [AHWikiEngine start];
        CustomWebpageViewController *webPageController = [CustomWebpageViewController new];
        [navController setViewControllers:@[webPageController]];
        [self presentViewController:navController animated:YES completion:nil];
        //[wikiViewController.articleController.webController performSelector:@selector(searchCurrentArticle:) withObject:@"united" afterDelay:3.0];
    }]]}];
    
    [self.tableView reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return data.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [data[section][@"rows"] count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"CellIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    
    TableViewCellWrapper *wrp = data[indexPath.section][@"rows"][indexPath.row];
    wrp.cellBlock(cell);
    
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return data[section][@"title"];
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    TableViewCellWrapper *wrp = data[indexPath.section][@"rows"][indexPath.row];
    wrp.selectBlock();
}

@end
