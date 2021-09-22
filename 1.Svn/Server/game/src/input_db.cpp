//Find
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
		|| ch->GetTransmutation()
#endif
	)
	
//Find
		item->SetAttributes(p->aAttr);

///Add
#if defined(__BL_TRANSMUTATION__)
		item->SetTransmutationVnum(p->dwTransmutationVnum);
#endif