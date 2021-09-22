#Find
	NEED_SKILL_POINT_COLOR = 0xff9A9CDB

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		CHANGELOOK_TITLE_COLOR = 0xff8BBDFF
		CHANGELOOK_ITEMNAME_COLOR = 0xffBCE55C

#Find in def SetInventoryItem(self, slotIndex, window_type = player.INVENTORY):
		self.AddItemData(itemVnum, metinSlot, attrSlot)

#Change
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AddItemData(itemVnum, metinSlot, attrSlot, 0, 0, window_type, slotIndex)
		else:
			self.AddItemData(itemVnum, metinSlot, attrSlot)

#Find in def SetShopItem(self, slotIndex):
		self.AddItemData(itemVnum, metinSlot, attrSlot)

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AppendChangeLookInfoShopWIndow(slotIndex)

#Find in def SetExchangeOwnerItem(self, slotIndex):
		self.AddItemData(itemVnum, metinSlot, attrSlot)

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AppendChangeLookInfoExchangeWIndow(0,slotIndex)

#Find in def SetExchangeTargetItem(self, slotIndex):
		self.AddItemData(itemVnum, metinSlot, attrSlot)

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AppendChangeLookInfoExchangeWIndow(1,slotIndex)

#Add new func in same class
	if app.BL_TRANSMUTATION_SYSTEM:
		def AppendChangeLookInfoExchangeWIndow(self, type, slotIndex):
			if type == 0:
				changelookvnum = exchange.GetChangeLookVnumFromSelf(slotIndex)
			elif type == 1:
				changelookvnum = exchange.GetChangeLookVnumFromTarget(slotIndex)
			if not changelookvnum == 0:
				self.AppendSpace(5)
				self.AppendTextLine("[ " + localeInfo.CHANGE_LOOK_TITLE+" ]", self.CHANGELOOK_TITLE_COLOR)
				itemName = item.GetItemNameByVnum(changelookvnum)
				
				if item.GetItemType() == item.ITEM_TYPE_COSTUME:
					if item.GetItemSubType() == item.COSTUME_TYPE_BODY:
						malefemale = ""
						if item.IsAntiFlag(item.ITEM_ANTIFLAG_MALE):
							malefemale = localeInfo.FOR_FEMALE

						if item.IsAntiFlag(item.ITEM_ANTIFLAG_FEMALE):
							malefemale = localeInfo.FOR_MALE
						itemName += " ( " + malefemale +  " )"
						
				textLine = self.AppendTextLine(itemName, self.CHANGELOOK_ITEMNAME_COLOR, True)
				textLine.SetFeather()

#Find in def SetPrivateShopBuilderItem(self, invenType, invenPos, privateShopSlotIndex):
		self.AddItemData(itemVnum, metinSlot, attrSlot)

#Change
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AddItemData(itemVnum, metinSlot, attrSlot,0,0,invenType,invenPos)
		else:
			self.AddItemData(itemVnum, metinSlot, attrSlot)

#Add new func in same class
	if app.BL_TRANSMUTATION_SYSTEM:
		def SetChangeLookWindowItem(self, slotIndex):
			inventoryslotindex = player.GetChangeLookItemInvenSlot(slotIndex)
			if inventoryslotindex == player.ITEM_SLOT_COUNT:
				return
			itemVnum = player.GetItemIndex(player.INVENTORY, inventoryslotindex)
			if 0 == itemVnum:
				return
			self.ClearToolTip()
			metinSlot = [player.GetItemMetinSocket(player.INVENTORY, inventoryslotindex, i) for i in xrange(player.METIN_SOCKET_MAX_NUM)]
			attrSlot = [player.GetItemAttribute(player.INVENTORY, inventoryslotindex, i) for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM)]
			self.AddItemData(itemVnum, metinSlot, attrSlot, 0, 0, player.INVENTORY, inventoryslotindex)

#Find in def SetSafeBoxItem(self, slotIndex):
		self.AddItemData(itemVnum, metinSlot, attrSlot, safebox.GetItemFlags(slotIndex))

