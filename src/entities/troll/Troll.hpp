#ifndef TROLL_HPP
#define TROLL_HPP

#include "../../states/State.hpp"
#include "../BaseGameEntity.hpp"

class State;

class Troll : public BaseGameEntity {
	public:
		Troll (int id);
		~Troll (void);

		bool isAngered (void);
		bool isPeaceful (void);

		void hitEnemy (void);
		void getDisturbed (void);

		void update (void);
		void changeState (State *const newState);

	private:
		int anger;
		State *mCurrentState;
};

#endif
