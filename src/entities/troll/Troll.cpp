#include <stdio.h>

#include "../../states/troll/TrollState.hpp"
#include "Troll.hpp"

Troll::Troll(int id) : BaseGameEntity(id), hunger(0), fatigue(0), food(0), mCurrentState(new TrollStatePeaceful()) {
}

Troll::~Troll(void) {
	hunger = 0;
	fatigue = 0;
	food = 0;

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
