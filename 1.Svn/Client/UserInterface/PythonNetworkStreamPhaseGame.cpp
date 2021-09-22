//Find
			case HEADER_GC_MOTION:
				ret = RecvMotionPacket();
				break;

///Add
#if defined(__BL_TRANSMUTATION__)
			case HEADER_GC_CHANGE_LOOK_SET:
				ret = RecvChangeLookItemSetPacket();
				break;

			case HEADER_GC_CHANGE_LOOK_DEL:
				ret = RecvChangeLookItemDelPacket();
				break;

			case HEADER_GC_CHANGE_LOOK_FREE_SET:
				ret = RecvChangeLookFreeItemSetPacket();
				break;

			case HEADER_GC_CHANGE_LOOK_FREE_DEL:
				ret = RecvChangeLookFreeItemDelPacket();
				break;
#endif

//Find
				for (int j = 0; j < ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++j)
					CPythonExchange::Instance().SetItemAttributeToSelf(iSlotIndex, j, exchange_packet.aAttr[j].bType, exchange_packet.aAttr[j].sValue);

///Add
#if defined(__BL_TRANSMUTATION__)
				CPythonExchange::Instance().SetItemChangeLookVnumToSelf(iSlotIndex, exchange_packet.dwTransmutationVnum);
#endif

//Find
				for (int j = 0; j < ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++j)
					CPythonExchange::Instance().SetItemAttributeToTarget(iSlotIndex, j, exchange_packet.aAttr[j].bType, exchange_packet.aAttr[j].sValue);
	
///Add
#if defined(__BL_TRANSMUTATION__)
				CPythonExchange::Instance().SetItemChangeLookVnumToTarget(iSlotIndex, exchange_packet.dwTransmutationVnum);
#endif

//Find
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "SetEquipmentDialogItem", Py_BuildValue("(iiii)", kViewEquipPacket.dwVID, i, rItemSet.vnum, rItemSet.count));

///Change
#if defined(__BL_TRANSMUTATION__)
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "SetEquipmentDialogItem", Py_BuildValue("(iiiii)", kViewEquipPacket.dwVID, i, rItemSet.vnum, rItemSet.count, rItemSet.dwTransmutationVnum));
#else
		PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "SetEquipmentDialogItem", Py_BuildValue("(iiii)", kViewEquipPacket.dwVID, i, rItemSet.vnum, rItemSet.count));
#endif

///Add to end
#if defined(__BL_TRANSMUTATION__)
#define TransmutationPacket(x) TPacketCGTransmutation p(static_cast<std::underlying_type_t<ECG_TRANSMUTATION_SHEADER>>(ECG_TRANSMUTATION_SHEADER::x))

bool CPythonNetworkStream::SendChangeLookCheckInPacket(const TItemPos& pos, const BYTE bSlotType)
{
	TransmutationPacket(ITEM_CHECK_IN);
	p.slot_type = bSlotType;
	p.pos = pos;

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendChangeLookCheckInPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendChangeLookCheckOutPacket(const BYTE bSlotType)
{
	TransmutationPacket(ITEM_CHECK_OUT);
	p.slot_type = bSlotType;

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendChangeLookCheckOutPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendChangeLookCheckInFreeYangItemPacket(const TItemPos& pos)
{
	TransmutationPacket(FREE_ITEM_CHECK_IN);
	p.pos = pos;

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendChangeLookCheckInFreeYangItemPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendChangeLookCheckOutFreeYangItemPacket()
{
	TransmutationPacket(FREE_ITEM_CHECK_OUT);

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendChangeLookCheckOutFreeYangItemPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendChangeLookAcceptPacket()
{
	TransmutationPacket(ACCEPT);

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendChangeLookAcceptPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::SendChangeLookCancelPacket()
{
	TransmutationPacket(CANCEL);

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendChangeLookCancelPacket Error\n");
		return false;
	}

	return SendSequence();
}

bool CPythonNetworkStream::RecvChangeLookItemSetPacket()
{
	TPacketGCTransmutationItemSet kItemSet;
	if (!Recv(sizeof(kItemSet), &kItemSet))
		return false;

	if (kItemSet.bSlotType >= static_cast<BYTE>(ETRANSMUTATIONSLOTTYPE::TRANSMUTATION_SLOT_MAX))
		return true;

	CPythonPlayer::Instance().SetChangeLookItemData(kItemSet);

	__RefreshInventoryWindow();

	return true;
}

bool CPythonNetworkStream::RecvChangeLookItemDelPacket()
{
	TPacketGCTransmutationDel kItemDel;
	if (!Recv(sizeof(kItemDel), &kItemDel))
		return false;

	CPythonPlayer::Instance().DelChangeLookItemData(kItemDel.bSlotType, true);

	__RefreshInventoryWindow();
	Tracef(" >> CPythonNetworkStream::RecvChangeLookItemDelPacket\n");

	return true;
}

bool CPythonNetworkStream::RecvChangeLookFreeItemSetPacket()
{
	TPacketGCTransmutationItemSet kItemSet;
	if (!Recv(sizeof(kItemSet), &kItemSet))
		return false;

	CPythonPlayer::Instance().SetChangeLookFreeItemData(kItemSet);

	__RefreshInventoryWindow();

	return true;
}

bool CPythonNetworkStream::RecvChangeLookFreeItemDelPacket()
{
	TPacketGCTransmutationDel kItemDel;
	if (!Recv(sizeof(kItemDel), &kItemDel))
		return false;

	CPythonPlayer::Instance().DelChangeLookFreeItemData(true);

	__RefreshInventoryWindow();
	Tracef(" >> CPythonNetworkStream::RecvChangeLookFreeItemDelPacket\n");

	return true;
}
#endif
