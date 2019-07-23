#import "ItemItemConfigTable.h"

@implementation ItemItemConfig

@synthesize m_id;
@synthesize m_name;
@synthesize m_desc;
@synthesize m_gain;
@synthesize m_type;
@synthesize m_overlap;
@synthesize m_usetype;
@synthesize m_usevalue;
@synthesize m_use_times;
@synthesize m_cansell;
@synthesize m_sells;
@synthesize m_head;
@synthesize m_model;
@synthesize m_star;
@synthesize m_linkid;

+(ItemItemConfig*)ConfigProcess:(NSArray*)rows
{
	if (rows.count != 19) {
		return nil;
	}

	int index = 0;
	ItemItemConfig* newInstance = [[ItemItemConfig alloc] init];

	newInstance.m_id = [rows[index++] intValue];
	newInstance.m_name = rows[index++];
	newInstance.m_desc = rows[index++];
	newInstance.m_gain = rows[index++];
	newInstance.m_type = [rows[index++] intValue];
	newInstance.m_overlap = [rows[index++] intValue];
	newInstance.m_usetype = [rows[index++] intValue];
	for (int i = 0; i < 2; ++i) {
		newInstance.m_usevalue[i] = [rows[index++] intValue];
	}
	newInstance.m_use_times = [rows[index++] intValue];
	newInstance.m_cansell = [rows[index++] intValue];
	for (int i = 0; i < 2; ++i) {
		newInstance.m_sells[i] = [ItemItemSellConfig ConfigProcess:[rows subarrayWithRange:NSMakeRange(index, 2)]];
		index += 2;
	}
	newInstance.m_head = rows[index++];
	newInstance.m_model = rows[index++];
	newInstance.m_star = [rows[index++] intValue];
	newInstance.m_linkid = [rows[index++] intValue];

	return newInstance;
}

@end

@implementation ItemItemSellConfig

@synthesize m_num;
@synthesize m_id;

+(ItemItemSellConfig*)ConfigProcess:(NSArray*)rows
{
	if (rows.count != 2) {
		return nil;
	}

	int index = 0;
	ItemItemSellConfig* newInstance = [[ItemItemSellConfig alloc] init];

	newInstance.m_num = [rows[index++] intValue];
	newInstance.m_id = [rows[index++] intValue];

	return newInstance;
}

@end

@implementation ItemItemConfigTable

+ (NSDictionary*)configs
{
	NSMutableDictionary* configs = [NSMutableDictionary dictionary];
	NSString* fileString = [NSString stringWithContentsOfFile:@"Config/Item_Item.txt" encoding:NSUTF8StringEncoding error:nil];
	NSArray* lines = [fileString componentsSeparatedByString:@"\r\n"];

	for (int i = 3; i < lines.count; ++i) {
		NSArray* line = [lines[i] componentsSeparatedByString:@"#"];
		ItemItemConfig* config = [ItemItemConfig ConfigProcess:line];
		[configs setObject:config forKey:[NSNumber numberWithInt:config.m_id]];
	}

	return configs;
}

@end
