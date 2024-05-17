#include "Functions.h"

#include <stdio.h>
#include <stdlib.h>

unsigned int* Arr_Create(unsigned int size_)
{
	while (size_ == 0)
	{
		printf("!!! Incorrect Input !!! Size must be GREATER than 0. Try Again:\n> ");
		scanf_s("%u", &size_);
	}

	unsigned int* arr = (unsigned int*)calloc(size_, sizeof(unsigned int));
	if (!arr)
		return NULL;

	for (unsigned int i = 0; i < size_; ++i)
		arr[i] = i * 2;

	return arr;
}

void Arr_Print(unsigned int* arr_, unsigned int size_)
{
	if (!arr_)
		return;

	for (unsigned int i = 0; i < size_; ++i)
		printf("%2u.%u\n", i, arr_[i]);
}

int Search_Binary(unsigned int* arr_, unsigned int size_, unsigned int key_)
{
	if (!arr_)
		return -2;

	unsigned int left = 0;
	unsigned int right = size_;
	unsigned int midle = 0;

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
