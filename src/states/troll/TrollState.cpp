#include <stdio.h>
#include "TrollState.hpp"

/*	ATTACK STATE	*/
TrollStateAttack::TrollStateAttack(void) {
}

TrollStateAttack::~TrollStateAttack(void) {
}

void TrollStateAttack::enter(Troll *troll) {
	if (troll) {}
}

void TrollStateAttack::execute(Troll *troll) {
	if (troll) {}
}

void TrollStateAttack::exit(Troll *troll) {
	if (troll) {}
}
/*	END ATTACK STATE	*/

/*	PEACEFUL STATE	*/
TrollStatePeaceful::TrollStatePeaceful(void) {
}

TrollStatePeaceful::~TrollStatePeaceful(void) {
}

void TrollStatePeaceful::enter(Troll *troll) {
	if (troll) {}
}

void TrollStatePeaceful::execute(Troll *troll) {
	if (troll) {}
}

void TrollStatePeaceful::exit(Troll *troll) {
	if (troll) {}
}
/*	END PEACEFUL STATE	*/
