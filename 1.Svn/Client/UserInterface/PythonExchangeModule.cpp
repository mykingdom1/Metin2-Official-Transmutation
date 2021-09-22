///Add
#if defined(__BL_TRANSMUTATION__)
PyObject* exchangeGetChangeLookVnumFromSelf(PyObject* poSelf, PyObject* poArgs)
{
	int pos;
	if (!PyTuple_GetInteger(poArgs, 0, &pos))
		return Py_BuildException();

	const DWORD dwTransmutationVnum = CPythonExchange::Instance().GetItemChangeLookVnumToSelf(pos);
	return Py_BuildValue("i", dwTransmutationVnum);
}

PyObject* exchangeGetChangeLookVnumFromTarget(PyObject* poSelf, PyObject* poArgs)
{
	int pos;
	if (!PyTuple_GetInteger(poArgs, 0, &pos))
		return Py_BuildException();

	const DWORD dwTransmutationVnum = CPythonExchange::Instance().GetItemChangeLookVnumToTarget(pos);
	return Py_BuildValue("i", dwTransmutationVnum);
}
#endif

//Find
		{"GetElkFromTarget",			exchangeGetElkFromTarget,			METH_VARARGS},

///Add
#if defined(__BL_TRANSMUTATION__)
		{"GetChangeLookVnumFromSelf",	exchangeGetChangeLookVnumFromSelf,	METH_VARARGS},
		{"GetChangeLookVnumFromTarget",	exchangeGetChangeLookVnumFromTarget,	METH_VARARGS},
#endif