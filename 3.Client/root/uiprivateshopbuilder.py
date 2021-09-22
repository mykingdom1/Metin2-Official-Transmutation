#Find in def Refresh(self):
			setitemVNum(i, getitemVNum(*pos), itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				inventyp, pos = self.itemStock[i]
				if not player.GetChangeLookVnum(inventyp, pos) == 0:
					self.itemSlot.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.itemSlot.EnableSlotCoverImage(i,False)