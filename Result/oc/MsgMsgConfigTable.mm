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
	for (int i = 0; i < 3; ++i) {
		newInstance.m_sells[i] = [MsgMsgSellConfig ConfigProcess:[rows subarrayWithRange:NSMakeRange(index, 2)]];
		index += 2;
	}
	for (int i = 0; i < 4; ++i) {
		newInstance.m_instance[i] = [rows[index++] intValue];
	}
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
	NSString* fileString = [NSString stringWithContentsOfFile:@"Config/Msg_Msg.txt" encoding:NSUTF8StringEncoding error:nil];
	NSArray* lines = [fileString componentsSeparatedByString:@"\r\n"];

	for (int i = 3; i < lines.count; ++i) {
		NSArray* line = [lines[i] componentsSeparatedByString:@"#"];
		MsgMsgConfig* config = [MsgMsgConfig ConfigProcess:line];
		[configs setObject:config forKey:[NSNumber numberWithInt:config.m_id]];
	}

	return configs;
}

@end
