//
//  MGProjectInfo.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 03.11.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@interface MGInfo : NSObject

+ (NSDictionary *)applicationInfo;
+ (NSDictionary *)deviceInfo;
+ (NSString *)connectionStateInfo;
+ (NSDictionary *)currentLocationInfo;

@end
