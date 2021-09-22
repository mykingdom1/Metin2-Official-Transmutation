#Find
	def HideRequirementSign(self, slotNumber):
		wndMgr.HideRequirementSign(self.hWnd, slotNumber)

#Add
	if app.BL_TRANSMUTATION_SYSTEM:
		def SetSlotCoverImage(self, slotindex, filename):
			wndMgr.SetSlotCoverImage(self.hWnd, slotindex, filename)

		def EnableSlotCoverImage(self, slotindex, onoff):
			wndMgr.EnableSlotCoverImage(self.hWnd, slotindex, onoff)
		
		def ActivateNewSlotEffect(self, slotNumber):
			wndMgr.ActivateNewSlotEffect(self.hWnd, slotNumber)

		def DeactivateNewSlotEffect(self, slotNumber):
			wndMgr.DeactivateNewSlotEffect(self.hWnd, slotNumber)
		
		def SetNewSlotDiffuseColor(self, slotindex, colortype):
			wndMgr.SetNewSlotDiffuseColor(self.hWnd, slotindex, colortype)