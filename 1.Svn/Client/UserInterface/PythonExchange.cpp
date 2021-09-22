//Find
void CPythonExchange::SetItemAttributeToSelf(int pos, int iattrpos, BYTE byType, short sValue)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
void CPythonExchange::SetItemChangeLookVnumToSelf(const int pos, const DWORD blVnum)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return;

	m_self.dwTransmutationVnum[pos] = blVnum;
}

void CPythonExchange::SetItemChangeLookVnumToTarget(const int pos, const DWORD blVnum)
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return;

	m_victim.dwTransmutationVnum[pos] = blVnum;
}

DWORD CPythonExchange::GetItemChangeLookVnumToSelf(const BYTE pos) const
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return 0;

	return m_self.dwTransmutationVnum[pos];
}

DWORD CPythonExchange::GetItemChangeLookVnumToTarget(const BYTE pos) const
{
	if (pos >= EXCHANGE_ITEM_MAX_NUM)
		return 0;

	return m_victim.dwTransmutationVnum[pos];
}
#endif