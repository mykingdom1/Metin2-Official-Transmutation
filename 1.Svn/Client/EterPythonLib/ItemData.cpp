//Find
BYTE CItemData::GetSubType() const
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
DWORD CItemData::GetAntiFlags() const
{
	return m_ItemTable.dwAntiFlags;
}
#endif