//Find
		virtual void	SetItemAttribute(TItemPos itemPos, DWORD dwAttrIndex, BYTE byType, short sValue) = 0;

///Add
#if defined(__BL_TRANSMUTATION__)
		virtual void	SetItemTransmutationVnum(TItemPos& Cell, const DWORD blVnum) = 0;
#endif