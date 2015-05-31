//
//  MGEventLog.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 23.10.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//


@interface MGEventLog : NSObject {
    
@private

    NSMutableArray *_eventLogList;
    
}

- (void)logEvent:(NSString *)eventType data:(NSDictionary *)data;
- (void)sendLog;

@end
