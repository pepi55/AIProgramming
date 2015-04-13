#include <stdio.h>
#include "states/troll/TrollState.hpp"
#include "entities/Troll.hpp"

int arrayLength(int array[]);

int main(void) {
	Troll bigGuy;
	bigGuy.changeState(new TrollStatePeaceful());

	for (int i = 0; i < 50; ++i) {
		bigGuy.update();
	}

	return 0;
}

int arrayLength(int array[]) {
	int result = 0;

	while (array[result]) {
		if (array[result + 1]) {
			result++;
		} else {
			break;
		}
	}

	return result;
}
