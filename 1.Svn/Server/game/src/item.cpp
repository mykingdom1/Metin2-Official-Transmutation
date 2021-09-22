//Find
	m_dwMaskVnum(0), m_dwSIGVnum (0)

///Change
	m_dwMaskVnum(0), m_dwSIGVnum (0)
#if defined(__BL_TRANSMUTATION__)
	, m_dwTransmutationVnum(0)
#endif

//Find
	thecore_memcpy(pack.aAttr, GetAttributes(), sizeof(pack.aAttr));

///Add
#if defined(__BL_TRANSMUTATION__)
	pack.dwTransmutationVnum = GetTransmutationVnum();
#endif

//Find
		case ITEM_WEAPON:
			{
				...
			}
			break;
	
///Change
		case ITEM_WEAPON:
			{
				if (bAdd)
				{
#if defined(__BL_TRANSMUTATION__)
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
					{
						const WORD wVnum = static_cast<WORD>(GetVnum());
						const WORD wTransmutationVnum = static_cast<WORD>(GetTransmutationVnum());
						m_pOwner->SetPart(PART_WEAPON, wTransmutationVnum != 0 ? wTransmutationVnum : wVnum);
					}
#else
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, static_cast<WORD>(GetVnum()));
#endif
				}
				else
				{
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, m_pOwner->GetOriginalPart(PART_WEAPON));
				}
			}
			break;

//Find
		case ITEM_ARMOR:
			{
				...
			}
			break;

///Change
		case ITEM_ARMOR:
			{
				// ДЪЅєГх bodyё¦ АФ°нАЦґЩёй armorґВ №юґш АФґш »у°ь ѕшАМ єсБЦѕуїЎ їµЗвА» БЦёй ѕИ µК.
				if (0 != m_pOwner->GetWear(WEAR_COSTUME_BODY))
					break;

				if (GetSubType() == ARMOR_BODY || GetSubType() == ARMOR_HEAD || GetSubType() == ARMOR_FOOTS || GetSubType() == ARMOR_SHIELD)
				{
					if (bAdd)
					{
#if defined(__BL_TRANSMUTATION__)
						if (GetProto()->bSubType == ARMOR_BODY)
						{
							const WORD wVnum = static_cast<WORD>(GetVnum());
							const WORD wTransmutationVnum = static_cast<WORD>(GetTransmutationVnum());
							m_pOwner->SetPart(PART_MAIN, wTransmutationVnum != 0 ? wTransmutationVnum : wVnum);
						}
#else
						if (GetProto()->bSubType == ARMOR_BODY)
							m_pOwner->SetPart(PART_MAIN, static_cast<WORD>(GetVnum()));
#endif
					}
					else
					{
						if (GetProto()->bSubType == ARMOR_BODY)
							m_pOwner->SetPart(PART_MAIN, m_pOwner->GetOriginalPart(PART_MAIN));
					}
				}
			}
			break;

//Find
		case ITEM_COSTUME:
			{
				...
			}
			break;

///Change
		case ITEM_COSTUME:
			{
				DWORD toSetValue = this->GetVnum();
				EParts toSetPart = PART_MAX_NUM;

				// °©їК ДЪЅєГх
				if (GetSubType() == COSTUME_BODY)
				{
					toSetPart = PART_MAIN;

					if (false == bAdd)
					{
						// ДЪЅєГх °©їКА» №юѕъА» ¶§ їш·Ў °©їКА» АФ°н АЦѕъґЩёй ±Ч °©їКАё·О look јјЖГ, АФБц ѕКѕТґЩёй default look
						const CItem* pArmor = m_pOwner->GetWear(WEAR_BODY);
#if defined(__BL_TRANSMUTATION__)
						if (pArmor)
						{
							const DWORD dwVnum = GetVnum();
							const DWORD dwTransmutationVnum = GetTransmutationVnum();
							toSetValue = dwTransmutationVnum != 0 ? dwTransmutationVnum : dwVnum;
						}
						else
						{
							toSetValue = m_pOwner->GetOriginalPart(PART_MAIN);
						}
#else
						toSetValue = (NULL != pArmor) ? pArmor->GetVnum() : m_pOwner->GetOriginalPart(PART_MAIN);
#endif
					}
					
				}

				// Змѕо ДЪЅєГх
				else if (GetSubType() == COSTUME_HAIR)
				{
					toSetPart = PART_HAIR;

					// ДЪЅєГх ЗмѕоґВ shape°ЄА» item protoАЗ value3їЎ јјЖГЗПµµ·П ЗФ. ЖЇє°ЗС АМАЇґВ ѕш°н ±вБё °©їК(ARMOR_BODY)АЗ shape°ЄАМ ЗБ·ОЕдАЗ value3їЎ АЦѕој­ Змѕоµµ °°АМ value3Аё·О ЗФ.
					// [NOTE] °©їКАє ѕЖАМЕЫ vnumА» єёі»°н ЗмѕоґВ shape(value3)°ЄА» єёі»ґВ АМАЇґВ.. ±вБё ЅГЅєЕЫАМ ±Ч·ё°Ф µЗѕоАЦАЅ...
					toSetValue = (true == bAdd) ? this->GetValue(3) : 0;
				}

				if (PART_MAX_NUM != toSetPart)
				{
					m_pOwner->SetPart((BYTE)toSetPart, static_cast<WORD>(toSetValue));
					m_pOwner->UpdatePacket();
				}
			}
			break;

///Add to end
#if defined(__BL_TRANSMUTATION__)
void CItem::SetTransmutationVnum(DWORD blVnum)
{
	m_dwTransmutationVnum = blVnum;
	Save();
}

DWORD CItem::GetTransmutationVnum() const
{
	return m_dwTransmutationVnum;
}
#endif