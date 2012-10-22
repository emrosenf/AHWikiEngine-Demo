//
//  ViewController.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/18/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "ViewController.h"
#import <AHWikiEngine/AHWikiEngine.h>
#import "CustomArticleController.h"

@interface ViewController ()

@property (nonatomic, readwrite) AHWikiViewController *wikiViewController;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor redColor];
    NSString *htmlPath = [[NSBundle mainBundle] pathForResource:@"demo" ofType:@"html"];
    NSString *html = [NSString stringWithContentsOfFile:htmlPath encoding:NSUTF8StringEncoding error:nil];
    [self.webView loadHTMLString:html baseURL:[NSBundle mainBundle].bundleURL];
    self.wikiViewController = [AHWikiViewController new];
    self.wikiViewController.articleController = [CustomArticleController new];
	// Do any additional setup after loading the view, typically from a nib.
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    if (navigationType == UIWebViewNavigationTypeLinkClicked) {
        if ([request.URL.scheme isEqualToString:@"ahwikiengine"]) {
            [self.wikiViewController loadRequest:request];
            UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:self.wikiViewController];
            [self presentViewController:nav animated:YES completion:nil];
            
            return NO;
        }
    }

    return YES;
}


@end
