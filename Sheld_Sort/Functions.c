
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int* arr_, size_t left_, size_t midle_, size_t right_)
{
	size_t len1 = midle_ - left_ + 1;
	size_t len2 = right_ - midle_;

	int* left = (int*)calloc(len1, sizeof(int));
	if (!left)
		return;

	int* right = (int*)calloc(len2, sizeof(int));
	if (!right)
		return;

	for (size_t i = 0; i < len1; ++i)
		left[i] = arr_[left_ + i];

	for (size_t i = 0; i < len2; ++i)
		right[i] = arr_[midle_ + 1 + i];

	size_t i = 0;
	size_t j = 0;

	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr_[left_] = left[i];
			++i;
		}
		else
		{
			arr_[left_] = right[j];
			++j;
		}

		++left_;
	}

	while (i < len1)
	{
		arr_[left_] = left[i];
		++i;
		++left_;
	}

	while (j < len2)
	{
		arr_[left_] = right[j];
		++j;
		++left_;
	}

	free(left);
	free(right);
}

void Recursive(int* arr_, size_t left_, size_t right_)
{
	if (left_ < right_)
	{
		size_t midle = left_ + (right_ - left_) / 2;

		Recursive(arr_, left_, midle);
		Recursive(arr_, midle + 1, right_);

		Merge(arr_, left_, midle, right_);
	}
}

void Merge_Sort(int* arr_, size_t size_)
{
	if (!arr_)
		return;

	Recursive(arr_, 0, size_ - 1);
}

int* Hibbard_Sequence(size_t size_)
{
	size_t sequence_length = floor(log(size_ + 1) / log(2));

	int* hibbard_sequence = (int*)calloc(sequence_length, sizeof(int));
	if (!hibbard_sequence)
		return NULL;

	for (size_t i = 0; i < sequence_length; ++i)
		hibbard_sequence[i] = pow(2, i + 1) - 1;

	return hibbard_sequence;
}

void Sheld_Hib(int* arr_, size_t size_)
{
	if (!arr_)
		return;

	size_t sequence_length = floor(log(size_ + 1) / log(2));

	int* hibbard_sequence = (int*)calloc(sequence_length, sizeof(int));
	if (!hibbard_sequence)
		return NULL;

	for (size_t i = 0; i < sequence_length; ++i)
		hibbard_sequence[i] = pow(2, i + 1) - 1;

	for (int hibb_index = (sequence_length - 1); hibb_index >= 0; --hibb_index)
	{
		int gap = hibbard_sequence[hibb_index];

		for (size_t i = gap; i < size_; ++i)
		{
			for (size_t j = i; j >= gap && arr_[j - gap] > arr_[j]; j -= gap)
			{
				int temp = arr_[j - gap];
				arr_[j - gap] = arr_[j];
				arr_[j] = temp;
			}
		}
	}
}

int* Pratt_Sequence(size_t size_)
{
	int* pratt_sequence = (int*)calloc(size_, sizeof(int));
	if (!pratt_sequence)
		return NULL;

	size_t i = 0;
	size_t pow3 = 1;

	while (pow3 <= size_)
	{
		size_t pow2 = pow3;

		while (pow2 <= size_)
		{
			pratt_sequence[i] = pow2;
			++i;

			pow2 *= 2;
		}

		pow3 *= 3;
	}

	return pratt_sequence;
}

void Sheld_Pratt(int* arr_, size_t size_)
{
	if (!arr_)
		return;

	int* pratt_sequence = Pratt_Sequence(size_);

	for (int pratt_index = size_ - 1; pratt_index >= 0; --pratt_index)
	{
		int gap = pratt_sequence[pratt_index];

		for (size_t i = gap; i < size_; ++i)
		{
			for (size_t j = i; j >= gap && arr_[j - gap] > arr_[j]; j -= gap)
			{
				int temp = arr_[j - gap];
				arr_[j - gap] = arr_[j];
				arr_[j] = temp;
			}
		}
	}
}