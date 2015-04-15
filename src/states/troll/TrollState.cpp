#include "TrollState.hpp"
#include <stdio.h>

/*	ATTACK STATE	*/
TrollStateAttack::TrollStateAttack(void) {
}

TrollStateAttack::~TrollStateAttack(void) {
}

void TrollStateAttack::enter(Troll *troll) {
}

void TrollStateAttack::execute(Troll *troll) {
	if (troll->isAngered()) {
		troll->hitEnemy();
	} else if (troll->isPeaceful()) {
		troll->changeState(new TrollStatePeaceful());
	}
}

void TrollStateAttack::exit(Troll *troll) {
}
/*	END ATTACK STATE	*/

/*	PEACEFUL STATE	*/
TrollStatePeaceful::TrollStatePeaceful(void) {
}

TrollStatePeaceful::~TrollStatePeaceful(void) {
}

void TrollStatePeaceful::enter(Troll *troll) {
}

void TrollStatePeaceful::execute(Troll *troll) {
	if (troll->isPeaceful()) {
		troll->getDisturbed();
	} else if (troll->isAngered()) {
		troll->changeState(new TrollStateAttack());
	}
}

void TrollStatePeaceful::exit(Troll *troll) {
}
/*	END PEACEFUL STATE	*/
