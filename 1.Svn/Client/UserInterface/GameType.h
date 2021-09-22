//Find
	SLOT_TYPE_DRAGON_SOUL_INVENTORY,

///Add
#if defined(__BL_TRANSMUTATION__)
	SLOT_TYPE_CHANGE_LOOK,
#endif

//Find
enum EDSInventoryMaxNum
{
	...
};

///Add
#if defined(__BL_TRANSMUTATION__)
enum class ETRANSMUTATIONTYPE : BYTE
{
	TRANSMUTATION_TYPE_MOUNT,
	TRANSMUTATION_TYPE_ITEM
};

enum class ETRANSMUTATIONSLOTTYPE : size_t
{
	TRANSMUTATION_SLOT_LEFT,
	TRANSMUTATION_SLOT_RIGHT,

	TRANSMUTATION_SLOT_MAX
};

enum class ETRANSMUTATIONSETTINGS : DWORD
{
	TRANSMUTATION_ITEM_PRICE = 50000000, // 50M
	TRANSMUTATION_MOUNT_PRICE = 30000000, // 30M
	TRANSMUTATION_TICKET_1 = 72326,
	TRANSMUTATION_TICKET_2 = 72341,
	TRANSMUTATION_CLEAR_SCROLL = 72325,
};
#endif

//Find in typedef struct packet_item
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif

//Find in typedef struct packet_shop_item
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
	DWORD		dwTransmutationVnum;
#endif