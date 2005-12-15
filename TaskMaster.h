/*
 *  $Id: TaskMaster.h 205 2005-12-05 06:04:34Z me $
 *
 *  Copyright (C) 2005 Stephen F. Booth <me@sbooth.org>
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#import <Cocoa/Cocoa.h>

#import "Track.h"
#import "CompactDiscDocument.h"
#import "RipperTask.h"
#import "ConverterTask.h"
#import "EncoderTask.h"
#import "RipperController.h"
#import "ConverterController.h"
#import "EncoderController.h"

@interface TaskMaster : NSObject
{
	RipperController		*_ripperController;
	ConverterController		*_converterController;
	EncoderController		*_encoderController;
	
	NSMutableArray			*_rippingTasks;
	NSMutableArray			*_convertingTasks;
	NSMutableArray			*_encodingTasks;
}

+ (TaskMaster *)	sharedController;

- (BOOL)			hasTasks;
- (BOOL)			hasRippingTasks;
- (BOOL)			hasConvertingTasks;
- (BOOL)			hasEncodingTasks;

- (IBAction)		stopAllRippingTasks:(id)sender;
- (IBAction)		stopAllConvertingTasks:(id)sender;
- (IBAction)		stopAllEncodingTasks:(id)sender;
- (IBAction)		stopAllTasks:(id)sender;

- (BOOL)			compactDiscDocumentHasRippingTasks:(CompactDiscDocument *)document;
- (void)			stopRippingTasksForCompactDiscDocument:(CompactDiscDocument *)document;

- (void)			encodeTrack:(Track *)track outputBasename:(NSString *)basename;
- (void)			encodeTracks:(NSArray *)tracks outputBasename:(NSString *)basename;

- (void)			encodeFile:(NSString *)filename outputBasename:(NSString *)basename;

- (void)			displayExceptionSheet:(NSException *) exception;
- (void)			alertDidEnd:(NSAlert *) alert returnCode:(int) returnCode contextInfo:(void *) contextInfo;

- (void)			ripDidStart:(RipperTask *) task;
- (void)			ripDidStop:(RipperTask *) task;
- (void)			ripDidComplete:(RipperTask *) task;

- (void)			convertDidStart:(ConverterTask *) task;
- (void)			convertDidStop:(ConverterTask *) task;
- (void)			convertDidComplete:(ConverterTask *) task;

- (void)			encodeDidStart:(EncoderTask *) task;
- (void)			encodeDidStop:(EncoderTask *) task;
- (void)			encodeDidComplete:(EncoderTask *) task;

@end
