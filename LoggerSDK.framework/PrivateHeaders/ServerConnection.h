//
//  ServerConnection.h
//  VOT
//
//  Created by Dmitry Kovalenko on 16.09.11.
//  Copyright 2011 MEV. All rights reserved.
//
#import "AFNetworking.h"

@interface ServerConnection : NSObject

/**
 * Service method for escaping all special characters in the query string
 *
 * @param unencodedString Unencoded string.
 * @return String after escaping 
 */
+ (NSString *)escapeString:(NSString *)unencodedString;

/**
 * Forms plain query string by the scheme "key=value&key2=value2" from the data dictionary
 *
 * @param data Dictionary with the pairs key => value
 * @return Formatted string 
 */
+ (NSString *)formatQueryStringWithData:(NSDictionary *)data;

/**
 * Forms url object with the domain settings from the received uri string
 *
 * @param uri String with uri for the url object ("/some-controller/some-action")
 * @return Formatted url object 
 */
+ (NSURL *)urlWithUri:(NSString *)uri;

/**
 * Forms url request object with the received data variables and files.
 */
+ (NSMutableURLRequest *)formatUrlRequestWithUrl:(NSString *)url data:(NSDictionary *)data files:(NSDictionary *)files options:(NSDictionary *)options;


/**
 * Sends prepared request to the url with specified data and files list. If recieved error from the backend -
 * will display alert window. Return formatted response data dictionary.
 */
+ (NSDictionary *)requestToUrl:(NSString *)url withData:(NSDictionary *)data files:(NSDictionary *)files options:(NSDictionary *)options;

/**
 * Simplify method for the requestToUrl with nil data
 */
+ (NSDictionary *)requestToUrl:(NSString *)url;



/**
 * Sends asynchronous request to the url with specified data and files list. If recieves error from the backend -
 * display alert window and run failure block. If result from the server not contains errors - run success block.
 */
+ (void)asynchronousRequestToUrl:(NSString *)url withData:(NSDictionary *)data files:(NSDictionary *)files options:(NSDictionary *)options
                         success:(void (^)(AFHTTPRequestOperation *operation, id JSON))success
                         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

/**
 * Simplify method for the asynchronousRequestToUrl with nil data, files and options
 */
+ (void)asynchronousRequestToUrl:(NSString *)url
                         success:(void (^)(AFHTTPRequestOperation *operation, id JSON))success
                         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

/**
 * Simplify method for the asynchronousRequestToUrl with nil success/failure blocks
 */
+ (void)asynchronousRequestToUrl:(NSString *)url;


@end
