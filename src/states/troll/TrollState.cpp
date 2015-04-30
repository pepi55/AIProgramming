#include <stdio.h>

#include "TrollState.hpp"
#include "../../enums/EntityNames.hpp"

/*	ATTACK STATE	*/
TrollStateHunt::TrollStateHunt(void) {
}

TrollStateHunt::~TrollStateHunt(void) {
}

void TrollStateHunt::enter(Troll *troll) {
	if (troll) {
		if (troll->getLocation() != HUNTING_GROUNDS) {
			troll->setLocation(HUNTING_GROUNDS);
		}

		fprintf(stdout, "%s: I IS GOING HUNTING!\n", getEntityName(troll->getID()).c_str());
	}
}

void TrollStateHunt::execute(Troll *troll) {
	if (troll) {
		/*Dispatch event of dealing dmg*/

		if (troll->isHungry()) {
		}

		troll->setHunger(troll->getHunger() + 1);
		troll->setFatigue(troll->getFatigue() + 1);
		troll->setFoodGathered(troll->getFoodGathered() + 1);

		fprintf(stdout, "%s: FOOD GET!\n", getEntityName(troll->getID()).c_str());
	}
}

void TrollStateHunt::exit(Troll *troll) {
	if (troll) {
		fprintf(stdout, "%s: I IS NO MORE HUNTING...\n", getEntityName(troll->getID()).c_str());
	}
}
/*	END ATTACK STATE	*/

/*	PEACEFUL STATE	*/
TrollStatePeaceful::TrollStatePeaceful(void) {
}

TrollStatePeaceful::~TrollStatePeaceful(void) {
}

void TrollStatePeaceful::enter(Troll *troll) {
	if (troll) {
		if (troll->getLocation() != FLOWER_FIELD) {
			troll->setLocation(FLOWER_FIELD);
		}

		fprintf(stdout, "%s: I IS MELLOW...\n", getEntityName(troll->getID()).c_str());
	}
}

void TrollStatePeaceful::execute(Troll *troll) {
	if (troll) {
	}
}

void TrollStatePeaceful::exit(Troll *troll) {
	if (troll) {
		fprintf(stdout, "%s: I DO SOMETHING NOW!\n", getEntityName(troll->getID()).c_str());
	}
}
/*	END PEACEFUL STATE	*/
