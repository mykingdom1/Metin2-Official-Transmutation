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
#if defined(ENABLE_MOUNT_COSTUME_SYSTEM)
		if (item->IsCostumeMount())
			return true;
#endif
		break;

	case ETRANSMUTATIONTYPE::TRANSMUTATION_TYPE_ITEM:
		if (item->IsMainWeapon()
#if defined(ENABLE_WEAPON_COSTUME_SYSTEM)
			|| item->IsCostumeWeapon()
#endif
			) return true;

		if (item->IsArmorBody()
#if defined(ENABLE_COSTUME_SYSTEM)
			|| item->IsCostumeBody()
#endif
			) return true;

#if defined(ENABLE_COSTUME_SYSTEM)
		if (item->IsCostumeBody())
			return true;
#endif

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

#if defined(ENABLE_COSTUME_SYSTEM)
	if (other_item->GetType() != item->GetType())
	{
		bool bCanPass = false;
		if ((other_item->IsCostumeBody() && item->IsArmorBody()) ||
			(other_item->IsArmorBody() && item->IsCostumeBody()))

			bCanPass = true;

		if ((other_item->IsCostumeWeapon() && item->IsMainWeapon() && other_item->GetValue(3) == item->GetSubType()) ||
			(other_item->IsMainWeapon() && item->IsCostumeWeapon() && other_item->GetSubType() == item->GetValue(3)))
			bCanPass = true;

		return bCanPass;
	}
	else
#endif
	{
		if (other_item->GetType() != item->GetType())
			return false;

		if (other_item->GetSubType() != item->GetSubType())
			return false;

		if (item->IsArmor() || item->IsMainWeapon())
			if (other_item->GetAntiFlags() != item->GetAntiFlags())
				return false;

#if defined(ENABLE_COSTUME_SYSTEM)
		if (other_item->IsCostumeBody() == item->IsCostumeBody())
		{
			if ((other_item->IsAntiFlag(CItemData::ITEM_ANTIFLAG_FEMALE) && item->IsAntiFlag(CItemData::ITEM_ANTIFLAG_MALE)) ||
				(other_item->IsAntiFlag(CItemData::ITEM_ANTIFLAG_MALE) && item->IsAntiFlag(CItemData::ITEM_ANTIFLAG_FEMALE)))
				return false;
		}
#endif

#if defined(ENABLE_WEAPON_COSTUME_SYSTEM)
		if (item->IsCostumeWeapon())
			if ((item->GetValue(3) != other_item->GetValue(3)))
				return false;
#endif
	}

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