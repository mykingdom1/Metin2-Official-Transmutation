//Find
			DWORD					elk;

///Add
#if defined(__BL_TRANSMUTATION__)
			DWORD					dwTransmutationVnum[EXCHANGE_ITEM_MAX_NUM];
#endif

//Find
		void			SetItemAttributeToSelf(int pos, int iattrpos, BYTE byType, short sValue);

///Add
#if defined(__BL_TRANSMUTATION__)
		void			SetItemChangeLookVnumToSelf(const int pos, const DWORD blVnum);
		void			SetItemChangeLookVnumToTarget(const int pos, const DWORD blVnum);

		DWORD			GetItemChangeLookVnumToSelf(const BYTE pos) const;
		DWORD			GetItemChangeLookVnumToTarget(const BYTE pos) const;
#endif