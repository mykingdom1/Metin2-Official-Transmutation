//Find
CPythonItem::~CPythonItem()
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
#include "PythonPlayer.h"

static bool _CanAddTransmutationItem(const CItemData* item)
{
	const bool bType = CPythonPlayer::Instance().GetChangeLookWindowType();
	const BYTE bItemType = item->GetType();
	const BYTE bItemSubType = item->GetSubType();

	switch (static_cast<ETRANSMUTATIONTYPE>(bType))
	{
	case ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_MOUNT:
		/// Edit here for your mount system
		break;
	case ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_ITEM:
		if (bItemType == CItemData::EItemType::ITEM_TYPE_WEAPON && bItemSubType != CItemData::EWeaponSubTypes::WEAPON_ARROW)
			return true;

		if (bItemType == CItemData::EItemType::ITEM_TYPE_ARMOR && bItemSubType == CItemData::EArmorSubTypes::ARMOR_BODY)
			return true;

		if (bItemType == CItemData::EItemType::ITEM_TYPE_COSTUME && bItemSubType == CItemData::ECostumeSubTypes::COSTUME_BODY)
			return true;
		break;
	}

	return false;
}

static bool _CheckOtherTransmutationItem(const CItemData* item, const CItemData* other_item)
{	
	if (item == other_item)
		return false;
	
	if (other_item->GetIndex() == item->GetIndex())
		return false;
	
	if (other_item->GetType() != item->GetType())
		return false;

	if (other_item->GetSubType() != item->GetSubType())
		return false;

	if (other_item->GetAntiFlags() != item->GetAntiFlags())
		return false;

	return true;
}

bool CPythonItem::CanAddChangeLookItem(const CItemData* item, const CItemData* other_item) const
{
	if (item == nullptr)
		return false;

	if (other_item)
		if (_CheckOtherTransmutationItem(item, other_item) == false)
			return false;
	else if (_CanAddTransmutationItem(item) == false)
		return false;

	return true;
}

bool CPythonItem::CanAddChangeLookFreeItem(const DWORD dwVnum) const
{
	return dwVnum == static_cast<DWORD>(ETRANSMUTATIONSETTINGS::TRANSMUTATION_TICKET_1)
		|| dwVnum == static_cast<DWORD>(ETRANSMUTATIONSETTINGS::TRANSMUTATION_TICKET_2);
}

bool CPythonItem::IsChangeLookClearScrollItem(const DWORD dwVnum) const
{
	return dwVnum == static_cast<DWORD>(ETRANSMUTATIONSETTINGS::TRANSMUTATION_CLEAR_SCROLL);
}
#endif