//Find
PyObject * shopGetItemPrice(PyObject * poSelf, PyObject * poArgs)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
PyObject* shopGetItemChangeLookVnum(PyObject* poSelf, PyObject* poArgs)
{
	int iIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex))
		return Py_BuildException();

	const TShopItemData* c_pItemData;
	if (CPythonShop::Instance().GetItemData(iIndex, &c_pItemData))
		return Py_BuildValue("i", c_pItemData->dwTransmutationVnum);

	return Py_BuildValue("i", 0);
}
#endif

//Find
		{ "GetItemPrice",				shopGetItemPrice,				METH_VARARGS },

///Add
#if defined(__BL_TRANSMUTATION__)
		{ "GetItemChangeLookVnum",		shopGetItemChangeLookVnum,		METH_VARARGS },
#endif