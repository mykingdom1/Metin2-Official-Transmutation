//Find
		thecore_memcpy(&pack_exchg.aAttr, ((LPITEM)pvData)->GetAttributes(), sizeof(pack_exchg.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
		pack_exchg.dwTransmutationVnum = static_cast<LPITEM>(pvData)->GetTransmutationVnum();
#endif

//Find
		memset(&pack_exchg.aAttr, 0, sizeof(pack_exchg.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
		pack_exchg.dwTransmutationVnum = 0;
#endif

//Find
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen() )

///Change
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
		|| GetTransmutation()
#endif
	)

//Find
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen() )

///Change
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
		|| victim->GetTransmutation()
#endif
	)