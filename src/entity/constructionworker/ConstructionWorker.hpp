#ifndef CONSTRUCTION_WORKER_H
#define CONSTRUCTION_WORKER_H

#include <string>
#include <assert.h>

#include "../BaseGameEntity.hpp"
#include "../../enum/Locations.hpp"

class State;

//Amount of bricks the worker feels comfortable with
const int ConstWorkerComfortLevel = 5;
//Amount of bricks the worker can carry around
const int ConstWorkerMaxBricks = 3;
//Above this value worker is hungry
const int ConstWorkerHungerLvl = 5;
//Above this value worker is sleepy
const int ConstWorkerExhaustionThreshold = 5;

class ConstructionWorker : public BaseGameEntity {
	private:
		State *m_current_state;

		location_type m_location;

		//The amount of bricks the worker is carrying
		int m_bricks_carried;
		//Bricks used at the construction site
		int m_bricks_contributed;
		//The higher these values, the higher the worker's
		//primitive needs
		int m_hunger;
		int m_fatigue;

	public:
		ConstructionWorker(int id);

		void update(void);

		//Change the current state to the new state
		void changeState(State *new_state);

		location_type getLocation(void) const;
		void changeLocation(const location_type loc);

		int getBricksCarried(void) const;
		void setBricksCarried(const int val);
		void addToBricksCarried(const int val);

		bool handsFull(void) const;

		bool tired(void) const;
		void decreaseFatigue(int value = 1);
		void increaseFatigue(int value = 1);

		int bricksContributed(void) const;
		void setBricksContributed(const int val);
		void addToBricksContributed(const int val);

		bool hungry(void) const;
		void buyAndEatFood(void);
};

#endif
