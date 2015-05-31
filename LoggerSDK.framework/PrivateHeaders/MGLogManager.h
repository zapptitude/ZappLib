//
//  MGLogManager.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 01.11.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MGEventLog;
@class MGErrorLog;

@interface MGLogManager : NSObject {
    
@private
    
    NSTimer *_timer;
    
}

+ (MGEventLog *)eventLog;
+ (MGErrorLog *)errorLog;

- (void)startSendingBackgroundProcess;
- (void)finishSendingBackgroundProcess;
- (void)sendLog;


@end
