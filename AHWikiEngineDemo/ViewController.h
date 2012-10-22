//
//  ViewController.h
//  AHWikiEngineDemo
//
//  Created by Evan Rosenfeld on 10/18/12.
//  Copyright (c) 2012 Avocado Hills. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UIWebViewDelegate>


@property (nonatomic, strong) IBOutlet UIWebView *webView;
@end
