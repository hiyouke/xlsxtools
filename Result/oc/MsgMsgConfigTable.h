#import <Foundation/Foundation.h>
#include <vector>

using namespace std;
@class MsgMsgConfig;
@class MsgMsgSellConfig;

@interface MsgMsgConfig : NSObject

@property (nonatomic) int m_id;
@property (nonatomic) NSString* m_title;
@property (nonatomic) NSString* m_content;
@property (nonatomic) vector<MsgMsgSellConfig*> m_sells; // count: 3
@property (nonatomic) vector<int> m_instance; // count: 4
@property (nonatomic) NSString* m_remark;

+(MsgMsgConfig*)ConfigProcess:(NSArray*)rows;

@end

@interface MsgMsgSellConfig : NSObject

@property (nonatomic) int m_num;
@property (nonatomic) int m_id;

+(MsgMsgSellConfig*)ConfigProcess:(NSArray*)rows;

@end

@interface MsgMsgConfigTable : NSObject

+ (NSDictionary*)configs;

@end
