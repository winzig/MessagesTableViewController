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
#import "JSBubbleMessageCell.h"
#import "JSMessageInputView.h"
#import "JSAvatarImageFactory.h"
#import "JSBubbleImageViewFactory.h"
#import "JSMessageSoundEffect.h"
#import "UIColor+JSMessagesView.h"
#import "JSMessage.h"

/**
 *  The delegate of a `JSMessagesViewController` must adopt the `JSMessagesViewDelegate` protocol.
 */
@protocol JSMessagesViewDelegate <NSObject>

@required

/**
 *  Tells the delegate that the specified text has been sent. Hook into your own backend here.
 *
 *  @param text A string containing the text that was present in the messageInputView's textView when the send button was pressed.
 */
- (void)didSendText:(NSString *)text;

/**
 *  Asks the delegate for the input view style.
 *
 *  @return A constant describing the input view style.
 *  @see JSMessageInputViewStyle.
 */
- (JSMessageInputViewStyle)inputViewStyle;

@optional

/**
 *  Tells the delegate to configure or further customize the given cell at the specified index path.
 *
 *  @param cell      The message cell to configure.
 *  @param indexPath The index path for cell.
 */
- (void)configureCell:(JSBubbleMessageCell *)cell atIndexPath:(NSIndexPath *)indexPath;

/**
 *  Asks the delegate if should always scroll to bottom automatically when new messages are sent or received.
 *
 *  @return `YES` if you would like to prevent the table view from being scrolled to the bottom while the user is scrolling the table view manually, `NO` otherwise.
 */
- (BOOL)shouldPreventScrollToBottomWhileUserScrolling;

/**
 *  Asks the delegate for the send button to be used in messageInputView. Implement this method if you wish to use a custom send button. The button must be a `UIButton` or a subclass of `UIButton`. The button's frame is set for you.
 *
 *  @return A custom `UIButton` to use in messageInputView.
 */
- (UIButton *)sendButtonForInputView;

@end



@protocol JSMessagesViewDataSource <NSObject>

@required

/**
 *  Asks the data source for the message to display at the specified index path.
 *
 *  @param indexPath An index path indicating the position of the message requested.
 *
 *  @return A JSMessage object representing the message. This value must not be `nil`,
 *  though you can return null for components of the JSMessage that you don't want to
 *  be displayed, such as the avatar, author name, timestamp, etc.
 */
- (JSMessage *)messageForIndexPath:(NSIndexPath *)indexPath;

@end


/**
 *  An instance of `JSMessagesViewController` is a subclass of `UIViewController` specialized to display a messaging interface.
 */
@interface JSMessagesViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UITextViewDelegate>

/**
 *  The object that acts as the delegate of the receiving messages view.
 */
@property (weak, nonatomic) id<JSMessagesViewDelegate> delegate;

/**
 *  The object that acts as the data source of receiving messages view.
 */
@property (weak, nonatomic) id<JSMessagesViewDataSource> dataSource;

/**
 *  Returns the table view that displays the messages in `JSMessagesViewController`.
 */
@property (weak, nonatomic, readonly) UITableView *tableView;

/**
 *  Returns the message input view with which new messages are composed.
 */
@property (weak, nonatomic, readonly) JSMessageInputView *messageInputView;

#pragma mark - Messages view controller

/**
 *  Animates and resets the text view in messageInputView. Call this method at the end of the delegate method `didSendText:`. 
 *  @see JSMessagesViewDelegate.
 */
- (void)finishSend;


/**
 *  Sets the background color of the table view, the table view cells, and the table view separator.
 *
 *  @param color The color to be used as the new background color.
 */
- (void)setBackgroundColor:(UIColor *)color;

/**
 *  Scrolls the table view such that the bottom most cell is completely visible, above the messageInputView. 
 *
 *  This method respects the delegate method `shouldPreventScrollToBottomWhileUserScrolling`. 
 *
 *  @see JSMessagesViewDelegate.
 *
 *  @param animated `YES` if you want to animate scrolling, `NO` if it should be immediate.
 */
- (void)scrollToBottomAnimated:(BOOL)animated;

/**
 *  Scrolls the receiver until a row identified by index path is at a particular location on the screen. 
 *
 *  This method respects the delegate method `shouldPreventScrollToBottomWhileUserScrolling`. 
 *
 *  @see JSMessagesViewDelegate.
 *
 *  @param indexPath An index path that identifies a row in the table view by its row index and its section index.
 *  @param position  A constant defined in `UITableViewScrollPosition` that identifies a relative position in the receiving table view.
 *  @param animated  `YES` if you want to animate the change in position, `NO` if it should be immediate.
 */
- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath
			  atScrollPosition:(UITableViewScrollPosition)position
					  animated:(BOOL)animated;

@end