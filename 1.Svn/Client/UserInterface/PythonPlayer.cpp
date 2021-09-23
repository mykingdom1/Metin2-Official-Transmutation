//Find
	m_dwPlayTime = 0;
	
///Add
#if defined(__BL_TRANSMUTATION__)
	ClearChangeLook();
	bIsChangeLookWindowOpen = false;
	bChangeLookWindowType = static_cast<decltype(bChangeLookWindowType)>(ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_ITEM);
#endif

//Find
CPythonPlayer::~CPythonPlayer(void)
{
}

///Add
#if defined(__BL_TRANSMUTATION__)
#include "../EterPythonLib/PythonSlotWindow.h"

void CPythonPlayer::SetItemTransmutationVnum(TItemPos& Cell, const DWORD blVnum)
{
	if (!Cell.IsValidCell())
		return;

	const TItemData* item = GetItemData(Cell);
	if (item == nullptr)
		return;

	const_cast<TItemData*>(item)->dwTransmutationVnum = blVnum;
	PyCallClassMemberFunc(m_ppyGameWindow, "RefreshInventory", Py_BuildValue("()"));
}

DWORD CPythonPlayer::GetItemChangeLookVnum(TItemPos& Cell) const
{
	if (!Cell.IsValidCell())
		return 0;

	const TItemData* pItem = GetItemData(Cell);
	return pItem ? pItem->dwTransmutationVnum : 0;
}

void CPythonPlayer::ClearChangeLook(const bool bClearEffect)
{
	for (BYTE i = 0; i < static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX); i++)
		DelChangeLookItemData(i, bClearEffect);

	DelChangeLookFreeItemData(bClearEffect);
}

void CPythonPlayer::SetChangeLookWindowOpen(const bool blOpen)
{
	bIsChangeLookWindowOpen = blOpen;
	CPythonPlayer::Instance().ClearChangeLook(true);
}

bool CPythonPlayer::GetChangeLookWindowOpen() const
{
	return bIsChangeLookWindowOpen;
}

void CPythonPlayer::SetChangeLookWindowType(const bool blType)
{
	bChangeLookWindowType = blType;
}

bool CPythonPlayer::GetChangeLookWindowType() const
{
	return bChangeLookWindowType;
}

void CPythonPlayer::SetChangeLookItemData(TPacketGCTransmutationItemSet& data)
{
	if (data.bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return;

	m_ChangeLookSlot[data.bSlotType] = data;
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	PyCallClassMemberFunc(m_ppyGameWindow, "ActivateSlot", Py_BuildValue("(ii)", data.wCell, UI::ESlotHilight::HILIGHTSLOT_CHANGE_LOOK));
#endif
}

TPacketGCTransmutationItemSet* CPythonPlayer::GetChangeLookItemData(const BYTE bSlotType)
{
	if (bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return nullptr;

	return &m_ChangeLookSlot[bSlotType];
}

void CPythonPlayer::DelChangeLookItemData(const BYTE bSlotType, const bool bClearEffect)
{
	if (bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return;

	TPacketGCTransmutationItemSet& rInstance = m_ChangeLookSlot[bSlotType];

#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	if (bClearEffect && rInstance.wCell < c_Inventory_Count)
		PyCallClassMemberFunc(m_ppyGameWindow, "DeactivateSlot", Py_BuildValue("(ii)", rInstance.wCell, UI::ESlotHilight::HILIGHTSLOT_CHANGE_LOOK));
#endif

	ZeroMemory(&rInstance, sizeof(rInstance));
	rInstance.wCell = c_Inventory_Count;
}

void CPythonPlayer::SetChangeLookFreeItemData(TPacketGCTransmutationItemSet& data)
{
	m_ChangeLookFreeYangItemSlot = data;
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	PyCallClassMemberFunc(m_ppyGameWindow, "ActivateSlot", Py_BuildValue("(ii)", data.wCell, UI::ESlotHilight::HILIGHTSLOT_CHANGE_LOOK));
#endif
}

TPacketGCTransmutationItemSet* CPythonPlayer::GetChangeLookFreeItemData()
{
	return &m_ChangeLookFreeYangItemSlot;
}

void CPythonPlayer::DelChangeLookFreeItemData(const bool bClearEffect)
{
#if defined(__BL_ENABLE_PICKUP_ITEM_EFFECT__)
	if (bClearEffect && m_ChangeLookFreeYangItemSlot.wCell < c_Inventory_Count)
		PyCallClassMemberFunc(m_ppyGameWindow, "DeactivateSlot", Py_BuildValue("(ii)", m_ChangeLookFreeYangItemSlot.wCell, UI::ESlotHilight::HILIGHTSLOT_CHANGE_LOOK));
#endif

	ZeroMemory(&m_ChangeLookFreeYangItemSlot, sizeof(m_ChangeLookFreeYangItemSlot));
	m_ChangeLookFreeYangItemSlot.wCell = c_Inventory_Count;
}
#endif