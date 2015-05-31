//
//  LogService.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 25.10.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

//@class ShoppingFolderModel;

#import "AFHTTPRequestOperation.h"

@class LConstant;

@interface LogService : NSObject{
    
    LConstant *_constant;
    
}

- (void)sendEventLogs:(NSMutableArray *)eventLogList deviceInfo:(NSDictionary *)deviceInfo applicationInfo:(NSDictionary *)applicationInfo
              success:(void (^)(AFHTTPRequestOperation *operation, id JSON))success;
- (void)sendErrorLogs:(NSMutableArray *)errorLogList deviceInfo:(NSDictionary *)deviceInfo applicationInfo:(NSDictionary *)applicationInfo
              success:(void (^)(AFHTTPRequestOperation *operation, id JSON))success;

@end
