//Find
	thecore_memcpy(pack.aAttr, pkItem->GetAttributes(), sizeof(pack.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
	pack.dwTransmutationVnum = pkItem->GetTransmutationVnum();
#endif