#Change
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AddItemData(itemVnum, metinSlot, attrSlot, safebox.GetItemFlags(slotIndex), 0, player.SAFEBOX, slotIndex)
		else:
			self.AddItemData(itemVnum, metinSlot, attrSlot, safebox.GetItemFlags(slotIndex))

#Find in def SetMallItem(self, slotIndex):
		self.AddItemData(itemVnum, metinSlot, attrSlot)

#Change
		if app.BL_TRANSMUTATION_SYSTEM:
			self.AddItemData(itemVnum, metinSlot, attrSlot, 0, 0, player.MALL, slotIndex)
		else:
			self.AddItemData(itemVnum, metinSlot, attrSlot)

#Find
	def __AppendAttackGradeInfo(self):
		atkGrade = item.GetValue(1)
		self.AppendTextLine(localeInfo.TOOLTIP_ITEM_ATT_GRADE % atkGrade, self.GetChangeTextLineColor(atkGrade))

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		def AppendChangeLookInfoItemVnum(self, changelookvnum):
			if not changelookvnum == 0:
				self.AppendSpace(5)
				self.AppendTextLine("[ " + localeInfo.CHANGE_LOOK_TITLE+" ]", self.CHANGELOOK_TITLE_COLOR)
				itemName = item.GetItemNameByVnum(changelookvnum)
				
				if item.GetItemType() == item.ITEM_TYPE_COSTUME:
					if item.GetItemSubType() == item.COSTUME_TYPE_BODY:
						malefemale = ""
						if item.IsAntiFlag(item.ITEM_ANTIFLAG_MALE):
							malefemale = localeInfo.FOR_FEMALE

						if item.IsAntiFlag(item.ITEM_ANTIFLAG_FEMALE):
							malefemale = localeInfo.FOR_MALE
						itemName += " ( " + malefemale +  " )"
						
				textLine = self.AppendTextLine(itemName, self.CHANGELOOK_ITEMNAME_COLOR, True)
				textLine.SetFeather()
		
		def AppendChangeLookInfoShopWIndow(self, slotIndex):
			changelookvnum = shop.GetItemChangeLookVnum(slotIndex)
			if not changelookvnum == 0:
				self.AppendSpace(5)
				self.AppendTextLine("[ " + localeInfo.CHANGE_LOOK_TITLE+" ]", self.CHANGELOOK_TITLE_COLOR)
				itemName = item.GetItemNameByVnum(changelookvnum)
				
				if item.GetItemType() == item.ITEM_TYPE_COSTUME:
					if item.GetItemSubType() == item.COSTUME_TYPE_BODY:
						malefemale = ""
						if item.IsAntiFlag(item.ITEM_ANTIFLAG_MALE):
							malefemale = localeInfo.FOR_FEMALE

						if item.IsAntiFlag(item.ITEM_ANTIFLAG_FEMALE):
							malefemale = localeInfo.FOR_MALE
						itemName += " ( " + malefemale +  " )"
						
				textLine = self.AppendTextLine(itemName, self.CHANGELOOK_ITEMNAME_COLOR, True)
				textLine.SetFeather()

#Find
	def AddItemData(self, itemVnum, metinSlot, attrSlot = 0, flags = 0, unbindTime = 0):

#Change
	# def AddItemData(self, itemVnum, metinSlot, attrSlot = 0, flags = 0, unbindTime = 0):
	def AddItemData(self, itemVnum, metinSlot, attrSlot = 0, flags = 0, unbindTime = 0, window_type = player.INVENTORY, slotIndex = -1):

#Find in if item.ITEM_TYPE_WEAPON == itemType:
			self.__AppendAttributeInformation(attrSlot)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				self.AppendChangeLookInformation(window_type, slotIndex)

#Find in elif item.ITEM_TYPE_ARMOR == itemType:
			self.__AppendAttributeInformation(attrSlot)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				self.AppendChangeLookInformation(window_type, slotIndex)

