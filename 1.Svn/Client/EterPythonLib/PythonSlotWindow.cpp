//Find
	Slot.pFinishCoolTimeEffect = NULL;

///Add
#if defined(__BL_TRANSMUTATION__)
	Slot.pCoverImage = nullptr;
#endif

//Find
void CSlotWindow::SetSlotCoolTime(DWORD dwIndex, float fCoolTime, float fElapsedTime)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
void CSlotWindow::SetSlotCoverImage(const DWORD dwIndex, const char* FileName)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot))
		return;

	auto& CoverImage = pSlot->pCoverImage;
	if (CoverImage == nullptr)
		CoverImage = std::make_shared<CImageBox>(nullptr);

	CoverImage->LoadImage(FileName);
	CoverImage->Show();
}

void CSlotWindow::EnableSlotCoverImage(const DWORD dwIndex, const bool bEnable)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot))
		return;

	const auto& CoverImage = pSlot->pCoverImage;
	if (CoverImage == nullptr)
		return;
	
	if (bEnable)
		CoverImage->Show();
	else
		CoverImage->Hide();
}
#endif

//Find
	if (pSlot->pSignImage)
	{
 		pSlot->pSignImage->Hide();
	}

///Add
#if defined(__BL_TRANSMUTATION__)
	if (pSlot->pCoverImage)
	{
		pSlot->pCoverImage->Hide();
	}
#endif

//Find
		if (rSlot.pInstance)
		{
			rSlot.pInstance->SetPosition(m_rect.left + rSlot.ixPosition, m_rect.top + rSlot.iyPosition);
			rSlot.pInstance->Render();
		}

///Add
#if defined(__BL_TRANSMUTATION__)
		if (rSlot.pCoverImage)
		{
			rSlot.pCoverImage->SetPosition(m_rect.left + rSlot.ixPosition, m_rect.top + rSlot.iyPosition);
			rSlot.pCoverImage->Render();
		}
#endif