#include "misc/GenericUtils.hpp"
#include "entity/constructionworker/ConstructionWorker.hpp"
#include "enum/Locations.hpp"
#include "entity/EntityNames.hpp"

int main (void) {
	ConstructionWorker worker(ent_construction_worker_Bob);

	for (int i = 0; i < 20; ++i) {
		worker.update();
	}

	return 0;
}
