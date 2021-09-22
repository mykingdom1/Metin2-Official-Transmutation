//Find
		void	Update(const POINT& c_rkPtMouse);

///Add
#if defined(__BL_TRANSMUTATION__)
		bool	CanAddChangeLookItem(const CItemData* item, const CItemData* other_item) const;
		bool	CanAddChangeLookFreeItem(const DWORD dwVnum) const;
		bool	IsChangeLookClearScrollItem(const DWORD dwVnum) const;
#endif