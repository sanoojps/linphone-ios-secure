/* ImageSharing.h
 *
 * Copyright (C) 2012  Belledonne Comunications, Grenoble, France
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#import <Foundation/Foundation.h>

@class ImageSharing;

@protocol ImageSharingDelegate <NSObject>

- (void)imageSharingProgress:(ImageSharing*)imageSharing progress:(float)progress;
- (void)imageSharingAborted:(ImageSharing*)imageSharing;
- (void)imageSharingError:(ImageSharing*)imageSharing error:(NSError *)error;
- (void)imageSharingUploadDone:(ImageSharing*)imageSharing url:(NSURL*)url;
- (void)imageSharingDownloadDone:(ImageSharing*)imageSharing image:(UIImage *)image;

@end

@interface ImageSharing : NSObject<NSURLConnectionDataDelegate> {
@private
    NSInteger totalBytesExpectedToRead;
    id<ImageSharingDelegate> delegate;
    int statusCode;
}

+ (id)imageSharingUpload:(NSURL*)url image:(UIImage*)image delegate:(id<ImageSharingDelegate>)delegate userInfo:(id)userInfo;
+ (id)imageSharingDownload:(NSURL*)url delegate:(id<ImageSharingDelegate>)delegate userInfo:(id)userInfo;

- (void)cancel;

@property (nonatomic, retain) id userInfo;

@property (nonatomic, readonly) BOOL upload;
@property (nonatomic, readonly) NSMutableData* data;
@property (nonatomic, readonly) NSURLConnection* connection;

@end
