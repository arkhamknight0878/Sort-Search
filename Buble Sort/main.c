#include "Functions.h"

#include <stdio.h>

int main()
{
	unsigned int size = 0;

	printf("Plese, Enter Array Size:\n> ");
	scanf_s("%u", &size);

	unsigned char* arr = Rand_Arr_Create(size);

	printf("-----------------------------------\n");
	printf("Generated Array: ");
	Arr_Print(arr, size);
	printf("\n-----------------------------------\n");

	Sort_Buble(arr, size);

	printf("Sorted Array: ");
	Arr_Print(arr, size);
	printf("\n-----------------------------------\n");

	return 0;
}