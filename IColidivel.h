#ifndef ICOLIDIVEL_H
#define ICOLIDIVEL_H
#include "IDesenhavel.h"

class IColidivel : public IDesenhavel
{
	public:
		bool virtual Comivel_pelo_pacman() = 0;
		void virtual Foi_comido() = 0;
		void virtual Comeu_pacman() {}
		virtual ~IColidivel() {}
};
#endif
