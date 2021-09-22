#Find in def Refresh(self):
			setItemID(i, getItemID(idx), itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				changelookvnum = shop.GetItemChangeLookVnum(idx)
				if not changelookvnum == 0:
					self.itemSlotWindow.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.itemSlotWindow.EnableSlotCoverImage(i,False)