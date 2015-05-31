//
//  DataSourceHelper.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 03.07.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

@interface DataSourceHelper : NSObject

+ (NSString *)errorLogPath;
+ (NSString *)eventLogPath;

+ (NSString *)documentsDirectoryPathForPathComponent:(NSString *)pathComponent create:(BOOL)create skipBackupAttribute:(BOOL)skipBackupAttribute;
+ (BOOL)addSkipBackupAttributeToItemAtURL:(NSURL*)URL;

@end
