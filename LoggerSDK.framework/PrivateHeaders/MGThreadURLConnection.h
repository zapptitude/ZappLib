//
//  CaptureService.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 09.10.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MGIdleThreadManager.h"

@interface MGThreadURLConnection : NSObject {
    
	// Thread in with we will create URLConnection and delegate its methods
    MGIdleThreadManager *_backgroundThread;
    
	// Locker condition
	NSCondition *_condition;
    
	// Flag to display that the connection is active and data is loading. When the connection is stopped contains NO
	volatile BOOL _isLoading;
    
	// Response data received from server. Contains actual data only after isLoading switched to NO.
    // If contains nil than data is not received and connection was determinated forced
	NSMutableData *_responseData;
	
	NSError *_error;
	
	// Connection object lived in the _backgroundThread
	NSURLConnection *_connection;
    
    // Time interval in seconds to provide connection
    NSTimeInterval _timeout;
    
	// For the timeout defenition
	volatile BOOL _serverInteraction;
    
	// Timer for timeout operations
	NSTimer *_timer;
}

/**
 * Synchronously sends request with the timeout
 */
- (NSData *)send:(NSURLRequest *)request timeout:(NSTimeInterval)timeout error:(NSError **)error;

/**
 * Forced determinates the active connection
 */
- (void)stop;


@end

