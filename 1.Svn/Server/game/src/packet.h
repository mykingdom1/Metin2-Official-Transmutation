//Find
	HEADER_CG_STATE_CHECKER					= 206,

///Add
#if defined(__BL_TRANSMUTATION__)
	HEADER_CG_TRANSMUTATION = 228,
#endif

//Find
	HEADER_GC_RESPOND_CHANNELSTATUS			= 210,

///Add
#if defined(__BL_TRANSMUTATION__)
	HEADER_GC_TRANSMUTATION_SET = 228,
	HEADER_GC_TRANSMUTATION_DEL = 229,
	HEADER_GC_TRANSMUTATION_FREE_SET = 230,
	HEADER_GC_TRANSMUTATION_FREE_DEL = 231,
#endif

//Find
typedef struct command_position
{
	...
} TPacketCGPosition;

///Add
#if defined(__BL_TRANSMUTATION__)
enum class ECG_TRANSMUTATION_SHEADER : BYTE
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
	BYTE		header;
	BYTE		subheader;
	BYTE		slot_type;
	TItemPos	pos;
} TPacketCGTransmutation;
#endif

//Find in struct TPacketGCItemDelDeprecated
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD	dwTransmutationVnum;
#endif

//Find in typedef struct packet_item_set
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD	dwTransmutationVnum;
#endif

//Find in typedef struct packet_item_update
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD	dwTransmutationVnum;
#endif

//Find in struct packet_shop_item
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif

//Find in struct packet_exchange
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD	dwTransmutationVnum;
#endif

//Find in typedef struct pakcet_view_equip
		TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
		DWORD	dwTransmutationVnum;
#endif