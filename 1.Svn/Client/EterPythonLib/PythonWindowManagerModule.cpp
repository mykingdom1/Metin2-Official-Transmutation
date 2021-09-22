//Find
PyObject * wndMgrRefreshSlot(PyObject * poSelf, PyObject * poArgs)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
PyObject* wndMgrSetSlotCoverImage(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	char* szFileName;
	if (!PyTuple_GetString(poArgs, 2, &szFileName))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->SetSlotCoverImage(dwSlotIndex, szFileName);

	return Py_BuildNone();
}

PyObject* wndMgrEnableSlotCoverImage(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	bool bOnOff;
	if (!PyTuple_GetBoolean(poArgs, 2, &bOnOff))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->EnableSlotCoverImage(dwSlotIndex, bOnOff);

	return Py_BuildNone();
}

PyObject* wndMgrActivateNewSlotEffect(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->ActivateNewSlotEffect(dwSlotIndex);
	return Py_BuildNone();
}

PyObject* wndMgrDeactivateNewSlotEffect(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->DeactivateNewSlotEffect(dwSlotIndex);
	return Py_BuildNone();
}

PyObject* wndMgrSetNewSlotDiffuseColor(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	DWORD dwSlotIndex;
	if (!PyTuple_GetUnsignedLong(poArgs, 1, &dwSlotIndex))
		return Py_BuildException();

	BYTE blType;
	if (!PyTuple_GetByte(poArgs, 2, &blType))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->SetNewSlotDiffuseColor(dwSlotIndex, blType);

	return Py_BuildNone();
}
#endif

//Find
		{ "RefreshSlot",				wndMgrRefreshSlot,					METH_VARARGS },

///Add
#if defined(__BL_TRANSMUTATION__)
		{ "SetSlotCoverImage",			wndMgrSetSlotCoverImage,			METH_VARARGS },
		{ "EnableSlotCoverImage",		wndMgrEnableSlotCoverImage,			METH_VARARGS },
		{ "ActivateNewSlotEffect",		wndMgrActivateNewSlotEffect,		METH_VARARGS },
		{ "DeactivateNewSlotEffect",	wndMgrDeactivateNewSlotEffect,		METH_VARARGS },
		{ "SetNewSlotDiffuseColor",		wndMgrSetNewSlotDiffuseColor,		METH_VARARGS },
#endif

//Find
	PyModule_AddIntConstant(poModule, "RENDERING_MODE_MODULATE",		CGraphicExpandedImageInstance::RENDERING_MODE_MODULATE);

///Add
#if defined(__BL_TRANSMUTATION__)
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_ORANGE", UI::ESlotColor::COLOR_TYPE_ORANGE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_WHITE", UI::ESlotColor::COLOR_TYPE_WHITE);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_RED", UI::ESlotColor::COLOR_TYPE_RED);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_GREEN", UI::ESlotColor::COLOR_TYPE_GREEN);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_YELLOW", UI::ESlotColor::COLOR_TYPE_YELLOW);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_SKY", UI::ESlotColor::COLOR_TYPE_SKY);
	PyModule_AddIntConstant(poModule, "COLOR_TYPE_PINK", UI::ESlotColor::COLOR_TYPE_PINK);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_ACCE", UI::ESlotHilight::HILIGHTSLOT_ACCE);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_CHANGE_LOOK", UI::ESlotHilight::HILIGHTSLOT_CHANGE_LOOK);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_AURA", UI::ESlotHilight::HILIGHTSLOT_AURA);
	PyModule_AddIntConstant(poModule, "HILIGHTSLOT_CUBE", UI::ESlotHilight::HILIGHTSLOT_CUBE);
#endif