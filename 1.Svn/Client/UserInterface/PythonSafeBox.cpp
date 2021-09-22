//Find
PyObject * safeboxGetMallSize(PyObject * poSelf, PyObject * poArgs)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
PyObject* safeboxGetItemChangeLookVnum(PyObject* poSelf, PyObject* poArgs)
{
	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iSlotIndex))
		return Py_BuildException();

	TItemData* pInstance;
	if (CPythonSafeBox::Instance().GetItemDataPtr(iSlotIndex, &pInstance))
		return Py_BuildValue("i", pInstance->dwTransmutationVnum);

	return Py_BuildValue("i", 0);
}

PyObject* safeboxGetMallItemChangeLookVnum(PyObject* poSelf, PyObject* poArgs)
{
	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iSlotIndex))
		return Py_BuildException();

	TItemData* pInstance;
	if (CPythonSafeBox::Instance().GetMallItemDataPtr(iSlotIndex, &pInstance))
		return Py_BuildValue("i", pInstance->dwTransmutationVnum);

	return Py_BuildValue("i", 0);
}
#endif

//Find
		{ "GetMallSize",				safeboxGetMallSize,						METH_VARARGS },

///Add
#if defined(__BL_TRANSMUTATION__)
		{ "GetItemChangeLookVnum",		safeboxGetItemChangeLookVnum,			METH_VARARGS },
		{ "GetMallItemChangeLookVnum",	safeboxGetMallItemChangeLookVnum,		METH_VARARGS },
#endif