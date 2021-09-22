//Find
PyObject* itemLoadItemTable(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__) || defined(__BL_TRANSMUTATION__)
PyObject* itemGetItemNameByVnum(PyObject* poSelf, PyObject* poArgs)
{
	DWORD dwVirtualNumber;
	if (!PyTuple_GetUnsignedLong(poArgs, 0, &dwVirtualNumber))
		return Py_BadArgument();
	
	CItemData* pItemData;
	if (!CItemManager::Instance().GetItemDataPointer(dwVirtualNumber, &pItemData))
		return Py_BuildException();

	return Py_BuildValue("s", pItemData->GetName());
}
#endif

#if defined(__BL_TRANSMUTATION__)
PyObject* itemIsPossibleChangeLookLeft(PyObject* poSelf, PyObject* poArgs)
{
	int iItemVID;
	if (!PyTuple_GetInteger(poArgs, 0, &iItemVID))
		return Py_BadArgument();

	CItemManager::Instance().SelectItemData(iItemVID);
	CItemData* pItemData = CItemManager::Instance().GetSelectedItemDataPointer();
	if (!pItemData)
		return Py_BuildException("Can't find select item data");

	return Py_BuildValue("b", CPythonItem::Instance().CanAddChangeLookItem(pItemData, nullptr));
}

PyObject* itemIsPossibleChangeLookRight(PyObject* poSelf, PyObject* poArgs)
{
	int iItemVID;
	if (!PyTuple_GetInteger(poArgs, 0, &iItemVID))
		return Py_BadArgument();

	int iOtherItemVID;
	if (!PyTuple_GetInteger(poArgs, 1, &iOtherItemVID))
		return Py_BadArgument();

	CItemManager::Instance().SelectItemData(iItemVID);
	CItemData* pItemData = CItemManager::Instance().GetSelectedItemDataPointer();
	
	CItemManager::Instance().SelectItemData(iOtherItemVID);
	CItemData* pOtherItemData = CItemManager::Instance().GetSelectedItemDataPointer();

	return Py_BuildValue("b", CPythonItem::Instance().CanAddChangeLookItem(pItemData, pOtherItemData));
}

PyObject* itemIsChangeLookFreePassYangItem(PyObject* poSelf, PyObject* poArgs)
{
	DWORD dwVirtualNumber;
	if (!PyTuple_GetUnsignedLong(poArgs, 0, &dwVirtualNumber))
		return Py_BadArgument();

	return Py_BuildValue("b", CPythonItem::Instance().CanAddChangeLookFreeItem(dwVirtualNumber));
}

PyObject* itemIsChangeLookClearScroll(PyObject* poSelf, PyObject* poArgs)
{
	int iItemVID;
	if (!PyTuple_GetInteger(poArgs, 0, &iItemVID))
		return Py_BadArgument();

	CItemManager::Instance().SelectItemData(iItemVID);
	CItemData* pItemData = CItemManager::Instance().GetSelectedItemDataPointer();
	if (!pItemData)
		return Py_BuildException("Can't find select item data");

	return Py_BuildValue("b", CPythonItem::Instance().IsChangeLookClearScrollItem(pItemData->GetIndex()));
}
#endif

//Find
		{ "LoadItemTable",					itemLoadItemTable,						METH_VARARGS },

///Add
#if defined(__BL_MOVE_COSTUME_ATTR__) || defined(__BL_TRANSMUTATION__)
		{ "GetItemNameByVnum",				itemGetItemNameByVnum,					METH_VARARGS },
#endif

#if defined(__BL_TRANSMUTATION__)
		{ "IsPossibleChangeLookLeft",		itemIsPossibleChangeLookLeft,			METH_VARARGS },
		{ "IsPossibleChangeLookRight",		itemIsPossibleChangeLookRight,			METH_VARARGS },
		{ "IsChangeLookFreePassYangItem",	itemIsChangeLookFreePassYangItem,		METH_VARARGS },
		{ "IsChangeLookClearScroll",		itemIsChangeLookClearScroll,			METH_VARARGS },
#endif