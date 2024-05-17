#include "Functions.h"

#include <stdio.h>
#include <stdlib.h>

int* Arr_Create(unsigned size_)
{
	while (size_ == 0)
	{
		printf("!!! Incorrect Input !!! Size must be GREATER than 0. Try Again:\n> ");
		scanf_s("%u", &size_);
	}

	int* arr = (int*)calloc(size_, sizeof(int));
	if (!arr)
		return NULL;

	for (unsigned i = 0; i < size_; ++i)
		arr[i] = i * 2;

	return arr;
}

void Arr_Print(int* arr_, unsigned size_)
{
	if (!arr_)
		return;

	for (unsigned i = 0; i < size_; ++i)
		printf("%2u.%u\n", i, arr_[i]);
}

int Search_Binary(int* arr_, unsigned size_, unsigned key_)
{
	if (!arr_)
		return -2;

	unsigned left = 0;
	unsigned right = size_;
	unsigned midle = 0;

	while (left < right)
	{
		midle = (left + right) / 2;

		if (arr_[midle] > key_)
			right = midle;
		else if (arr_[midle] < key_)
			left = midle + 1;
		else
			return midle;
	}

	return -1;
}
