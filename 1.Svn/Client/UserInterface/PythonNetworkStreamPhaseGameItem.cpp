//Find in bool CPythonNetworkStream::RecvSafeBoxSetPacket()
	for (int iattr=0; iattr<ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++iattr)
		kItemData.aAttr[iattr] = kItemSet.aAttr[iattr];

///Add
#if defined(__BL_TRANSMUTATION__)
	kItemData.dwTransmutationVnum = kItemSet.dwTransmutationVnum;
#endif

//Find in bool CPythonNetworkStream::RecvMallItemSetPacket()
	for (int iattr=0; iattr<ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++iattr)
		kItemData.aAttr[iattr] = kItemSet.aAttr[iattr];

///Add
#if defined(__BL_TRANSMUTATION__)
	kItemData.dwTransmutationVnum = kItemSet.dwTransmutationVnum;
#endif

//Find in bool CPythonNetworkStream::RecvItemSetPacket()
	for (int j=0; j<ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++j)
		kItemData.aAttr[j]=packet_item_set.aAttr[j];

///Add
#if defined(__BL_TRANSMUTATION__)
	kItemData.dwTransmutationVnum = packet_item_set.dwTransmutationVnum;
#endif

//Find in bool CPythonNetworkStream::RecvItemSetPacket2()
	for (int j=0; j<ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++j)
		kItemData.aAttr[j]=packet_item_set.aAttr[j];

///Add
#if defined(__BL_TRANSMUTATION__)
	kItemData.dwTransmutationVnum = packet_item_set.dwTransmutationVnum;
#endif

//Find in bool CPythonNetworkStream::RecvItemUpdatePacket()
	for (int j = 0; j < ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++j)
		rkPlayer.SetItemAttribute(packet_item_update.Cell, j, packet_item_update.aAttr[j].bType, packet_item_update.aAttr[j].sValue);

///Add
#if defined(__BL_TRANSMUTATION__)
	rkPlayer.SetItemTransmutationVnum(packet_item_update.Cell, packet_item_update.dwTransmutationVnum);
#endif