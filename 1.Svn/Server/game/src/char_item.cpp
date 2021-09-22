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