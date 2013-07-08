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
    AHMediawikiParser *parser;
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
    static NSString *CellIdentifier = @"CellIdentifier";
    TableViewCellWrapper *enUSA = [TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"USA (English)";
        return cell;
    } selectBlock:^{
        [AHWikiEngine start];
        wikiViewController.articleController = [AHArticleController new];
        [wikiViewController loadArticleNamed:@"USA"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }];
    
    TableViewCellWrapper *frUSA = [TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"USA (French)";
        return cell;
    } selectBlock:^{
        [AHWikiEngine start];
        wikiViewController.articleController = [AHArticleController new];
        [wikiViewController loadArticleNamed:@"USA" subdomain:@"fr"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }];
    
    TableViewCellWrapper *ruUSA = [TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"USA (Russian)";
        return cell;
    } selectBlock:^{
        [AHWikiEngine start];
        wikiViewController.articleController = [AHArticleController new];
        [wikiViewController loadArticleNamed:@"USA" subdomain:@"ru"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }];
    
    NSDictionary *wikipedia = @{@"title" : @"Wikipedia", @"rows": @[enUSA, frUSA, ruUSA] };
    [data addObject:wikipedia];
    
    [data addObject:@{@"title": @"World of Warcraft Wiki", @"rows": @[[TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"Mage";
        return cell;
    } selectBlock:^{
        [AHWikiEngine startWithConfiguration:[WoWWikiConfiguration new]];
        [wikiViewController loadArticleNamed:@"Mage" subdomain:@""];
        wikiViewController.articleController = [CustomArticleController new];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }]]}];
    
    
    [data addObject:@{@"title": @"The Zelda Wiki", @"rows": @[[TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"Princess Zelda";
        return cell;
    } selectBlock:^{
        [AHWikiEngine startWithConfiguration:[ZeldaWikiConfiguration new]];
        [wikiViewController loadArticleNamed:@"Princess Zelda" subdomain:@""];
        wikiViewController.articleController = [CustomArticleController new];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
    }]]}];
    
    
    [data addObject:@{@"title": @"Custom CSS", @"rows": @[[TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"USA (English)";
        return cell;
    } selectBlock:^{
        [AHWikiEngine startWithConfiguration:[CustomCSSWikiConfiguration new]];
        [wikiViewController loadArticleNamed:@"USA" subdomain:@"en"];
        [navController setViewControllers:@[wikiViewController]];
        [self presentViewController:navController animated:YES completion:nil];
        [wikiViewController.articleController.webController performSelector:@selector(searchCurrentArticle:) withObject:@"united" afterDelay:3.0];
    }]]}];
    
    
    [data addObject:@{@"title": @"Using HTML", @"rows": @[[TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"HTML";
        return cell;
    } selectBlock:^{
        [AHWikiEngine start];
        CustomWebpageViewController *webPageController = [CustomWebpageViewController new];
        [navController setViewControllers:@[webPageController]];
        [self presentViewController:navController animated:YES completion:nil];
    }]]}];
    
    [data addObject:@{@"title": @"No UI", @"rows": @[[TableViewCellWrapper cellWithBlock:^UITableViewCell * {
        UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
        cell.textLabel.text = @"Parse USA";
        return cell;
    } selectBlock:^{
        [AHWikiEngine start];
        parser = [AHWikiEngine parser];
        parser.subdomain = @"en";
        [NSURLConnection connectionWithRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://en.wikipedia.org/wiki/USA"]] delegate:self];
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
    TableViewCellWrapper *wrp = data[indexPath.section][@"rows"][indexPath.row];
    return wrp.cellBlock();
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return data[section][@"title"];
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    TableViewCellWrapper *wrp = data[indexPath.section][@"rows"][indexPath.row];
    wrp.selectBlock();
}

#pragma mark - No UI

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    NSLog(@"Parser finished");
    NSString *entireArticle = [parser entireArticle];
    NSArray *toc = [parser toc];
    NSArray *images = [parser images];
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    [parser parseChunk:data];
    if (![parser isParsingTable]) {
        [parser flushData];
    }
}

@end
