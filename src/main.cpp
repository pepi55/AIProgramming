#include <stdio.h>

#include "states/troll/TrollState.hpp"
#include "entities/troll/Troll.hpp"
#include "enums/EntityNames.hpp"

//std::string getEntityName (int name);

int main(void) {
	Troll bigGuy(EDGAR);

	for (int i = 0; i < 50; ++i) {
		bigGuy.update();
	}

	return 0;
}
