//Find
				"SELECT id, window+0, pos, count, vnum, socket0, socket1, socket2, "

///Change
#if defined(__BL_TRANSMUTATION__)
				"SELECT id, window+0, pos, count, vnum, transmutation, socket0, socket1, socket2, "
#else
				"SELECT id, window+0, pos, count, vnum, socket0, socket1, socket2, "
#endif

//Find
			"REPLACE INTO item%s (id, owner_id, window, pos, count, vnum, socket0, socket1, socket2, "

///Add
#if defined(__BL_TRANSMUTATION__)
			"REPLACE INTO item%s (id, owner_id, window, pos, count, vnum, transmutation, socket0, socket1, socket2, "
#else
			"REPLACE INTO item%s (id, owner_id, window, pos, count, vnum, socket0, socket1, socket2, "
#endif

//Find in same func
			"VALUES(%u, %u, %d, %d, %u, %u, %ld, %ld, %ld, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",

///Change
#if defined(__BL_TRANSMUTATION__)
			"VALUES(%u, %u, %d, %d, %u, %u, %u, %ld, %ld, %ld, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
#else
			"VALUES(%u, %u, %d, %d, %u, %u, %ld, %ld, %ld, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
#endif

//Find in same func
			p->vnum,

///Add
#if defined(__BL_TRANSMUTATION__)
			p->dwTransmutationVnum,
#endif