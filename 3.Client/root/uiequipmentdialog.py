#Add
import app

#Find
	def SetEquipmentDialogItem(self, slotIndex, vnum, count):
		if count <= 1:
			count = 0
		self.slotWindow.SetItemSlot(slotIndex, vnum, count)

		emptySocketList = []
		emptyAttrList = []
		for i in xrange(player.METIN_SOCKET_MAX_NUM):
			emptySocketList.append(0)
		for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
			emptyAttrList.append((0, 0))
		self.itemDataDict[slotIndex] = (vnum, count, emptySocketList, emptyAttrList)

#Change
	if app.BL_TRANSMUTATION_SYSTEM:
		def SetEquipmentDialogItem(self, slotIndex, vnum, count, dwChangeLookVnum):
			if count <= 1:
				count = 0
			self.slotWindow.SetItemSlot(slotIndex, vnum, count)

			emptySocketList = []
			emptyAttrList = []
			for i in xrange(player.METIN_SOCKET_MAX_NUM):
				emptySocketList.append(0)
			for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
				emptyAttrList.append((0, 0))
			
			self.itemDataDict[slotIndex] = (vnum, count, emptySocketList, emptyAttrList, dwChangeLookVnum)
			
			if not dwChangeLookVnum == 0:
				self.slotWindow.SetSlotCoverImage(slotIndex,"icon/item/ingame_convert_Mark.tga")
			else:
				self.slotWindow.EnableSlotCoverImage(slotIndex,False)	
	else:
		def SetEquipmentDialogItem(self, slotIndex, vnum, count):
			if count <= 1:
				count = 0
			self.slotWindow.SetItemSlot(slotIndex, vnum, count)

			emptySocketList = []
			emptyAttrList = []
			for i in xrange(player.METIN_SOCKET_MAX_NUM):
				emptySocketList.append(0)
			for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
				emptyAttrList.append((0, 0))
			self.itemDataDict[slotIndex] = (vnum, count, emptySocketList, emptyAttrList)

#Find in def OverInItem(self, slotIndex):
		self.tooltipItem.AddItemData(itemVnum, metinSlot, attrSlot)

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.tooltipItem.AppendChangeLookInfoItemVnum(self.itemDataDict[slotIndex][4])