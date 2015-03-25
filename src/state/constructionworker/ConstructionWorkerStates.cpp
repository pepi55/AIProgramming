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
	worker->addToBricksCarried(1);
	worker->increaseFatigue();

	fprintf(stdout, "%s: Gathering some bricks.\n", GetNameOfEntity(worker->ID()).c_str());

	if (worker->handsFull()) {
		worker->changeState(VisitConstructionSiteAndDropBricks::instance());
	}

	if (worker->hungry()) {
		worker->changeState(GoEat::instance());
	}
}

// END GO_TO_DEPOT_AND_COLLECT_BRICKS
