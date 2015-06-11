#include <stdio.h>

#include "states/troll/TrollState.hpp"
#include "entities/troll/Troll.hpp"
#include "enums/EntityNames.hpp"

int main(void) {
	Troll bigGuy(EDGAR);

	for (int i = 0; i < 50; ++i) {
		bigGuy.update();
	}

	return 0;
}
