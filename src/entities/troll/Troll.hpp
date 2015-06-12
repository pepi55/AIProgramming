#ifndef TROLL_HPP
#define TROLL_HPP

#include "../../states/StateMachine.hpp"
#include "../BaseGameEntity.hpp"
#include "../../enums/Locations.hpp"

class Troll : public BaseGameEntity {
	public:
		Troll (int id);
		~Troll (void);

		void update (void);
		void changeState (State<Troll> *const newState);

		bool isHungry (void);
		bool isTired (void);
		bool enoughFoodGathered (void);

		void addToFoodCarried (const int value);
		void addToFoodGathered (const int value);

		void decreaseFatigue (void);
		void increaseFatigue (void);

		int foodReserve (void) const;

		Locations getLocation (void);
		void setLocation (Locations location);

		StateMachine<Troll> *getStateMachine (void) const;

	private:
		int mHunger;
		int mFatigue;
		int mFoodCarried;
		int mFoodGathered;

		Locations mLocation;
		StateMachine<Troll> *mStateMachine;
};

#endif
