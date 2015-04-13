#ifndef TROLL_STATE_HPP
#define TROLL_STATE_HPP

#include "../State.hpp"
#include "../../entities/Troll.hpp"

class TrollStateAttack : public State {
	public:
		TrollStateAttack(void);
		~TrollStateAttack(void);

		void checkCurrentState(void);

		void execute(Troll *troll);
};

class TrollStatePeaceful : public State {
	public:
		TrollStatePeaceful(void);
		~TrollStatePeaceful(void);

		void checkCurrentState(void);

		void execute(Troll *troll);
};

#endif
