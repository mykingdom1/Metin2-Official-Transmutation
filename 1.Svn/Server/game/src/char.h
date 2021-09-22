///Add
#if defined(__BL_TRANSMUTATION__)
#include "Transmutation.h"
#endif

//Find
		int				GetSyncHackCount() { return m_iSyncHackCount; }

///Add
#if defined(__BL_TRANSMUTATION__)
	public:
		void			SetTransmutation(CTransmutation* c);
		CTransmutation*	GetTransmutation() const;
	protected:
		CTransmutation*	m_pkTransmutation;
#endif