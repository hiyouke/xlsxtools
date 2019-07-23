#import "MsgErrcodeConfigTable.h"

@implementation MsgErrcodeConfig

@synthesize m_id;
@synthesize m_en;
@synthesize m_ch;

+(MsgErrcodeConfig*)ConfigProcess:(NSArray*)rows
{
	if (rows.count != 3) {
		return nil;
	}

	int index = 0;
	MsgErrcodeConfig* newInstance = [[MsgErrcodeConfig alloc] init];

	newInstance.m_id = [rows[index++] intValue];
	newInstance.m_en = rows[index++];
	newInstance.m_ch = rows[index++];

	return newInstance;
}

@end

@implementation MsgErrcodeConfigTable

+ (NSDictionary*)configs
{
	NSMutableDictionary* configs = [NSMutableDictionary dictionary];
	NSString* fileString = [NSString stringWithContentsOfFile:@"Config/Msg_Errcode.txt" encoding:NSUTF8StringEncoding error:nil];
	NSArray* lines = [fileString componentsSeparatedByString:@"\r\n"];

	for (int i = 3; i < lines.count; ++i) {
		NSArray* line = [lines[i] componentsSeparatedByString:@"#"];
		MsgErrcodeConfig* config = [MsgErrcodeConfig ConfigProcess:line];
		[configs setObject:config forKey:[NSNumber numberWithInt:config.m_id]];
	}

	return configs;
}

@end
