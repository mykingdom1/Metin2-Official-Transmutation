//Find
	void CAniImageBox::ResetFrame()
	{
		...
	}

///Add
#if defined(__BL_TRANSMUTATION__)
	const std::vector<CGraphicExpandedImageInstance*>& CAniImageBox::GetImageVector() const
	{
		return m_ImageVector;
	}
#endif