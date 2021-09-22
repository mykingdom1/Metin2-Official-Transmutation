//Find
	int item_get_level(lua_State* L)
	{
		...
	}

///Add
#if defined(__BL_TRANSMUTATION__)
	int item_get_transmutation(lua_State* L)
	{
		CQuestManager& q = CQuestManager::instance();

		if (q.GetCurrentItem())
			lua_pushnumber(L, q.GetCurrentItem()->GetTransmutationVnum());
		else
			lua_pushnumber(L, 0);

		return 1;
	}
#endif

//Find
			{ "get_level",		item_get_level		},

///Add
#if defined(__BL_TRANSMUTATION__)
			{ "get_transmutation",	item_get_transmutation		},
#endif