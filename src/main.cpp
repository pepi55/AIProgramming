#include <stdio.h>
#include <string>

#include "states/troll/TrollState.hpp"
#include "entities/troll/Troll.hpp"
#include "enums/EntityNames.hpp"

std::string getEntityName (int name);
int arrayLength (int array[]);

int main(void) {
	Troll bigGuy(EDGAR);

	for (int i = 0; i < 50; ++i) {
		bigGuy.update();
	}

	return 0;
}

std::string getEntityName (int name) {
	switch (name) {
		case EDGAR:
			return "Edgar";

		case HELLEN:
			return "Hellen";

		default:
			return "Unknown";
	}
}

int arrayLength(int array[]) {
	int result = 0;

	while (array[result + 1]) {
		result++;
	}

	return result;
}
