//
//  MGLog.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 14.10.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

typedef enum {
    MGLogInfoPriority,
    MGLogNoticePriority,
    MGLogErrorPriority,
    MGLogCrashPriority
} MGLogPriorityLevel;


@interface MGErrorLog : NSObject {
    
@private
    
    NSMutableArray *_errorLogList;
    
}

- (void)logMessage:(NSString *)message priority:(MGLogPriorityLevel)priority payload:(NSDictionary *)payload display:(BOOL)display;
- (void)logError:(NSError *)error;

- (void)sendLog;


@end
