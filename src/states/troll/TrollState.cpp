#include "TrollState.hpp"
#include <stdio.h>

/*	ATTACK STATE	*/
TrollStateAttack::TrollStateAttack(void) {
	checkCurrentState();
}

TrollStateAttack::~TrollStateAttack(void) {
}

void TrollStateAttack::checkCurrentState(void) {
	//fprintf(stdout, "This is TrollAttackState\n");
}

void TrollStateAttack::execute(Troll *troll) {
	if (troll->isAngered()) {
		troll->hitEnemy();
	} else if (troll->isPeaceful()) {
		troll->changeState(new TrollStatePeaceful());
	}
}
/*	END ATTACK STATE	*/

/*	PEACEFUL STATE	*/
TrollStatePeaceful::TrollStatePeaceful(void) {
	checkCurrentState();
}

TrollStatePeaceful::~TrollStatePeaceful(void) {
}

void TrollStatePeaceful::checkCurrentState(void) {
	//fprintf(stdout, "This is TrollPeacefulState\n");
}

void TrollStatePeaceful::execute(Troll *troll) {
	if (troll->isPeaceful()) {
		troll->getDisturbed();
	} else if (troll->isAngered()) {
		troll->changeState(new TrollStateAttack());
	}
}
/*	END PEACEFUL STATE	*/
