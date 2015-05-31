//
//  CaptureService.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 09.10.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MGIdleThreadManager : NSObject {
    
	volatile BOOL _running;
    
}


@property (readonly) NSThread *thread;

- (void)stop;


@end
