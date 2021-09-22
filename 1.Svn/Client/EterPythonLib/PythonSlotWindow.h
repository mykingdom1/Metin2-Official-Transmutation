///Add
#if defined(__BL_TRANSMUTATION__)
#include <array>
#endif

//Find
	enum ESlotStyle
	{
		...
	};
	
///Add
#if defined(__BL_TRANSMUTATION__)
	enum ESlotColor
	{
		COLOR_TYPE_ORANGE,
		COLOR_TYPE_WHITE,
		COLOR_TYPE_RED,
		COLOR_TYPE_GREEN,
		COLOR_TYPE_YELLOW,
		COLOR_TYPE_SKY,
		COLOR_TYPE_PINK,

		COLOR_TYPE_MAX
	};

	enum ESlotHilight
	{
		HILIGHTSLOT_ACCE,
		HILIGHTSLOT_CHANGE_LOOK,
		HILIGHTSLOT_AURA,
		HILIGHTSLOT_CUBE,

		HILIGHTSLOT_MAX
	};
#endif

//Find
				CAniImageBox * pFinishCoolTimeEffect;

///Add
#if defined(__BL_TRANSMUTATION__)
				std::shared_ptr< CImageBox > pCoverImage;
				std::array<std::shared_ptr< CAniImageBox >, 3> pNewSlotEffect;
#endif

//Find
			void RefreshSlot();

///Add
#if defined(__BL_TRANSMUTATION__)
			D3DXCOLOR GetSlotColor(const BYTE blType) const;
			void SetSlotCoverImage(const DWORD dwIndex, const char* FileName);
			void EnableSlotCoverImage(const DWORD dwIndex, const bool bEnable);
			void ActivateNewSlotEffect(const DWORD dwSlotIndex);
			void DeactivateNewSlotEffect(const DWORD dwSlotIndex);
			void SetNewSlotDiffuseColor(const DWORD dwIndex, const BYTE blType);
#endif