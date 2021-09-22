#Find in def SelectOwnerEmptySlot(self, SlotIndex):
		if False == mouseModule.mouseController.isAttached():
			return

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			if player.GetChangeLookWindowOpen() == 1:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.CHANGE_LOOK_OPEN_OTHER_WINDOW)
				return

#Find in def RefreshOwnerSlot(self):
			self.OwnerSlot.SetItemSlot(i, itemIndex, itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				changelookvnum = exchange.GetChangeLookVnumFromSelf(i)
				if not changelookvnum == 0:
					self.OwnerSlot.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.OwnerSlot.EnableSlotCoverImage(i,False)

#Find in def RefreshTargetSlot(self):
			self.TargetSlot.SetItemSlot(i, itemIndex, itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				changelookvnum = exchange.GetChangeLookVnumFromTarget(i)
				if not changelookvnum == 0:
					self.TargetSlot.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.TargetSlot.EnableSlotCoverImage(i,False)