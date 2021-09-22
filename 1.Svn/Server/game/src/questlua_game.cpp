///Add
#if defined(__BL_TRANSMUTATION__)
#include "Transmutation.h"
#endif

//Find
	int game_web_mall(lua_State* L)
	{
		...
	}

///Add
#if defined(__BL_TRANSMUTATION__)
	int game_open_transmutation(lua_State* L)
	{
		if (lua_isboolean(L, 1))
		{
			const LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
			const bool bType = lua_toboolean(L, 1);
			CTransmutation::Open(ch, bType);
		}

		return 0;
	}
#endif

//Find
			{ "open_web_mall",				game_web_mall					},

///Add
#if defined(__BL_TRANSMUTATION__)
			{ "open_transmutation",			game_open_transmutation			},
#endif