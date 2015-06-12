#include <stdio.h>

#include "TrollState.hpp"
#include "../../entities/troll/Troll.hpp"
#include "../../enums/Locations.hpp"
#include "../../enums/EntityNames.hpp"

/*	GLOBAL STATE	*/
GlobalTrollState::GlobalTrollState(void) {
}

GlobalTrollState::~GlobalTrollState(void) {
}

void GlobalTrollState::enter(Troll *troll) {
	if (troll) {
	}
}

void GlobalTrollState::execute(Troll *troll) {
	if (troll) {
	}
}

void GlobalTrollState::exit(Troll *troll) {
	if (troll) {
	}
}
/*	END GLOBAL STATE	*/

/*	HUNT STATE	*/
TrollStateHunt::TrollStateHunt(void) {
}

TrollStateHunt::~TrollStateHunt(void) {
}

void TrollStateHunt::enter(Troll *troll) {
	if (troll) {
		if (troll->getLocation() != HUNTING_GROUNDS) {
			troll->setLocation(HUNTING_GROUNDS);

		fprintf(stdout, "%s: I IS GOING HUNTING!\n", getEntityName(troll->getID()).c_str());
		}
	}
}

void TrollStateHunt::execute(Troll *troll) {
	if (troll) {
		/*Dispatch event of dealing dmg*/

		troll->addToFoodCarried(1);

		troll->increaseFatigue();

		if (troll->enoughFoodGathered()) {
			troll->getStateMachine()->changeState(new TrollStatePeaceful);
		}

		if (troll->isHungry()) {
		}

		fprintf(stdout, "%s: FOOD GET!\n", getEntityName(troll->getID()).c_str());
	}
}

void TrollStateHunt::exit(Troll *troll) {
	if (troll) {
		fprintf(stdout, "%s: I IS NO MORE HUNTING...\n", getEntityName(troll->getID()).c_str());
	}
}
/*	END HUNT STATE	*/

/*	PEACEFUL STATE	*/
TrollStatePeaceful::TrollStatePeaceful(void) {
}

TrollStatePeaceful::~TrollStatePeaceful(void) {
}

void TrollStatePeaceful::enter(Troll *troll) {
	if (troll) {
		if (troll->getLocation() != CAVE) {
			troll->setLocation(CAVE);

		fprintf(stdout, "%s: I IS CONTENT...\n", getEntityName(troll->getID()).c_str());
		}
	}
}

void TrollStatePeaceful::execute(Troll *troll) {
	if (troll) {
		if (!troll->isTired()) {
			fprintf(stdout, "%s: I HAS RESTED...\n", getEntityName(troll->getID()).c_str());

			troll->getStateMachine()->changeState(new TrollStateHunt);
		} else {
			fprintf(stdout, "%s: zZzZzZz...\n", getEntityName(troll->getID()).c_str());

			troll->decreaseFatigue();
		}
	}
}

void TrollStatePeaceful::exit(Troll *troll) {
	if (troll) {
		fprintf(stdout, "%s: I DO SOMETHING NOW!\n", getEntityName(troll->getID()).c_str());
	}
}
/*	END PEACEFUL STATE	*/
