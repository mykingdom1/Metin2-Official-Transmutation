//Find
#ifdef __AUCTION__
	HEADER_CG_AUCTION_CMD							= 205,
#endif

///Add
#if defined(__BL_TRANSMUTATION__)
	HEADER_CG_CHANGE_LOOK = 228,
#endif

//Find
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,

///Add
#if defined(__BL_TRANSMUTATION__)
	HEADER_GC_CHANGE_LOOK_SET = 228,
	HEADER_GC_CHANGE_LOOK_DEL = 229,
	HEADER_GC_CHANGE_LOOK_FREE_SET = 230,
	HEADER_GC_CHANGE_LOOK_FREE_DEL = 231,
#endif

//Find
typedef struct command_shop
{
	...
} TPacketCGShop;

///Add
#if defined(__BL_TRANSMUTATION__)
enum class ECG_TRANSMUTATION_SHEADER: BYTE
{
	ITEM_CHECK_IN,
	ITEM_CHECK_OUT,
	FREE_ITEM_CHECK_IN,
	FREE_ITEM_CHECK_OUT,
	ACCEPT,
	CANCEL
};

typedef struct packet_set_transmutation
{
	BYTE		header;
	WORD		wCell;
	BYTE		bSlotType;
} TPacketGCTransmutationItemSet;

typedef struct packet_transmutation_del
{
	BYTE        header;
	WORD        wCell;
	BYTE        bSlotType;
} TPacketGCTransmutationDel;

typedef struct command_transmutation
{
	command_transmutation(const BYTE _Sub) :
		header(HEADER_CG_CHANGE_LOOK),
		subheader(_Sub),
		slot_type(255)
	{}
	BYTE		header;
	BYTE		subheader;
	BYTE		slot_type;
	TItemPos	pos;
} TPacketCGTransmutation;
#endif

//Find in struct TPacketGCItemDelDeprecate
        count(0),

///Add
#if defined(__BL_TRANSMUTATION__)
		dwTransmutationVnum(0),
#endif

//Find in struct TPacketGCItemDelDeprecate
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD	dwTransmutationVnum;
#endif

//Find in typedef struct packet_set_item (x2)
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif

//Find in typedef struct packet_set_item2
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif

//Find in typedef struct packet_update_item
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif

//Find in typedef struct packet_exchange
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif

//Find in typedef struct SEquipmentItemSet
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD	dwTransmutationVnum;
#endif