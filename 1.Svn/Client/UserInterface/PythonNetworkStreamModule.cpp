//Find
PyObject* netRegisterErrorLog(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
PyObject* netSendChangeLookCheckIn(PyObject* poSelf, PyObject* poArgs)
{
	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
		return Py_BuildException();

	BYTE bChangeLookSlotType;
	if (!PyTuple_GetByte(poArgs, 2, &bChangeLookSlotType))
		return Py_BuildException();

	if (bChangeLookSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendChangeLookCheckInPacket(Cell, bChangeLookSlotType);

	return Py_BuildNone();
}

PyObject* netSendChangeLookCheckOut(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bChangeLookSlotType;
	if (!PyTuple_GetByte(poArgs, 0, &bChangeLookSlotType))
		return Py_BuildException();
	
	CPythonNetworkStream::Instance().SendChangeLookCheckOutPacket(bChangeLookSlotType);
	
	return Py_BuildNone();
}

PyObject* netSendChangeLookCheckInFreeYangItem(PyObject* poSelf, PyObject* poArgs)
{
	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendChangeLookCheckInFreeYangItemPacket(Cell);

	return Py_BuildNone();
}

PyObject* netSendChangeLookCheckOutFreeYangItem(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendChangeLookCheckOutFreeYangItemPacket();
	
	return Py_BuildNone();
}

PyObject* netSendChangeLookAccept(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendChangeLookAcceptPacket();
	
	return Py_BuildNone();
}

PyObject* netSendChangeLookCancel(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendChangeLookCancelPacket();
	
	return Py_BuildNone();
}
#endif

//Find
		{ "RegisterErrorLog",						netRegisterErrorLog,						METH_VARARGS },

///Add
#if defined(__BL_TRANSMUTATION__)
		{ "SendChangeLookCheckIn",					netSendChangeLookCheckIn,					METH_VARARGS },
		{ "SendChangeLookCheckOut",					netSendChangeLookCheckOut,					METH_VARARGS },
		{ "SendChangeLookCheckInFreeYangItem",		netSendChangeLookCheckInFreeYangItem,		METH_VARARGS },
		{ "SendChangeLookCheckOutFreeYangItem",		netSendChangeLookCheckOutFreeYangItem,		METH_VARARGS },
		{ "SendChangeLookCheckOut",					netSendChangeLookCheckOut,					METH_VARARGS },
		{ "SendChangeLookAccept",					netSendChangeLookAccept,					METH_VARARGS },
		{ "SendChangeLookCanCle",					netSendChangeLookCancel,					METH_VARARGS },
#endif