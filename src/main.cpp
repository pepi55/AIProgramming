#include <stdio.h>

int main(void) {
	int stuff = 10;

	stuff ^= 22;

	fprintf(stdout, "%i\n", stuff);

	return 0;
}
