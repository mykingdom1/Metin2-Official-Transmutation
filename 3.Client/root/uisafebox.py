#Find in def RefreshSafebox(self):
			setItemID(i, getItemID(slotIndex), itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				changelookitemvnum = safebox.GetItemChangeLookVnum(slotIndex)
				if not changelookitemvnum == 0:
					self.wndItem.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.wndItem.EnableSlotCoverImage(i,False)

#Find in def RefreshMall(self):
			setItemID(i, itemID, itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				changelookitemvnum = safebox.GetMallItemChangeLookVnum(i)
				if not changelookitemvnum == 0:
					self.wndItem.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.wndItem.EnableSlotCoverImage(i,False)