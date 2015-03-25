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

		worker->ChangeLocation(DEPOT);
	}
}
