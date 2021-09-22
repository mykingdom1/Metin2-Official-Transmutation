//Find
		len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x", 
				pPlayerItem->vnum, pPlayerItem->flags,
				pPlayerItem->alSockets[0], pPlayerItem->alSockets[1], pPlayerItem->alSockets[2]);

///Add
#if defined(__BL_TRANSMUTATION__)
		len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x",
			pPlayerItem->dwTransmutationVnum);
#endif

//Find
PyObject * playerSlotTypeToInvenType(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
PyObject* playerGetChangeLookVnum(PyObject* poSelf, PyObject* poArgs)
{
	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
		return Py_BuildException();

	return Py_BuildValue("i", CPythonPlayer::Instance().GetItemChangeLookVnum(Cell));
}

PyObject* playerSetChangeLookWindow(PyObject* poSelf, PyObject* poArgs)
{
	bool blOpen;
	if (!PyTuple_GetBoolean(poArgs, 0, &blOpen))
		return Py_BadArgument();

	CPythonPlayer::Instance().SetChangeLookWindowOpen(blOpen);

	return Py_BuildNone();
}

PyObject* playerGetChangeLookWindowOpen(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("b", CPythonPlayer::Instance().GetChangeLookWindowOpen());
}

PyObject* playerSetChangeLookWindowType(PyObject* poSelf, PyObject* poArgs)
{
	bool blType;
	if (!PyTuple_GetBoolean(poArgs, 0, &blType))
		return Py_BadArgument();

	CPythonPlayer::Instance().SetChangeLookWindowType(blType);

	return Py_BuildNone();
}

PyObject* playerGetChangeLookItemID(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	if (bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return Py_BuildException();

	const TPacketGCTransmutationItemSet* item = CPythonPlayer::Instance().GetChangeLookItemData(bSlotType);
	if (!item)
		return Py_BuildValue("i", 0);

	const TItemData* pPlayerItem = CPythonPlayer::Instance().GetItemData(TItemPos(INVENTORY, item->wCell));
	if (!pPlayerItem)
		return Py_BuildValue("i", 0);

	return Py_BuildValue("i", pPlayerItem->vnum);
}

PyObject* playerGetChangeLookItemInvenSlot(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	if (bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return Py_BuildException();

	const TPacketGCTransmutationItemSet* item = CPythonPlayer::Instance().GetChangeLookItemData(bSlotType);
	if (item)
		return Py_BuildValue("i", item->wCell);

	return Py_BuildValue("i", 0);
}

PyObject* playerGetChangeLookFreeYangItemID(PyObject* poSelf, PyObject* poArgs)
{
	const TPacketGCTransmutationItemSet* item = CPythonPlayer::Instance().GetChangeLookFreeItemData();
	if (!item)
		return Py_BuildValue("i", 0);

	const TItemData* pPlayerItem = CPythonPlayer::Instance().GetItemData(TItemPos(INVENTORY, item->wCell));
	if (!pPlayerItem)
		return Py_BuildValue("i", 0);

	return Py_BuildValue("i", pPlayerItem->vnum);
}

PyObject* playerGetChangeLookFreeYangInvenSlotPos(PyObject* poSelf, PyObject* poArgs)
{
	const TPacketGCTransmutationItemSet* item = CPythonPlayer::Instance().GetChangeLookFreeItemData();
	if (item)
		return Py_BuildValue("i", item->wCell);

	return Py_BuildValue("i", 0);
}

PyObject* playerCanChangeLookClearItem(PyObject* poSelf, PyObject* poArgs)
{
	int iItemVID;
	if (!PyTuple_GetInteger(poArgs, 0, &iItemVID))
		return Py_BadArgument();

	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 1, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 2, &Cell.cell))
		return Py_BuildException();

	CItemManager::Instance().SelectItemData(iItemVID);
	CItemData* pItemData = CItemManager::Instance().GetSelectedItemDataPointer();

	if (!pItemData)
		return Py_BuildException("Can't find select item data");

	const TItemData* pPlayerItem = CPythonPlayer::Instance().GetItemData(Cell);
	if (pPlayerItem)
		return Py_BuildValue("b", pPlayerItem->dwTransmutationVnum != 0);

	return Py_BuildValue("b", false);
}

PyObject* playerGetChangeWIndowChangeLookVnum(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bSlotType))
		return Py_BadArgument();

	if (bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return Py_BuildException();

	const TPacketGCTransmutationItemSet* item = CPythonPlayer::Instance().GetChangeLookItemData(bSlotType);
	if (!item)
		return Py_BuildValue("i", 0);

	const TItemData* pPlayerItem = CPythonPlayer::Instance().GetItemData(TItemPos(INVENTORY, item->wCell));
	if (!pPlayerItem)
		return Py_BuildValue("i", 0);

	return Py_BuildValue("i", pPlayerItem->dwTransmutationVnum);
}

