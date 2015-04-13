#include "Troll.hpp"
#include <stdio.h>

Troll::Troll(void) {
	mCurrentState = NULL;
	anger = 0;
}

Troll::~Troll(void) {
	mCurrentState = NULL;
	anger = 0;
}

bool Troll::isAngered(void) {
	if (anger == 10) {
		return true;
	}

	return false;
}

bool Troll::isPeaceful(void) {
	if (anger == 0) {
		return true;
	}

	return false;
}

void Troll::hitEnemy(void) {
	fprintf(stdout, "ME IS ANGRY! ME BASH FOE!\n");

	anger--;
}

void Troll::getDisturbed(void) {
	fprintf(stdout, "UGH THOSE ANNOYING FAERIES!\n");

	anger += 0.9;
}

void Troll::update() {
	mCurrentState->execute(this);
}

void Troll::changeState(State *const newState) {
	if (newState) {
		delete mCurrentState;
		mCurrentState = newState;
	} else {
		fprintf(stderr, "newState is not a valid state!\n");
	}
}
