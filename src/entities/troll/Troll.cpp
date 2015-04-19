#include <stdio.h>

#include "../../states/troll/TrollState.hpp"
#include "Troll.hpp"

Troll::Troll(int id) : BaseGameEntity(id), mHunger(0), mFatigue(0), mFoodGathered(0), mCurrentState(new TrollStatePeaceful()) {
}

Troll::~Troll(void) {
	mHunger = 0;
	mFatigue = 0;
	mFoodGathered = 0;

	delete mCurrentState;
}

void Troll::update() {
	if (mCurrentState) {
		mCurrentState->execute(this);
	} else {
		fprintf(stderr, "mCurrentState is not a valid state!\n");
	}
}

void Troll::changeState(State *const newState) {
	if (newState) {
		delete mCurrentState;
		mCurrentState = newState;
	} else {
		fprintf(stderr, "newState is not a valid state!\n");
	}
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
