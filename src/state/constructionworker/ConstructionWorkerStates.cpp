#include "ConstructionWorkerStates.hpp"
#include "../State.hpp"
#include "../../entity/constructionworker/ConstructionWorker.hpp"
#include "../../enum/Locations.hpp"
#include "../../misc/GenericUtils.hpp"
#include "../../entity/EntityNames.hpp"

// GO_TO_DEPOT_AND_COLLECT_BRICKS
GoToDepotAndCollectBricks* GoToDepotAndCollectBricks::instance(void) {
	static GoToDepotAndCollectBricks instance;

	return &instance;
}

void GoToDepotAndCollectBricks::enter(ConstructionWorker *worker) {
	if (worker->getLocation() != DEPOT) {
		fprintf(stdout, "%s: Going to the depot to get some bricks!\n", GetNameOfEntity(worker->ID()).c_str());

		worker->changeLocation(DEPOT);
	}
}

void GoToDepotAndCollectBricks::execute(ConstructionWorker *worker) {
	//Worker collects bricks at the depot until in excess of MaxBricks.
	fprintf(stdout, "%s: Gathering some bricks.\n", GetNameOfEntity(worker->ID()).c_str());

	worker->addToBricksCarried(1);
	worker->increaseFatigue();

	if (worker->handsFull()) {
		worker->changeState(VisitConstructionSiteAndDropBricks::instance());
	}

	if (worker->hungry()) {
		worker->changeState(GoEat::instance());
	}
}

// END GO_TO_DEPOT_AND_COLLECT_BRICKS

// VISIT_CONSTRUCTION_SITE_AND_DROP_BRICKS

VisitConstructionSiteAndDropBricks *VisitConstructionSiteAndDropBricks::instance(void) {
	static VisitConstructionSiteAndDropBricks instance;

	return &instance;
}

void VisitConstructionSiteAndDropBricks::enter(ConstructionWorker *worker) {
	if (worker->getLocation() != CONSTRUCTION_SITE) {
		fprintf(stdout, "%s: Going to drop off the bricks I collected!\n", GetNameOfEntity(worker->ID()).c_str());

		worker->changeLocation(CONSTRUCTION_SITE);
	}
}

void VisitConstructionSiteAndDropBricks::execute(ConstructionWorker *worker) {
	//Drop off them brix
	fprintf(stdout, "%s: Dropping off bricks. Total bricks at site: %i\n", GetNameOfEntity(worker->ID()).c_str(), worker->bricksContributed());

	worker->addToBricksContributed(worker->getBricksCarried());
	worker->setBricksCarried(0);

	if (worker->bricksContributed() >= ConstWorkerComfortLevel) {
		fprintf(stdout, "%s: Enough hard work for today...\n", GetNameOfEntity(worker->ID()).c_str());

		worker->changeState(GoHomeAndSleep::instance());
	} else {
		worker->changeState(GoToDepotAndCollectBricks::instance());
	}
}

void VisitConstructionSiteAndDropBricks::exit(ConstructionWorker *worker) {
	fprintf(stdout, "%s: Leaving construction site.\n", GetNameOfEntity(worker->ID()).c_str());
}

// END VISIT_CONSTRUCTION_SITE_AND_SHIT_BRICKS

// GO_HOME_AND_SLEEP

GoHomeAndSleep *GoHomeAndSleep::instance(void) {
	static GoHomeAndSleep instance;

	return &instance;
}

void GoHomeAndSleep::enter(ConstructionWorker *worker) {
	if (worker->getLocation() != HOME) {
		fprintf(stdout, "%s: Goin' home!\n", GetNameOfEntity(worker->ID()).c_str());

		worker->changeLocation(HOME);
	}
}

void GoHomeAndSleep::execute(ConstructionWorker *worker) {
	if (!worker->tired()) {
		fprintf(stdout, "%s: Ahh, feeling well rested!\n", GetNameOfEntity(worker->ID()).c_str());

		worker->changeState(GoToDepotAndCollectBricks::instance());
	} else {
		fprintf(stdout, "%s: zzZZzz...\n", GetNameOfEntity(worker->ID()).c_str());

		worker->decreaseFatigue();
	}
}

void GoHomeAndSleep::exit(ConstructionWorker *worker) {
	fprintf(stdout, "%s: Leaving home.\n", GetNameOfEntity(worker->ID()).c_str());
}

// END GO_HOME_AND_SLEEP

// GO_EAT

GoEat *GoEat::instance(void) {
	static GoEat instance;

	return &instance;
}

void GoEat::enter(ConstructionWorker *worker) {
	if (worker->getLocation() != SNACKBAR) {
		fprintf(stdout, "%s: Gon' go eat some food, so I don't die.\n", GetNameOfEntity(worker->ID()).c_str());

		worker->changeLocation(SNACKBAR);
	}
}

void GoEat::execute(ConstructionWorker *worker) {
	if (worker->hungry()) {
		fprintf(stdout, "%s: Mmm that burger really hit the spot!\n", GetNameOfEntity(worker->ID()).c_str());

		worker->buyAndEatFood();
		worker->changeState(GoToDepotAndCollectBricks::instance());
	} else {
		fprintf(stderr, "Something went wrong...\n");
	}
}

void GoEat::exit(ConstructionWorker *worker) {
	fprintf(stdout, "%s: No longer hungry... Time to leave the snackbar.\n", GetNameOfEntity(worker->ID()).c_str());
}

// END GO_EAT
