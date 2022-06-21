//Find
	if (IsCubeOpen() || NULL != DragonSoul_RefineWindow_GetOpener())
		return false;

///Add
#if defined(__BL_TRANSMUTATION__)
	if (GetTransmutation())
		return false;
#endif

//Find
			thecore_memcpy(pack.aAttr, pItem->GetAttributes(), sizeof(pack.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
			pack.dwTransmutationVnum = pItem->GetTransmutationVnum();
#endif

//Find
			memset(pack.aAttr, 0, sizeof(pack.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
			pack.dwTransmutationVnum = 0;
#endif

//Find
					case USE_SPECIAL:
						
						switch (item->GetVnum())
						{

///Add
#if defined(__BL_TRANSMUTATION__)
						case TRANSMUTATION_REVERSAL:
							LPITEM item2;
							if (!IsValidItemPosition(DestCell) || !(item2 = GetItem(DestCell)))
								return false;

							if (item2->IsExchanging())
								return false;
							
							if (item2->isLocked())
								return false;

							if (item2->GetTransmutationVnum() == 0)
								return false;

							item2->SetTransmutationVnum(0);
							item2->UpdatePacket();

							item->SetCount(item->GetCount() - 1);
							break;
#endif

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
			|| GetTransmutation()
#endif
		)

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
			|| GetTransmutation()
#endif
		)

// Find
	if (false == FN_check_item_sex(this, item))
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("성별이 맞지않아 이 아이템을 사용할 수 없습니다."));
		return false;
	}

///Add below
#if defined(__BL_TRANSMUTATION__) && defined(__COSTUME_SYSTEM__)
	DWORD dwTransmutationVnum = item->GetTransmutationVnum();
	if (dwTransmutationVnum != 0)
	{
		TItemTable* pItemTable = ITEM_MANAGER::instance().GetTable(dwTransmutationVnum);
		if (pItemTable && (pItemTable->GetType() == ITEM_COSTUME))
		{
			if ((IS_SET(pItemTable->GetAntiFlags(), ITEM_ANTIFLAG_MALE) && SEX_MALE == GET_SEX(this)) ||
				(IS_SET(pItemTable->GetAntiFlags(), ITEM_ANTIFLAG_FEMALE) && SEX_FEMALE == GET_SEX(this)))
			{
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Transmutation] You cannot equip the transmuted item as it does not match your gender."));
				return false;
			}
		}
	}
#endif

// Find
	if (FN_check_item_sex(this, item) == false)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("성별이 맞지않아 이 아이템을 사용할 수 없습니다."));
		return false;
	}

///Add below
#if defined(__BL_TRANSMUTATION__) && defined(__COSTUME_SYSTEM__)
	DWORD dwTransmutationVnum = item->GetTransmutationVnum();
	if (dwTransmutationVnum != 0)
	{
		TItemTable* pItemTable = ITEM_MANAGER::instance().GetTable(dwTransmutationVnum);
		if (pItemTable && (pItemTable->GetType() == ITEM_COSTUME))
		{
			if ((IS_SET(pItemTable->GetAntiFlags(), ITEM_ANTIFLAG_MALE) && SEX_MALE == GET_SEX(this)) ||
				(IS_SET(pItemTable->GetAntiFlags(), ITEM_ANTIFLAG_FEMALE) && SEX_FEMALE == GET_SEX(this)))
			{
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Transmutation] You cannot equip the transmuted item as it does not match your gender."));
				return false;
			}
		}
	}
#endif
