#ifndef TROLL_STATE_HPP
#define TROLL_STATE_HPP

#include "../State.hpp"
#include "../../entities/troll/Troll.hpp"

class TrollStateAttack : public State {
	public:
		TrollStateAttack (void);
		TrollStateAttack (const TrollStateAttack& ctor);
		~TrollStateAttack (void);

		void execute (Troll *troll);
};

class TrollStatePeaceful : public State {
	public:
		TrollStatePeaceful (void);
		TrollStatePeaceful (const TrollStatePeaceful& ctor);
		~TrollStatePeaceful (void);

		void execute (Troll *troll);
};

#endif
