//Find
	m_pkChrTarget = NULL;

///Add
#if defined(__BL_TRANSMUTATION__)
	m_pkTransmutation = nullptr;
#endif

//Find
	HorseSummon(false);

///Add
#if defined(__BL_TRANSMUTATION__)
	SetTransmutation(nullptr);
#endif

//Find
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen())

///Change
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
						|| GetTransmutation()
#endif
					)

//Find
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen())

///Change
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
						|| pkChrCauser->GetTransmutation()
#endif
					)

//Find
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen()))

///Change
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen())
#if defined(__BL_TRANSMUTATION__)
						|| GetTransmutation()
#endif
					)

//Find in void CHARACTER::LoadSafebox(int iSize, DWORD dwGold, int iItemCount, TPlayerItem * pItems)
			item->SetAttributes(pItems->aAttr);

///Add
#if defined(__BL_TRANSMUTATION__)
			item->SetTransmutationVnum(pItems->dwTransmutationVnum);
#endif

//Find in void CHARACTER::LoadMall(int iItemCount, TPlayerItem * pItems)
			item->SetAttributes(pItems->aAttr);

///Add
#if defined(__BL_TRANSMUTATION__)
			item->SetTransmutationVnum(pItems->dwTransmutationVnum);
#endif

//Find in void CHARACTER::SendEquipment(LPCHARACTER ch)
			thecore_memcpy(p.equips[i].aAttr, item->GetAttributes(), sizeof(p.equips[i].aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
			p.equips[i].dwTransmutationVnum = item->GetTransmutationVnum();
#endif

//Find in void CHARACTER::SendEquipment(LPCHARACTER ch)
			p.equips[i].vnum = 0;

///Add
#if defined(__BL_TRANSMUTATION__)
			p.equips[i].dwTransmutationVnum = 0;
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
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
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

///Add to end
#if defined(__BL_TRANSMUTATION__)
void CHARACTER::SetTransmutation(CTransmutation* c)
{
	if (m_pkTransmutation != nullptr)
		delete m_pkTransmutation;

	m_pkTransmutation = c;
}

CTransmutation* CHARACTER::GetTransmutation() const
{
	return m_pkTransmutation;
}
#endif