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

#import "JSMessage.h"

@implementation JSMessage

#pragma mark - Initialization

- (id)initWithText:(NSString *)text
              name:(NSString *)name
            avatar:(UIImageView *)avatar
         timestamp:(NSDate *)timestamp
        bubbleType:(JSBubbleMessageType)type
       bubbleColor:(UIColor *)bubbleColor
         textColor:(UIColor *)textColor
         nameColor:(UIColor *)nameColor
    timestampColor:(UIColor *)timestampColor
{
    self = [super init];
    if(self) {
        self.text = text;
        self.name = name;
        self.avatar = avatar;
        self.timestamp = timestamp;
        self.bubbleType = type;
        self.bubbleColor = bubbleColor;
        self.textColor = textColor;
        self.nameColor = nameColor;
        self.timestampColor = timestampColor;
        self.bubbleImageView = [JSBubbleImageViewFactory bubbleImageViewForType:self.bubbleType color:self.bubbleColor];
        
        _reuseIdentifier = [NSString stringWithFormat:@"JSMessage_%d_%d_%d_%d", (int)type, (BOOL)self.timestamp, (BOOL)self.avatar, (BOOL)self.name];
    }
    return self;
}

- (void)dealloc
{
    _text = nil;
    _name = nil;
    _avatar = nil;
    _timestamp = nil;
}

@end
