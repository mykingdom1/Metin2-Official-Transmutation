#Find in def RefreshCostumeSlot(self):
			self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), 0)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				if not player.GetChangeLookVnum(player.EQUIPMENT, slotNumber) == 0:
					self.wndEquip.SetSlotCoverImage(slotNumber,"icon/item/ingame_convert_Mark.tga")
				else:
					self.wndEquip.EnableSlotCoverImage(slotNumber,False)

#Find
			self.equipmentTab.append(self.GetChild("Equipment_Tab_02"))

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				self.dlgQuestion = uiCommon.QuestionDialog2()
				self.dlgQuestion.Close()
                self.listHighlightedChangeLookSlot = []

#Find in def Destroy(self):
		if self.wndBelt:
			self.wndBelt.Destroy()
			self.wndBelt = None

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.dlgQuestion = None

#Find in def RefreshBagSlotWindow(self):
		self.wndItem.RefreshSlot()

#Add above
			if app.BL_TRANSMUTATION_SYSTEM:
				if not player.GetChangeLookVnum(player.INVENTORY, slotNumber) == 0:
					self.wndItem.SetSlotCoverImage(i,"icon/item/ingame_convert_Mark.tga")
				else:
					self.wndItem.EnableSlotCoverImage(i,False)
				self.__HighlightSlot_Refresh()

#Find in def RefreshEquipSlotWindow(self):
			setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				if not player.GetChangeLookVnum(player.EQUIPMENT, slotNumber) == 0:
					self.wndEquip.SetSlotCoverImage(slotNumber,"icon/item/ingame_convert_Mark.tga")
				else:
					self.wndEquip.EnableSlotCoverImage(slotNumber,False)

#Find in def SelectEmptySlot(self, selectedSlotPos):
		if constInfo.GET_ITEM_QUESTION_DIALOG_STATUS() == 1:
			return

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			if player.GetChangeLookWindowOpen() == 1:
				return

#Find in def __DropSrcItemToDestItemInInventory(self, srcItemVID, srcItemSlotPos, dstItemSlotPos):
		if srcItemSlotPos == dstItemSlotPos:
			return

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			if player.GetChangeLookWindowOpen() == 1:
				return

#Find
			# snd.PlaySound("sound/ui/drop.wav")

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				if item.IsChangeLookClearScroll(srcItemVID):
					if player.CanChangeLookClearItem(srcItemVID, player.INVENTORY, dstItemSlotPos):
						self.__OpenQuestionDialog(srcItemSlotPos, dstItemSlotPos)
						return

#Find
	def SetItemToolTip(self, tooltipItem):
		self.tooltipItem = tooltipItem

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		def IsDlgQuestionShow(self):
			if self.dlgQuestion.IsShow():
				return True
			else:
				return False
		
		def CancelDlgQuestion(self):
			self.__Cancel()
		
		def __OpenQuestionDialog(self, srcItemPos, dstItemPos):
			if self.interface.IsShowDlgQuestionWindow():
				self.interface.CloseDlgQuestionWindow()
				
			getItemVNum=player.GetItemIndex
			self.srcItemPos = srcItemPos
			self.dstItemPos = dstItemPos
			
			self.dlgQuestion.SetAcceptEvent(ui.__mem_func__(self.__Accept))
			self.dlgQuestion.SetCancelEvent(ui.__mem_func__(self.__Cancel))

			self.dlgQuestion.SetText1("%s" % item.GetItemName(getItemVNum(srcItemPos)) )
			self.dlgQuestion.SetText2(localeInfo.INVENTORY_REALLY_USE_ITEM)

			self.dlgQuestion.Open()
			
		def __Accept(self):
			self.dlgQuestion.Close()
			self.__SendUseItemToItemPacket(self.srcItemPos, self.dstItemPos)
			self.srcItemPos = (0, 0)
			self.dstItemPos = (0, 0)

		def __Cancel(self):
			self.srcItemPos = (0, 0)
			self.dstItemPos = (0, 0)
			self.dlgQuestion.Close()

#Find in def __IsUsableItemToItem(self, srcItemVNum, srcSlotPos):
		elif (player.GetItemFlags(srcSlotPos) & ITEM_FLAG_APPLICABLE) == ITEM_FLAG_APPLICABLE:
			return True
		else:

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				if item.IsChangeLookClearScroll(srcItemVNum):
					return True

#Find in def __CanUseSrcItemToDstItem(self, srcItemVNum, srcSlotPos, dstSlotPos):
		elif (player.GetItemFlags(srcSlotPos) & ITEM_FLAG_APPLICABLE) == ITEM_FLAG_APPLICABLE:
			return True

		else:

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				if player.CanChangeLookClearItem(srcItemVNum, player.INVENTORY, dstSlotPos):
					return True

#Find in def __UseItem(self, slotIndex):
		item.SelectItem(ItemVNum)

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			if player.GetChangeLookWindowOpen() == 1:
				return

#Find
	def SetDragonSoulRefineWindow(self, wndDragonSoulRefine):
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoulRefine = wndDragonSoulRefine

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		## HilightSlot Change
		def DeactivateSlot(self, slotindex, type):
			if type == wndMgr.HILIGHTSLOT_CHANGE_LOOK:
				self.__DelHighlightSlotChangeLook(slotindex)

		## HilightSlot Change
		def ActivateSlot(self, slotindex, type):
			if type == wndMgr.HILIGHTSLOT_CHANGE_LOOK:
				self.__AddHighlightSlotChangeLook(slotindex)
		
		def __AddHighlightSlotChangeLook(self, slotIndex):
			if not slotIndex in self.listHighlightedChangeLookSlot:
				self.listHighlightedChangeLookSlot.append(slotIndex)

		def __DelHighlightSlotChangeLook(self, slotIndex):
			if slotIndex in self.listHighlightedChangeLookSlot:
				if slotIndex >= player.INVENTORY_PAGE_SIZE:
					self.wndItem.DeactivateNewSlotEffect(slotIndex - (self.inventoryPageIndex * player.INVENTORY_PAGE_SIZE) )
				else:
					self.wndItem.DeactivateNewSlotEffect(slotIndex)
				self.listHighlightedChangeLookSlot.remove(slotIndex)

		def __HighlightSlot_Refresh(self):
		## 악세서리.
			for i in xrange(self.wndItem.GetSlotCount()):
				slotNumber = self.__InventoryLocalSlotPosToGlobalSlotPos(i)
				if slotNumber in self.listHighlightedChangeLookSlot:
					self.wndItem.ActivateNewSlotEffect(i)
					self.wndItem.SetNewSlotDiffuseColor(i, wndMgr.COLOR_TYPE_RED)

		def __HighlightSlot_Clear(self):
		## 악세서리
			for i in xrange(self.wndItem.GetSlotCount()):
				slotNumber = self.__InventoryLocalSlotPosToGlobalSlotPos(i)
				if slotNumber in self.listHighlightedChangeLookSlot:
					self.wndItem.DeactivateNewSlotEffect(i)
					self.listHighlightedChangeLookSlot.remove(slotNumber)