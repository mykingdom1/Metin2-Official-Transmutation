//Find
	Set(HEADER_CG_GUILD, sizeof(TPacketCGGuild), "Guild", true);

///Add
#if defined(__BL_TRANSMUTATION__)
	Set(HEADER_CG_TRANSMUTATION, sizeof(TPacketCGTransmutation), "Transmutation", true);
#endif