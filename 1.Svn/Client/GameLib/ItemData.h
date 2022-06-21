//Find
	void SetItemTableData(TItemTable* pItemTable);

///Add below
	/////
	// Mappers
public:
	// Weapon
	bool IsWeapon() const { return GetType() == ITEM_TYPE_WEAPON; }
	bool IsMainWeapon() const
	{
		return GetType() == ITEM_TYPE_WEAPON && (
			GetSubType() == WEAPON_SWORD
			|| GetSubType() == WEAPON_DAGGER
			|| GetSubType() == WEAPON_BOW
			|| GetSubType() == WEAPON_TWO_HANDED
			|| GetSubType() == WEAPON_BELL
			|| GetSubType() == WEAPON_FAN
			);
	}
	bool IsSword() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_SWORD; }
	bool IsDagger() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_DAGGER; }
	bool IsBow() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_BOW; }
	bool IsTwoHandSword() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_TWO_HANDED; }
	bool IsBell() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_BELL; }
	bool IsFan() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_FAN; }
	bool IsArrow() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_ARROW; }
	bool IsMountSpear() const { return GetType() == ITEM_TYPE_WEAPON && GetSubType() == WEAPON_MOUNT_SPEAR; }

	// Armor
	bool IsArmor() const { return GetType() == ITEM_TYPE_ARMOR; }
	bool IsArmorBody() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_BODY; }
	bool IsHelmet() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_HEAD; }
	bool IsShield() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_SHIELD; }
	bool IsWrist() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_WRIST; }
	bool IsShoe() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_FOOTS; }
	bool IsNecklace() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_NECK; }
	bool IsEarRing() const { return GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_EAR; }

#if defined(ENABLE_COSTUME_SYSTEM)
	// Costume
	bool IsCostume() const { return GetType() == ITEM_TYPE_COSTUME; }
	bool IsCostumeBody() const { return GetType() == ITEM_TYPE_COSTUME && GetSubType() == COSTUME_BODY; }
	bool IsCostumeHair() const { return GetType() == ITEM_TYPE_COSTUME && GetSubType() == COSTUME_HAIR; }
#	if defined(ENABLE_MOUNT_COSTUME_SYSTEM)
	bool IsCostumeMount() const { return GetType() == ITEM_TYPE_COSTUME && GetSubType() == COSTUME_MOUNT; }
#	endif
#	if defined(ENABLE_WEAPON_COSTUME_SYSTEM)
	bool IsCostumeWeapon() const { return GetType() == ITEM_TYPE_COSTUME && GetSubType() == COSTUME_WEAPON; }
#	endif
#endif