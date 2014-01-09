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
//  Copyright (c) 2013 Jesse Squires
//  http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>
#import "JSBubbleView.h"
#import "JSMessage.h"

/**
 *  The `JSBubbleMessageCell` class defines the attributes and behavior of the cells that appear in `JSMessagesViewController`. This class includes properties and methods for setting and managing cell content.
 */
@interface JSBubbleMessageCell : UITableViewCell

/**
 *  Returns the bubble view used in the cell. JSBubbleMessageCell adds the appropriate bubble view when you create the cell with a given cell type and bubbleImageView. This property is never `nil`. 
 *  @see JSBubbleView. 
 *  @see JSBubbleMessageType.
 */
@property (weak, nonatomic, readonly) JSBubbleView *bubbleView;

/**
 *  Returns the label used to display the timestamp for the cell. This property may be `nil` if no timestamp is provided. 
 *  @see JSMessagesViewDataSource.
 */
@property (weak, nonatomic, readonly) UILabel *timestampLabel;

/**
 *  Returns the image view used to display the avatar for the cell. This property may be `nil` if no avatar is provided. 
 *  @see JSMessagesViewDataSource.
 */
@property (weak, nonatomic, readonly) UIImageView *avatarImageView;

/**
 *  Returns the label used to display the subtitle for the cell. This property may be `nil` if no subtitle is provided. 
 *  @see JSMessagesViewDataSource.
 */
@property (weak, nonatomic, readonly) UILabel *nameLabel;

#pragma mark - Initialization

/**
 *  Initializes a message cell and returns it to the caller.
 *
 *  @param message         The JSMessage to use for this cell. @see JSBubbleMessageType for details.
 *
 *  @return An initialized `JSBubbleMessageCell` object or `nil` if the object could not be created.
 */
- (instancetype)initWithMessage:(JSMessage*)message;

#pragma mark - Setters

/**
 *  Sets the message to be displayed in the bubbleView of the cell.
 *
 *  @param msg The message text for the cell.
 */
- (void)setMessage:(NSString *)msg;

/**
 *  Sets the date to be displayed in the timestampLabel of the cell. The date is formatted for you via `NSDateFormatter` by `JSBubbleMessageCell`.
 *
 *  @param date The date for the cell.
 */
- (void)setTimestamp:(NSDate *)date;

/**
 *  Sets the imageView for the avatarImageView of the cell. The frame is set for you by `JSBubbleMessageCell`.
 *
 *  @param imageView An imageView containing an avatar image. The `image` property of the `UIImageView` must not be `nil`.
 */
- (void)setAvatarImageView:(UIImageView *)imageView;

/**
 *  Sets the text to be displayed in the subtitleLabel of the cell.
 *
 *  @param subtitle The subtitle text for the cell.
 */
- (void)setName:(NSString *)name;

#pragma mark - Getters

/**
 *  Returns a contant indicating the message type for the cell. 
 *  @see JSBubbleMessageType.
 *
 *  @return A contant indicating the message type.
 */
- (JSBubbleMessageType)messageType;

#pragma mark - Class methods

/**
 *  Computes and returns the minimum necessary height of a `JSBubbleMessageCell` needed to display its contents.
 *
 *  @param message      The JSMessage to display
 *
 *  @return The height required for the frame of the cell in order for the cell to display the entire contents of its subviews.
 */
+ (CGFloat)neededHeightForBubbleMessageCellWithMessage:(JSMessage *)message;

@end