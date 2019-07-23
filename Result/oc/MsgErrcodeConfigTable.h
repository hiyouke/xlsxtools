#import <Foundation/Foundation.h>
#include <vector>

using namespace std;
@class MsgErrcodeConfig;

@interface MsgErrcodeConfig : NSObject

@property (nonatomic) int m_id;
@property (nonatomic) NSString* m_en;
@property (nonatomic) NSString* m_ch;

+(MsgErrcodeConfig*)ConfigProcess:(NSArray*)rows;

@end

@interface MsgErrcodeConfigTable : NSObject

+ (NSDictionary*)configs;

@end
