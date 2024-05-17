#include "Functions.h"

#include <stdio.h>

int main()
{
	unsigned size = 0;
	unsigned key = 0;
	
	printf("Plese, Enter Array Size:\n> ");
	scanf_s("%u", &size);

	int* arr = Arr_Create(size);

	printf("-----------------------------------\n");
	printf("Generated Array:\n");
	Arr_Print(arr, size);
	printf("-----------------------------------\n");

	printf("Please, Enter Key:\n> ");
	scanf_s("%u", &key);

	printf("Result of Binary Search is: %d", Search_Binary(arr, size, key));

	return 0;
}
