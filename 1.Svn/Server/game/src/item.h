//Find
		void		AddAttribute(BYTE bType, short sValue);

///Add
#if defined(__BL_TRANSMUTATION__)
		void		SetTransmutationVnum(DWORD blVnum);
		DWORD		GetTransmutationVnum() const;
#endif

//Find
		DWORD		m_dwVnum;

///Add
#if defined(__BL_TRANSMUTATION__)
		DWORD		m_dwTransmutationVnum;
#endif