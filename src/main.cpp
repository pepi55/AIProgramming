#include <stdio.h>

int arrayLength(int array[]);

int main(void) {
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
