#ifndef TROLL_HPP
#define TROLL_HPP

#include "../../states/State.hpp"
#include "../BaseGameEntity.hpp"
#include "../../enums/Locations.hpp"

class State;

class Troll : public BaseGameEntity {
	public:
		Troll (int id);
		~Troll (void);

		void update (void);
		void changeState (State *const newState);

	private:
		int hunger;
		int fatigue;
		int food; //Gathered

		Locations mLocation;
		State *mCurrentState;
};

#endif
