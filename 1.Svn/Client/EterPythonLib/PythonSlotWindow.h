//Find
				CAniImageBox * pFinishCoolTimeEffect;

///Add
#if defined(__BL_TRANSMUTATION__)
				std::shared_ptr< CImageBox > pCoverImage;
#endif

//Find
			void RefreshSlot();

///Add
#if defined(__BL_TRANSMUTATION__)
			void SetSlotCoverImage(const DWORD dwIndex, const char* FileName);
			void EnableSlotCoverImage(const DWORD dwIndex, const bool bEnable);
#endif