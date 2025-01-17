//
//  UIImage+HEIC.h
//  Test
//
//  Created by Tim Johnsen on 10/13/17.
//  Copyright © 2017 Tim Johnsen. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef HEIC_DECODING
#define HEIC_DECODING

/// Returns and NSData HEIC representation of the image if possible, otherwise returns nil.
NSData *_Nullable tj_UIImageHEICRepresentation_resizer(UIImage *const image, const CGFloat compressionQuality);

@interface UIGraphicsImageRenderer (TJHEICAdditions)

- (nullable NSData *)tj_HEICDataWithCompressionQuality:(const CGFloat)compressionQuality
                                               actions:(NS_NOESCAPE UIGraphicsImageDrawingActions)actions;

- (nullable NSData *)tj_HEICDataWithCompressionQuality:(const CGFloat)compressionQuality
           fallingBackToJPEGDataWithCompressionQuality:(const CGFloat)jpegCompressionQuality
                                               actions:(NS_NOESCAPE UIGraphicsImageDrawingActions)actions;

- (nullable NSData *)tj_HEICDataFallingBackToPNGDataWithCompressionQuality:(const CGFloat)compressionQuality
                                                                   actions:(NS_NOESCAPE UIGraphicsImageDrawingActions)actions;

@end

@interface UIDevice (TJHEICAdditions)

+ (BOOL)isHEICWritingSupported;

@end

BOOL tj_CGImageSourceUTIIsHEIC_resizer(const CGImageSourceRef imageSource);
BOOL tj_isImageAtPathHEIC_resizer(NSString *const path);

pthread_mutex_t *tj_HEICEncodingLock_resizer(void);

#endif

NS_ASSUME_NONNULL_END
