//Find
			Set(HEADER_GC_EXCHANGE,		CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCExchange), STATIC_SIZE_PACKET));

///Add
#if defined(__BL_TRANSMUTATION__)
			Set(HEADER_GC_CHANGE_LOOK_SET, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCTransmutationItemSet), STATIC_SIZE_PACKET));
			Set(HEADER_GC_CHANGE_LOOK_DEL, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCTransmutationDel), STATIC_SIZE_PACKET));
			Set(HEADER_GC_CHANGE_LOOK_FREE_SET, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCTransmutationItemSet), STATIC_SIZE_PACKET));
			Set(HEADER_GC_CHANGE_LOOK_FREE_DEL, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCTransmutationDel), STATIC_SIZE_PACKET));
#endif