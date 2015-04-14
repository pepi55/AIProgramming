#include "Troll.hpp"
#include <stdio.h>

Troll::Troll(void) {
	mCurrentState = NULL;
	anger = 1;
}

Troll::~Troll(void) {
	mCurrentState = NULL;
	anger = 0;
}

bool Troll::isAngered(void) {
	if (anger > 0) {
		//fprintf(stdout, "%s\n", "MakeAngryCheck");

		return true;
	}
	//fprintf(stdout, "Anger lvl: %i\n", anger);

	return false;
}

bool Troll::isPeaceful(void) {
	if (anger < 0) {
		//fprintf(stdout, "%s\n", "MakePeacefulCheck");

		return true;
	}
	//fprintf(stdout, "Anger lvl: %i\n", anger);

	return false;
}

void Troll::hitEnemy(void) {
	fprintf(stdout, "ME IS ANGRY! ME BASH FOE!\n");

	anger -= 2;
}

void Troll::getDisturbed(void) {
	fprintf(stdout, "UGH THOSE ANNOYING FAERIES!\n");

	anger += 2;
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
