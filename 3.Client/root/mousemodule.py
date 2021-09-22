#Find
			elif Type == player.SLOT_TYPE_QUICK_SLOT:
				(quickSlotType, position) = player.GetGlobalQuickSlot(SlotNumber)

				if quickSlotType == player.SLOT_TYPE_INVENTORY:

					itemIndex = player.GetItemIndex(position)
					item.SelectItem(itemIndex)
					self.AttachedIconHandle = item.GetIconInstance()
					(width, height) = item.GetItemSize()

				elif quickSlotType == player.SLOT_TYPE_SKILL:
					skillIndex = player.GetSkillIndex(position)
					skillGrade = player.GetSkillGrade(position)
					self.AttachedIconHandle = skill.GetIconInstanceNew(skillIndex, skillGrade)

				elif quickSlotType == player.SLOT_TYPE_EMOTION:
					image = player.GetEmotionIconImage(position)
					self.AttachedIconHandle = grpImage.GenerateFromHandle(image)

#Add
			if app.BL_TRANSMUTATION_SYSTEM:
				if Type == player.SLOT_TYPE_CHANGE_LOOK:
					item.SelectItem(self.AttachedItemIndex)
					self.AttachedIconHandle = item.GetIconInstance()

					if not self.AttachedIconHandle:
						self.AttachedIconHandle = 0
						self.DeattachObject()
						return

					(width, height) = item.GetItemSize()