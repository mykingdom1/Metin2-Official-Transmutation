//Find
	Slot.pFinishCoolTimeEffect = NULL;

///Add
#if defined(__BL_TRANSMUTATION__)
	Slot.pCoverImage = nullptr;
	Slot.pNewSlotEffect.fill(nullptr);
#endif

//Find
void CSlotWindow::SetSlotCoolTime(DWORD dwIndex, float fCoolTime, float fElapsedTime)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
D3DXCOLOR CSlotWindow::GetSlotColor(const BYTE blType) const
{
	switch (blType)
	{
	case ESlotColor::COLOR_TYPE_ORANGE:
		return D3DXCOLOR(0xFFA500);
	case ESlotColor::COLOR_TYPE_WHITE:
		return D3DXCOLOR(0xFFFFFF);
	case ESlotColor::COLOR_TYPE_RED:
		return D3DXCOLOR(0xFF0000);
	case ESlotColor::COLOR_TYPE_GREEN:
		return D3DXCOLOR(0x008000);
	case ESlotColor::COLOR_TYPE_YELLOW:
		return D3DXCOLOR(0xFFFF00);
	case ESlotColor::COLOR_TYPE_SKY:
		return D3DXCOLOR(0x87CEFA);
	case ESlotColor::COLOR_TYPE_PINK:
		return D3DXCOLOR(0xFFC0CB);
	}

	return D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

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

void CSlotWindow::ActivateNewSlotEffect(const DWORD dwSlotIndex)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwSlotIndex, &pSlot))
		return;

	for (size_t i = 0; i < pSlot->pNewSlotEffect.size(); i++)
	{
		auto& NewSlotEffect = pSlot->pNewSlotEffect.at(i);
		if (NewSlotEffect == nullptr)
		{
			char buf[128];
			NewSlotEffect = std::make_shared< CAniImageBox >(nullptr);

			for (BYTE j = 0; j < 13; j++)
			{
				if (i == 0)
					snprintf(buf, sizeof(buf), "d:/ymir work/ui/public/slotactiveeffect/%02d.sub", j);
				else
					snprintf(buf, sizeof(buf), "d:/ymir work/ui/public/slotactiveeffect/slot%d/%02d.sub", (i + 1), j);

				NewSlotEffect->AppendImage(buf);
				NewSlotEffect->SetRenderingMode(CGraphicExpandedImageInstance::RENDERING_MODE_SCREEN);
			}
		}
		
		if (i == (pSlot->byyPlacedItemSize - 1))
			NewSlotEffect->Show();
		else
			NewSlotEffect->Hide();
	}
}

void CSlotWindow::DeactivateNewSlotEffect(const DWORD dwSlotIndex)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwSlotIndex, &pSlot))
		return;

	for (const auto& NewSlotEffect : pSlot->pNewSlotEffect)
		if (NewSlotEffect)
			NewSlotEffect->Hide();
}

void CSlotWindow::SetNewSlotDiffuseColor(const DWORD dwIndex, const BYTE blType)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot))
		return;

	for (auto& NewSlotEffect : pSlot->pNewSlotEffect)
	{
		if (NewSlotEffect == nullptr)
			continue;

		const auto& vecImage = NewSlotEffect->GetImageVector();
		if (vecImage.empty())
			continue;

		for (CGraphicExpandedImageInstance* SlotImage : vecImage)
		{
			if (SlotImage == nullptr || SlotImage->IsEmpty())
				continue;

			const D3DXCOLOR color{ GetSlotColor(blType) };
			SlotImage->SetDiffuseColor(color.r, color.g, color.b, color.a);
		}
	}
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
	for (auto& NewSlotEffect : pSlot->pNewSlotEffect)
	{
		if (NewSlotEffect)
			NewSlotEffect->Hide();
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
	
		for (const auto& NewSlotEffect : rSlot.pNewSlotEffect)
		{
			if (NewSlotEffect == nullptr || NewSlotEffect->IsShow() == false)
				continue;

			NewSlotEffect->SetPosition(m_rect.left + rSlot.ixPosition, m_rect.top + rSlot.iyPosition);
			NewSlotEffect->Update();
			NewSlotEffect->Render();
		}
#endif