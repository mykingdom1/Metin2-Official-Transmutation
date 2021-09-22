//Find
		void	GetItemAttribute(TItemPos Cell, DWORD dwAttrSlotIndex, BYTE * pbyType, short * psValue);

///Add
#if defined(__BL_TRANSMUTATION__)
		void							ClearChangeLook(const bool bClearEffect = false);

		void							SetItemTransmutationVnum(TItemPos& Cell, const DWORD blVnum);
		DWORD							GetItemChangeLookVnum(TItemPos& Cell) const;

		void							SetChangeLookWindowOpen(const bool blOpen);
		bool							GetChangeLookWindowOpen() const;
		void							SetChangeLookWindowType(const bool blType);
		bool							GetChangeLookWindowType() const;

		void							SetChangeLookItemData(TPacketGCTransmutationItemSet& data);
		TPacketGCTransmutationItemSet*		GetChangeLookItemData(const BYTE bSlotType);
		void							DelChangeLookItemData(const BYTE bSlotType, const bool bClearEffect = false);
		
		void							SetChangeLookFreeItemData(TPacketGCTransmutationItemSet& data);
		TPacketGCTransmutationItemSet*		GetChangeLookFreeItemData();
		void							DelChangeLookFreeItemData(const bool bClearEffect = false);
#endif

//Find
		DWORD					m_adwEffect[EFFECT_NUM];

///Add
#if defined(__BL_TRANSMUTATION__)
		bool								bIsChangeLookWindowOpen;
		bool								bChangeLookWindowType;
		TPacketGCTransmutationItemSet		m_ChangeLookSlot[static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX)];
		TPacketGCTransmutationItemSet		m_ChangeLookFreeYangItemSlot;
#endif