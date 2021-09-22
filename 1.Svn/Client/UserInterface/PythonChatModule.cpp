//Find in PyObject * chatGetLinkFromHyperlink(PyObject * poSelf, PyObject * poArgs)
		if (CItemManager::Instance().GetItemDataPointer(htoi(results[1].c_str()), &pItemData))
		{
			...
		}

///Change
		if (CItemManager::Instance().GetItemDataPointer(htoi(results[1].c_str()), &pItemData))
		{
			char buf[1024] = { 0 };
			char itemlink[256];
			int len;
			bool isAttr = false;

			len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x", 
					htoi(results[1].c_str()),
					htoi(results[2].c_str()),
					htoi(results[3].c_str()),
					htoi(results[4].c_str()),
					htoi(results[5].c_str()));

#if defined(__BL_TRANSMUTATION__)
			len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x",
				htoi(results[6].c_str()));
#endif

#if defined(__BL_TRANSMUTATION__)
			if (results.size() >= 8 + 1)
#else
			if (results.size() >= 8)
#endif
			{
#if defined(__BL_TRANSMUTATION__)
				for (int i = 6 + 1; i < results.size(); i += 2)
#else
				for (int i = 6; i < results.size(); i += 2)
#endif
				{
					len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x:%I64d", 
							htoi(results[i].c_str()),
							atoi(results[i+1].c_str()));
					isAttr = true;
				}

				
			}

			if (isAttr)
				//"item:锅龋:敲贰弊:家南0:家南1:家南2"
				snprintf(buf, sizeof(buf), "|cffffc700|H%s|h[%s]|h|r", itemlink, pItemData->GetName());
			else
				snprintf(buf, sizeof(buf), "|cfff1e6c0|H%s|h[%s]|h|r", itemlink, pItemData->GetName());

			return Py_BuildValue("s", buf);
		}