#Add
if app.BL_TRANSMUTATION_SYSTEM:
	import uiChangeLook
	import shop

#Find in def __init__(self):
		self.equipmentDialogDict = {}

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.wndChangeLook = None

#Find
		self.wndMall = wndMall

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.wndChangeLook = uiChangeLook.ChangeLookWindow()

#Find
		self.wndGuild.SetSkillToolTip(self.tooltipSkill)

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			self.wndChangeLook.SetItemToolTip(self.tooltipItem)

#Find
		if self.wndGuildBuilding:
			self.wndGuildBuilding.Destroy()

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			if self.wndChangeLook:
				del self.wndChangeLook

#Find in def RefreshInventory(self):
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.RefreshItemSlot()

#Add
		if app.BL_TRANSMUTATION_SYSTEM:
			if player.GetChangeLookWindowOpen() == 1:
				self.wndChangeLook.RefreshChangeLookWindow()

#Add new funcs in same class
    if app.BL_TRANSMUTATION_SYSTEM:
		## HilightSlot Change			
		def DeactivateSlot(self, slotindex, type):
			self.wndInventory.DeactivateSlot(slotindex, type)

		## HilightSlot Change		
		def ActivateSlot(self, slotindex, type):
			self.wndInventory.ActivateSlot(slotindex, type)
		
		def ChangeWindowOpen(self, type):
			if self.wndChangeLook:
				self.wndChangeLook.Open(type)

#Find
	def ToggleExpandedButton(self):
		if False == player.IsObserverMode():
			if False == self.wndExpandedTaskBar.IsShow():
				self.wndExpandedTaskBar.Show()
				self.wndExpandedTaskBar.SetTop()
			else:
				self.wndExpandedTaskBar.Close()

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		def IsShowDlgQuestionWindow(self):
			if self.wndInventory.IsDlgQuestionShow():
				return True
			else:
				return False
		
		def CloseDlgQuestionWindow(self):
			if self.wndInventory.IsDlgQuestionShow():
				self.wndInventory.CancelDlgQuestion()

#Find
	def SetEquipmentDialogItem(self, vid, slotIndex, vnum, count):
		if not vid in self.equipmentDialogDict:
			return
		self.equipmentDialogDict[vid].SetEquipmentDialogItem(slotIndex, vnum, count)

#Change
	if app.BL_TRANSMUTATION_SYSTEM:
		def SetEquipmentDialogItem(self, vid, slotIndex, vnum, count, dwChangeLookVnum):
			if not vid in self.equipmentDialogDict:
				return
			self.equipmentDialogDict[vid].SetEquipmentDialogItem(slotIndex, vnum, count, dwChangeLookVnum)
	else:
		def SetEquipmentDialogItem(self, vid, slotIndex, vnum, count):
			if not vid in self.equipmentDialogDict:
				return
			self.equipmentDialogDict[vid].SetEquipmentDialogItem(slotIndex, vnum, count)