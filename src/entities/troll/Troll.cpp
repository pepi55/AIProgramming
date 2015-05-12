#include <stdio.h>

#include "../../states/troll/TrollState.hpp"
#include "Troll.hpp"

Troll::Troll(int id) : BaseGameEntity(id), mHunger(0), mFatigue(0), mFoodGathered(0) {
	mStateMachine = new StateMachine<Troll>(this);

	mStateMachine->setCurrentState(
}

Troll::~Troll(void) {
	mHunger = 0;
	mFatigue = 0;
	mFoodGathered = 0;

	delete mStateMachine; //mCurrentState;
}

void Troll::update() {
	if (mStateMachine) {
		mStateMachine->update();
	} else {
		fprintf(stderr, "mStateMachine is not valid!\n");
	}
}

void Troll::changeState(State<Troll> *const newState) {
	if (newState) {
		delete mCurrentState;
		mCurrentState = newState;
	} else {
		fprintf(stderr, "newState is not a valid state!\n");
	}
}

bool Troll::isHungry(void) {
	return mHunger >= 5;
}

int Troll::getHunger(void) {
	return mHunger;
}

void Troll::setHunger(int hunger) {
	mHunger = hunger;
}

int Troll::getFatigue(void) {
	return mFatigue;
}

void Troll::setFatigue(int fatigue) {
	mFatigue = fatigue;
}

int Troll::getFoodGathered(void) {
	return mFoodGathered;
}

void Troll::setFoodGathered(int foodGathered) {
	mFoodGathered = foodGathered;
}

Locations Troll::getLocation(void) {
	return mLocation;
}

void Troll::setLocation(Locations location) {
	mLocation = location;
}
