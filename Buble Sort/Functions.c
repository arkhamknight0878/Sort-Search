#include "Functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int* Rand_Arr_Create(unsigned int size_)
{
	while (size_ == 0)
	{
		printf("!!! Incorrect Input !!! Size must be GREATER than 0. Try Again:\n> ");
		scanf_s("%u", &size_);
	}

	int* arr = (int*)calloc(size_, sizeof(int));
	if (!arr)
		return NULL;

	srand((unsigned)time(NULL));

	for (unsigned i = 0; i < size_; ++i)
		arr[i] = rand() % 100;

	return arr;
}

void Arr_Print(int* arr_, unsigned int size_)
{
	if (!arr_)
		return;

	for (unsigned i = 0; i < size_; ++i)
		printf("%d ", arr_[i]);
}

void Sort_Buble(int* arr_, unsigned int size_)
{
	if (!arr_)
		return;

	for (unsigned i = 0; i < size_; ++i)
	{
		bool flag = true;

		for (unsigned j = 0; j < (size_ - (i + 1)); ++j)
		{
			if (arr_[j] > arr_[j + 1])
			{
				int save = arr_[j + 1];
				arr_[j + 1] = arr_[j];
				arr_[j] = save;

				flag = false;
			}
		}

		if (flag)
			break;
	}
}
