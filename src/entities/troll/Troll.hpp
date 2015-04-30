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

		bool isHungry(void);
		bool isTired(void);

		int getHunger (void);
		void setHunger (int hunger);

		int getFatigue (void);
		void setFatigue (int fatigue);

		int getFoodGathered (void);
		void setFoodGathered (int foodGathered);

		Locations getLocation (void);
		void setLocation (Locations location);

	private:
		int mHunger;
		int mFatigue;
		int mFoodGathered;

		Locations mLocation;
		State *mCurrentState;
};

#endif
