///Add
#if defined(__BL_TRANSMUTATION__)
	PyModule_AddIntConstant(poModule, "BL_TRANSMUTATION_SYSTEM", true);
#else
	PyModule_AddIntConstant(poModule, "BL_TRANSMUTATION_SYSTEM", false);
#endif