#include <stdio.h>

int arrayLength(int array[]);

int main(void) {
	fprintf(stdout, "size of char %i\n", sizeof(char));
	fprintf(stdout, "size of int %i\n", sizeof(int));
	fprintf(stdout, "size of short int %i\n", sizeof(short int));
	fprintf(stdout, "size of long int %i\n", sizeof(long int));
	fprintf(stdout, "size of float %i\n", sizeof(float));
	fprintf(stdout, "size of double %i\n", sizeof(double));
	fprintf(stdout, "size of wchar_t %i\n", sizeof(wchar_t));

	int array[] = {1, 2, 3};

	fprintf(stdout, "\narray len = %i\n", arrayLength(array));

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
