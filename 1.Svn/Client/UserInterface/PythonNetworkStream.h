//Find
		bool SendGuildWithdrawMoneyPacket(DWORD dwMoney);

///Add
#if defined(__BL_TRANSMUTATION__)
		bool SendChangeLookCheckInPacket(const TItemPos& pos, const BYTE bSlotType);
		bool SendChangeLookCheckOutPacket(const BYTE bSlotType);
		bool SendChangeLookCheckInFreeYangItemPacket(const TItemPos& pos);
		bool SendChangeLookCheckOutFreeYangItemPacket();
		bool SendChangeLookAcceptPacket();
		bool SendChangeLookCancelPacket();
		bool RecvChangeLookItemSetPacket();
		bool RecvChangeLookItemDelPacket();
		bool RecvChangeLookFreeItemSetPacket();
		bool RecvChangeLookFreeItemDelPacket();
#endif