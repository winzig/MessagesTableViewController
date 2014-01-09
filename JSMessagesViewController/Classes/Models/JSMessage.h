//
//  Created by Jesse Squires
//  http://www.hexedbits.com
//
//
//  Documentation
//  http://cocoadocs.org/docsets/JSMessagesViewController
//
//
//  The MIT License
//  Copyright (c) 2014 Jesse Squires, et. al.
//  http://opensource.org/licenses/MIT
//

#import <Foundation/Foundation.h>

#import "JSBubbleImageViewFactory.h"

@interface JSMessage : NSObject

/**
 *  The timestamp for the message, or nil if we don't want to show the timestamp for this message.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) NSDate *timestamp;

/**
 *  The text of the message, or nil if we don't want a bubble to appear (not sure why you'd want that).
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) NSString *text;

/**
 *  The avatar image for the message, or nil if we don't want to show the avatar for this message.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) UIImageView *avatar;

/**
 *  The name for the author of the message, or nil if we don't want to show the name for this message.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) NSString *name;

/**
 *  The type of message bubble.
 *  @see JSBubbleMessageType.
 *  @see JSMessagesViewController.
 */
@property JSBubbleMessageType bubbleType;

/**
 *  The color for the message bubble.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) UIColor *bubbleColor;

/**
 *  The color for the message text, or nil to use the default.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) UIColor *textColor;

/**
 *  The color for the message author's name, or nil to use the default.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) UIColor *nameColor;

/**
 *  The color for the message timestamp, or nil to use the default.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) UIColor *timestampColor;

/**
 *  The name for the author of the message, or nil if we don't want to show the name for this message.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic) UIImageView *bubbleImageView;

/**
 *  Useful when implementing messages in things like UITableViews, as this should give you
 *  a unique identifier representing the 'state' of this message, i.e. whether it will be
 *  displaying a timestamp, text message, avatar, and/or name.
 *  @see JSMessagesViewController.
 */
@property (strong, nonatomic, readonly) NSString *reuseIdentifier;

- (id)initWithText:(NSString *)text
              name:(NSString *)name
            avatar:(UIImageView *)avatar
         timestamp:(NSDate *)timestamp
        bubbleType:(JSBubbleMessageType)type
       bubbleColor:(UIColor *)bubbleColor
         textColor:(UIColor *)textColor
         nameColor:(UIColor *)nameColor
    timestampColor:(UIColor *)timestampColor;

@end
