//
//  Logger.h
//  LoggerSDK
//
//  Created by Vitalii Skorobreshchuk on 3/19/15.
//  Copyright (c) 2015 MEV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MGEventLog.h"

@interface Logger : NSObject

+ (Logger *)sharedInstance;
- (id)loggerWithAppID:(NSString *)appID;
- (void)addLogEvent:(NSString *)eventType data:(NSDictionary *)data;

@end
