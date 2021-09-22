//Find
			thecore_memcpy(pack2.items[i].aAttr, item.pkItem->GetAttributes(), sizeof(pack2.items[i].aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
			pack2.items[i].dwTransmutationVnum = item.pkItem->GetTransmutationVnum();
#endif

//Find
			thecore_memcpy(pack2.item.aAttr, m_itemVector[pos].pkItem->GetAttributes(), sizeof(pack2.item.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
			pack2.item.dwTransmutationVnum = m_itemVector[pos].pkItem->GetTransmutationVnum();
#endif

//Find
			memset(pack2.item.aAttr, 0, sizeof(pack2.item.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
			pack2.item.dwTransmutationVnum = 0;
#endif