#Find in elif 0 != isCostumeItem:
			self.__AppendAttributeInformation(attrSlot)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				# if item.GetItemSubType() == item.COSTUME_TYPE_WEAPON or item.GetItemSubType() == item.COSTUME_TYPE_BODY:
				if item.GetItemSubType() == item.COSTUME_TYPE_BODY:
					self.AppendChangeLookInformation(window_type, slotIndex)

#Find
	def __GetAffectString(self, affectType, affectValue):
		if 0 == affectType:
			return None

		if 0 == affectValue:
			return None

		try:
			return self.AFFECT_DICT[affectType](affectValue)
		except TypeError:
			return "UNKNOWN_VALUE[%s] %s" % (affectType, affectValue)
		except KeyError:
			return "UNKNOWN_TYPE[%s] %s" % (affectType, affectValue)

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		def AppendChangeLookInformation(self,window_type, slotIndex):
			if window_type == player.SAFEBOX:
				changelookvnum = safebox.GetItemChangeLookVnum(slotIndex)
			elif window_type == player.MALL:
				changelookvnum = safebox.GetMallItemChangeLookVnum(slotIndex)
			# elif window_type == player.ACCEREFINE:
			# 	changelookvnum = player.GetAcceWindowChangeLookVnum(slotIndex)
			else:
				changelookvnum = player.GetChangeLookVnum(window_type, slotIndex)

			if not changelookvnum == 0:
				self.AppendSpace(5)
				self.AppendTextLine("[ " + localeInfo.CHANGE_LOOK_TITLE+" ]", self.CHANGELOOK_TITLE_COLOR)
				itemName = item.GetItemNameByVnum(changelookvnum)
				
				if item.GetItemType() == item.ITEM_TYPE_COSTUME:
					if item.GetItemSubType() == item.COSTUME_TYPE_BODY:
						malefemale = ""
						if item.IsAntiFlag(item.ITEM_ANTIFLAG_MALE):
							malefemale = localeInfo.FOR_FEMALE

						if item.IsAntiFlag(item.ITEM_ANTIFLAG_FEMALE):
							malefemale = localeInfo.FOR_MALE
						itemName += " ( " + malefemale +  " )"
						
				textLine = self.AppendTextLine(itemName, self.CHANGELOOK_ITEMNAME_COLOR, True)
				textLine.SetFeather()

#Find
class HyperlinkItemToolTip(ItemToolTip):

#Change
class HyperlinkItemToolTip(ItemToolTip):
	def __init__(self):
		ItemToolTip.__init__(self, isPickable=True)

	def SetHyperlinkItem(self, tokens):
		minTokenCount = 3 + player.METIN_SOCKET_MAX_NUM
		if app.BL_TRANSMUTATION_SYSTEM:
			minTokenCount += 1
		maxTokenCount = minTokenCount + 2 * player.ATTRIBUTE_SLOT_MAX_NUM
		if tokens and len(tokens) >= minTokenCount and len(tokens) <= maxTokenCount:
			head, vnum, flag = tokens[:3]
			itemVnum = int(vnum, 16)
			metinSlot = [int(metin, 16) for metin in tokens[3:6]]

			if app.BL_TRANSMUTATION_SYSTEM:
				changelookvnum = int(tokens[6],16)
				rests = tokens[7:]
			else:
				rests = tokens[6:]
			if rests:
				attrSlot = []

				rests.reverse()
				while rests:
					key = int(rests.pop(), 16)
					if rests:
						val = int(rests.pop())
						attrSlot.append((key, val))

				attrSlot += [(0, 0)] * (player.ATTRIBUTE_SLOT_MAX_NUM - len(attrSlot))
			else:
				attrSlot = [(0, 0)] * player.ATTRIBUTE_SLOT_MAX_NUM

			self.ClearToolTip()
			self.AddItemData(itemVnum, metinSlot, attrSlot)
			if app.BL_TRANSMUTATION_SYSTEM:
				self.AppendChangeLookInfoItemVnum(changelookvnum)

			ItemToolTip.OnUpdate(self)

	def OnUpdate(self):
		pass

	def OnMouseLeftButtonDown(self):
		self.Hide()