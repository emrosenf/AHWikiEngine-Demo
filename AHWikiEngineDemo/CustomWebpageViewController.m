//
//  ViewController.m
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/18/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import "CustomWebpageViewController.h"
#import <AHWikiEngine/AHWikiEngine.h>

@interface CustomWebpageViewController ()

@property (nonatomic, readwrite) AHWikiViewController *wikiViewController;

@end

@implementation CustomWebpageViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.webView = [[UIWebView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:self.webView];
    self.webView.delegate = self;
    NSString *htmlPath = [[NSBundle mainBundle] pathForResource:@"demo" ofType:@"html"];
    NSString *html = [NSString stringWithContentsOfFile:htmlPath encoding:NSUTF8StringEncoding error:nil];
    [self.webView loadHTMLString:html baseURL:[NSBundle mainBundle].bundleURL];
    self.wikiViewController = [AHWikiViewController new];
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(hide)];
}

- (void) hide {
    [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    if (navigationType == UIWebViewNavigationTypeLinkClicked) {
        if ([request.URL.scheme isEqualToString:[AHWikiEngine protocol]]) {
            [self.wikiViewController loadRequest:request];
            UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:self.wikiViewController];
            [self presentViewController:nav animated:YES completion:nil];
            
            return NO;
        }
    }

    return YES;
}


@end