PyObject* playerGetChangeChangeLookPrice(PyObject* poSelf, PyObject* poArgs)
{
	const bool bType = CPythonPlayer::Instance().GetChangeLookWindowType();
	switch (static_cast<ETRANSMUTATIONTYPE>(bType))
	{
	case ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_MOUNT:
		return Py_BuildValue("i", static_cast<DWORD>(ETRANSMUTATIONSETTINGS::TRANSMUTATION_MOUNT_PRICE));
	case ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_ITEM:
		return Py_BuildValue("i", static_cast<DWORD>(ETRANSMUTATIONSETTINGS::TRANSMUTATION_ITEM_PRICE));
	}

	return Py_BuildValue("i", 0);
}
#endif

//Find
		{ "SendDragonSoulRefine",		playerSendDragonSoulRefine,			METH_VARARGS },

///Add
#if defined(__BL_TRANSMUTATION__)
		{ "GetChangeLookVnum", playerGetChangeLookVnum, METH_VARARGS },

		{ "SetChangeLookWindow", playerSetChangeLookWindow, METH_VARARGS },
		{ "GetChangeLookWindowOpen", playerGetChangeLookWindowOpen, METH_VARARGS },

		{ "SetChangeLookWindowType", playerSetChangeLookWindowType, METH_VARARGS },
		
		{ "GetChangeLookItemID", playerGetChangeLookItemID, METH_VARARGS },
		{ "GetChangeLookItemInvenSlot", playerGetChangeLookItemInvenSlot, METH_VARARGS },
		
		{ "GetChangeLookFreeYangItemID", playerGetChangeLookFreeYangItemID, METH_VARARGS },
		{ "GetChangeLookFreeYangInvenSlotPos", playerGetChangeLookFreeYangInvenSlotPos, METH_VARARGS },

		{ "CanChangeLookClearItem", playerCanChangeLookClearItem, METH_VARARGS },
		{ "GetChangeWIndowChangeLookVnum", playerGetChangeWIndowChangeLookVnum, METH_VARARGS },
		{ "GetChangeChangeLookPrice", playerGetChangeChangeLookPrice, METH_VARARGS },
#endif

//Find
	PyModule_AddIntConstant(poModule, "SLOT_TYPE_DRAGON_SOUL_INVENTORY",	SLOT_TYPE_DRAGON_SOUL_INVENTORY);

///Add
#if defined(__BL_TRANSMUTATION__)
	PyModule_AddIntConstant(poModule, "SLOT_TYPE_CHANGE_LOOK",				ESlotType::SLOT_TYPE_CHANGE_LOOK);
	PyModule_AddIntConstant(poModule, "ITEM_SLOT_COUNT",					c_ItemSlot_Count);
	PyModule_AddIntConstant(poModule, "ITEM_SLOT_COUNT",					c_ItemSlot_Count);
	PyModule_AddIntConstant(poModule, "TRANSMUTATION_TYPE_MOUNT",			static_cast<BYTE>(ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_MOUNT));
	PyModule_AddIntConstant(poModule, "TRANSMUTATION_TYPE_ITEM",			static_cast<BYTE>(ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_ITEM));
#endif