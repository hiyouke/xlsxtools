#import <Foundation/Foundation.h>
#include <vector>

using namespace std;
@class ItemItemConfig;
@class ItemItemSellConfig;

@interface ItemItemConfig : NSObject

@property (nonatomic) int m_id;
@property (nonatomic) NSString* m_name;
@property (nonatomic) NSString* m_desc;
@property (nonatomic) NSString* m_gain;
@property (nonatomic) int m_type;
@property (nonatomic) int m_overlap;
@property (nonatomic) int m_usetype;
@property (nonatomic) vector<int> m_usevalue; // count: 2
@property (nonatomic) int m_use_times;
@property (nonatomic) int m_cansell;
@property (nonatomic) vector<ItemItemSellConfig*> m_sells; // count: 2
@property (nonatomic) NSString* m_head;
@property (nonatomic) NSString* m_model;
@property (nonatomic) int m_star;
@property (nonatomic) int m_linkid;

(ItemItemConfig*)ConfigProcess:(NSArray*)rows;

@end

@interface ItemItemSellConfig : NSObject

@property (nonatomic) int m_num;
@property (nonatomic) int m_id;

(ItemItemSellConfig*)ConfigProcess:(NSArray*)rows;

@end

@interface ItemItemConfigTable : NSObject

+ (NSDictionary*)configs;

@end
