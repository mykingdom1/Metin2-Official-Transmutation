//Find
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
						|| ch->GetTransmutation()
#endif
					)

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
		|| ch->GetTransmutation()
#endif
	)

//Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	...
}

///Add
#if defined(__BL_TRANSMUTATION__)
#include "Transmutation.h"

void CInputMain::Transmutation(LPCHARACTER ch, const char* c_pData)
{
	auto p = reinterpret_cast<const TPacketCGTransmutation*>(c_pData);
	
	CTransmutation* CLook = ch->GetTransmutation();
	if (CLook == nullptr)
		return;

	switch (static_cast<ECG_TRANSMUTATION_SHEADER>(p->subheader))
	{
	case ECG_TRANSMUTATION_SHEADER::ITEM_CHECK_IN:
		CLook->ItemCheckIn(p->pos, p->slot_type);
		break;
	case ECG_TRANSMUTATION_SHEADER::ITEM_CHECK_OUT:
		CLook->ItemCheckOut(p->slot_type);
		break;
	case ECG_TRANSMUTATION_SHEADER::FREE_ITEM_CHECK_IN:
		CLook->FreeItemCheckIn(p->pos);
		break;
	case ECG_TRANSMUTATION_SHEADER::FREE_ITEM_CHECK_OUT:
		CLook->FreeItemCheckOut();
		break;
	case ECG_TRANSMUTATION_SHEADER::ACCEPT:
		CLook->Accept();
		break;
	case ECG_TRANSMUTATION_SHEADER::CANCEL:
		ch->SetTransmutation(nullptr);
		break;
	default:
		sys_err("Unknown Subheader ch:%s, %d", ch->GetName(), p->subheader);
		return;
	}
}
#endif

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_TRANSMUTATION__)
		|| ch->GetTransmutation()
#endif
	)

//Find
		case HEADER_CG_MALL_CHECKOUT:
			SafeboxCheckout(ch, c_pData, true);
			break;

///Add
#if defined(__BL_TRANSMUTATION__)
		case HEADER_CG_TRANSMUTATION:
			Transmutation(ch, c_pData);
			break;
#endif