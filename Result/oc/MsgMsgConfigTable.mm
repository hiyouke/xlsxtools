#import "MsgMsgConfigTable.h"

@implementation MsgMsgConfig

@synthesize m_id;
@synthesize m_title;
@synthesize m_content;
@synthesize m_sells;
@synthesize m_instance;
@synthesize m_remark;

+(MsgMsgConfig*)ConfigProcess:(NSArray*)rows
{
	if (rows.count != 14) {
		return nil;
	}

	int index = 0;
	MsgMsgConfig* newInstance = [[MsgMsgConfig alloc] init];

	newInstance.m_id = [rows[index++] intValue];
	newInstance.m_title = rows[index++];
	newInstance.m_content = rows[index++];

    vector<MsgMsgSellConfig *> m_sells_vector;
    for (int i = 0; i < 3; i++) 
    {
        m_sells_vector.push_back([MsgMsgSellConfig ConfigProcess:[rows subarrayWithRange:NSMakeRange(index, 2)]]);
        index += 2;
    }
    newInstance.m_sells = m_sells_vector;
    

    vector<int> m_instance_vector;
    for (int i = 0; i < 4; i++) 
    {
        m_instance_vector.m_instance.push_back([rows[index++] intValue]);
    }
    newInstance.m_instance = m_instance_vector;
    
	newInstance.m_remark = rows[index++];

	return newInstance;
}

@end

@implementation MsgMsgSellConfig

@synthesize m_num;
@synthesize m_id;

+(MsgMsgSellConfig*)ConfigProcess:(NSArray*)rows
{
	if (rows.count != 2) {
		return nil;
	}

	int index = 0;
	MsgMsgSellConfig* newInstance = [[MsgMsgSellConfig alloc] init];

	newInstance.m_num = [rows[index++] intValue];
	newInstance.m_id = [rows[index++] intValue];

	return newInstance;
}

@end

@implementation MsgMsgConfigTable

+ (NSDictionary*)configs
{
    NSMutableDictionary* configs = [NSMutableDictionary dictionary];
    NSString * path = [[NSBundle mainBundle] pathForResource:@"Config/Msg_Msg.txt" ofType:nil];
    NSString* fileString = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
    NSArray* lines = [fileString componentsSeparatedByString:@"\r\n"];
    for (int i = 3; i < lines.count; ++i) 
    {
        NSArray* line = [lines[i] componentsSeparatedByString:@"#"];
        if([line count] > 1)
        {
            MsgMsgConfig* config = [MsgMsgConfig ConfigProcess:line];
            [configs setObject:config forKey:[NSNumber numberWithInt:config.m_id]];
        }
    }
    return configs;
}

@end
