//
//  TrackingLocation.h
//  Magnetique
//
//  Created by Dmitry Kovalenko on 22.09.12.
//  Copyright (c) 2012 MEV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
//#import <QuartzCore/QuartzCore.h>
//#import <AddressBook/AddressBook.h>


@class TrackingLocation;

@protocol TrackingLocationDelegate

- (void)trackingLocation:(TrackingLocation *)trackingLocation didUpdateLocation:(CLLocation *)location;
- (void)trackingLocation:(TrackingLocation *)trackingLocation didFailWithError:(NSString *)error;

@end


@interface TrackingLocation : NSObject <CLLocationManagerDelegate> {

@private

    CLLocationManager *_locationManager;
    
}

@property (weak, nonatomic) id <TrackingLocationDelegate> delegate;

@property (strong, nonatomic) CLLocation *trackedLocation;
@property (strong, nonatomic) NSString *trackedAddress;
@property (nonatomic) BOOL trackedSelfLocation;


+ (BOOL)locationServicesEnabled;
- (void)startTrackSelfLocation;
- (void)stopTrackSelfLocation;
- (void)trackLocationWithAdress:(NSString *)address;



@end
