#include <stdio.h>

#include "Troll.hpp"
#include "../../states/troll/TrollState.hpp"

Troll::Troll(int id) : BaseGameEntity(id), mHunger(0), mFatigue(0), mFoodCarried(0), mFoodGathered(0), mLocation(CAVE) {
	mStateMachine = new StateMachine<Troll>(this);

	mStateMachine->setCurrentState(new TrollStatePeaceful);
	mStateMachine->setGlobalState(new GlobalTrollState);
}

Troll::~Troll(void) {
	mHunger = 0;
	mFatigue = 0;
	mFoodGathered = 0;

	delete mStateMachine;
}

void Troll::update(void) {
	mHunger++;

	mStateMachine->update();
}

bool Troll::isHungry(void) {
	return mHunger >= 5; //If >5 is hungry
}

bool Troll::isTired(void) {
	return mFatigue >= 5; //If >5 is tired
}

bool Troll::enoughFoodGathered(void) {
	return mFoodCarried >= 3;
}

void Troll::addToFoodCarried(const int value) {
	mFoodCarried += value;

	if (mFoodCarried < 0) mFoodCarried = 0;
}

void Troll::addToFoodGathered(const int value) {
	mFoodGathered += value;

	if (mFoodGathered < 0) mFoodGathered = 0;
}

void Troll::decreaseFatigue(void) {
	mFatigue -= 1;
}

void Troll::increaseFatigue(void) {
	mFatigue += 1;
}

int Troll::foodReserve(void) const {
	return mFoodGathered;
}

Locations Troll::getLocation(void) {
	return mLocation;
}

void Troll::setLocation(Locations location) {
	mLocation = location;
}

StateMachine<Troll> *Troll::getStateMachine(void) const {
	return mStateMachine;
}
