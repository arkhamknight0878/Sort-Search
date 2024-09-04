#include "Functions.h"

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct List_Node
{
	int data;
	List_Node* next;
	List_Node* prev;
};

struct DEnd_List
{
	size_t size;
	List_Node* top;
	List_Node* back;
};

struct Hash_Node
{
	int key;
	int value;
	struct Hash_Node* next;
};

struct Hash_Map
{
	size_t capasity;
	size_t amount_of_elements;
	Hash_Node** buckets;
};

struct Tree_Node
{
	int data;
	struct Tree_Node* left;
	struct Tree_Node* right;
};

// ------------------------------ Array Functions ------------------------------

int* Rand_Arr_Create(size_t length_)
{
	int* arr = (int*)calloc(length_, sizeof(int));
	if (!arr)
		return NULL;

	srand(time(NULL));

	for (size_t i = 0; i < length_; ++i)
		arr[i] = rand() % 100;

	return arr;
}

void Arr_Output(int* arr_, size_t length_)
{
	for (size_t i = 0; i < length_; ++i)
		printf("%d ", arr_[i]);

	printf("\n");
}

// ------------------------------- Sort Functions ------------------------------

void Swap(int* element1_, int* element2_)
{
	int temp = *element1_;
	*element1_ = *element2_;
	*element2_ = temp;
}

void Place_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	for (size_t i = 1; i < length_; ++i)
	{
		for (size_t j = i; j <= i && arr_[j - 1] > arr_[j]; --j)
			Swap(&arr_[j - 1], &arr_[j]);
	}
}

int Shell_Gap(size_t length_, size_t current_index_)
{
	return (int)((double)length_ / (pow(2, floor(log2(length_) - current_index_))));
}

void Shell_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	for (int shell_index = length_ - 1; shell_index >= 0; --shell_index)
	{
		int gap = Shell_Gap(length_, shell_index);

		for (size_t i = 0; i < length_; ++i)
		{
			for (size_t j = i; j <= i && arr_[j - gap] > arr_[j]; j -= gap)
				Swap(&arr_[j - 1], &arr_[j]);
		}
	}
}

void Hibbard_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	size_t hibbard_length = floor(log(length_) / log(2));

	int* hibbard_sequence = (int*)calloc(hibbard_length, sizeof(int));
	if (!hibbard_sequence)
		return;

	for (size_t i = 0; i < hibbard_length; ++i)
		hibbard_sequence[i] = pow(2, i + 1) - 1;

	for (int hibbard_index = hibbard_length - 1; hibbard_index >= 0; --hibbard_index)
	{
		int gap = hibbard_sequence[hibbard_index];

		for (size_t i = 0; i < length_; ++i)
		{
			for (size_t j = i; j <= i && arr_[j - gap] > arr_[j]; j -= gap)
				Swap(&arr_[j - 1], &arr_[j]);
		}
	}
}

int* Pratt_Sequence(size_t length_)
{
	int* pratt_sequence = (int*)calloc(length_, sizeof(int));
	if (!pratt_sequence)
		return NULL;

	size_t index = 0;
	size_t pow3 = 1;

	while (pow3 <= length_)
	{
		size_t pow2 = pow3;

		while (pow2 <= length_)
		{
			pratt_sequence[index] = pow2;
			++index;
			pow2 *= 2;
		}

		pow3 *= 3;
	}

	Hibbard_Sort(pratt_sequence, length_);

	return pratt_sequence;
}

void Pratt_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	int* pratt_sequence = Pratt_Sequence(length_);

	for (int pratt_index = length_ - 1; pratt_index >= 0; --pratt_index)
	{
		int gap = pratt_sequence[pratt_index];

		for (size_t i = 0; i < length_; ++i)
		{
			for (size_t j = i; j <= i && arr_[j - gap] > arr_[j]; j -= gap)
				Swap(&arr_[j - 1], &arr_[j]);
		}
	}
}

void Bubble_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	bool is_swapped;

	for (size_t i = 0; i < length_; ++i)
	{
		is_swapped = false;

		for (size_t j = 0; j < length_ - i - 1; ++j)
		{
			if (arr_[j + 1] < arr_[j])
			{
				Swap(&arr_[j + 1], &arr_[j]);
				is_swapped = true;
			}
		}

		if (is_swapped == false)
			return;
	}
}

void Cocktail_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	size_t start = 0;
	size_t end = length_ - 1;
	bool is_swapped = true;

	while (is_swapped == true)
	{
		is_swapped = false;

		for (size_t i = 0; i < end; ++i)
		{
			if (arr_[i + 1] < arr_[i])
			{
				Swap(&arr_[i + 1], &arr_[i]);
				is_swapped = true;
			}
		}

		if (is_swapped == false)
			return;

		--end;
		is_swapped = false;

		for (int i = end; i >= start; --i)
		{
			if (i < 0)
				break;

			if (arr_[i - 1] > arr_[i])
			{
				Swap(&arr_[i - 1], &arr_[i]);
				is_swapped = true;
			}
		}

		++start;
	}
}

int Partion(int* arr_, size_t left_, size_t right_)
{
	size_t pivot = arr_[right_];
	size_t index = left_;

	for (size_t i = left_; i < right_; ++i)
	{
		if (arr_[i] < pivot)
		{
			Swap(&arr_[i], &arr_[index]);
			++index;
		}
	}

	Swap(&arr_[index], &arr_[right_]);

	return index;
}

void Quick_Sort(int* arr_, size_t left_, size_t right_)
{
	if (!arr_)
		return;

	if (left_ < right_)
	{
		int partion = Partion(arr_, left_, right_);

		Quick_Sort(arr_, left_, partion - 1);
		Quick_Sort(arr_, partion + 1, right_);
	}
}

int Comb_Gap(size_t current_gap_)
{
	current_gap_ = (current_gap_ * 10) / 15;

	if (current_gap_ < 1)
		return 1;

	return current_gap_;
}

void Comb_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	int gap = 0;
	bool is_swapped = true;

	while (gap != 1 || is_swapped == true)
	{
		is_swapped = false;
		gap = Comb_Gap(gap);

		for (size_t i = 0; i < length_ - gap; ++i)
		{
			if (arr_[i + gap] < arr_[i])
			{
				Swap(&arr_[i + gap], &arr_[i]);
				is_swapped = true;
			}
		}
	}
}

void Selection_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	size_t min_index = 0;

	for (size_t i = 0; i < length_; ++i)
	{
		min_index = i;

		for (size_t j = i + 1; j < length_; ++j)
		{
			if (arr_[min_index] > arr_[j])
				min_index = j;
		}

		if (min_index != i)
			Swap(&arr_[min_index], &arr_[i]);
	}
}

void Merge(int* arr_, size_t left_, size_t middle_, size_t right_)
{
	size_t len1 = middle_ - left_ + 1;
	size_t len2 = right_ - middle_;

	int* left_subarr = (int*)calloc(len1, sizeof(int));
	if (!left_subarr)
		return;

	int* right_subarr = (int*)calloc(len2, sizeof(int));
	if (!right_subarr)
	{
		free(left_subarr);
		return;
	}

	for (size_t i = 0; i < len1; ++i)
		left_subarr[i] = arr_[left_ + i];

	for (size_t i = 0; i < len2; ++i)
		right_subarr[i] = arr_[middle_ + 1 + i];

	size_t i = 0;
	size_t j = 0;

	while (i < len1 && j < len2)
	{
		if (left_subarr[i] < right_subarr[j])
		{
			arr_[left_] = left_subarr[i];
			++i;
		}
		else
		{
			arr_[left_] = right_subarr[j];
			++j;
		}

		++left_;
	}

	while (i < len1)
	{
		arr_[left_] = left_subarr[i];
		++i;
		++left_;
	}

	while (j < len2)
	{
		arr_[left_] = right_subarr[j];
		++j;
		++left_;
	}

	free(left_subarr);
	free(right_subarr);
}

void Merge_Sort_Recur(int* arr_, size_t left_, size_t right_)
{
	if (left_ < right_)
	{
		size_t middle = left_ + (right_ - left_) / 2;

		Merge_Sort_Recur(arr_, left_, middle);
		Merge_Sort_Recur(arr_, middle + 1, right_);

		Merge(arr_, left_, middle, right_);
	}
}

void Merge_Sort(int* arr_, size_t length_)
{
	if (!arr_)
		return;

	Merge_Sort_Recur(arr_, 0, length_ - 1);
}

// ------------------------------ Search Functions -----------------------------

int Linear_Search_Unsorted(int* arr_, size_t length_, int key_)
{
	if (!arr_)
		return -1;

	for (size_t i = 0; i < length_; ++i)
	{
		if (arr_[i] == key_)
			return i;
	}

	return -1;
}

int Linear_Search_Sorted(int* arr_, int key_)
{
	if (!arr_)
		return - 1;

	size_t i = 0;

	for (; arr_[i] < key_; ++i);

	if (arr_[i] == key_)
		return i;
	else
		return -1;

	return 0;
}

int Binary_Search(int* arr_, size_t length_, int key_)
{
	if (!arr_)
		return -1;

	size_t left = 0;
	size_t right = length_ - 1;
	size_t middle = 0;

	while (left < right)
	{
		middle = (left + right) / 2;

		if (key_ < arr_[middle])
			right = middle - 1;
		else if (key_ > arr_[middle])
			left = middle + 1;
		else
			return middle;
	}

	return -1;
}

int Interpolation_Search(int* arr_, size_t length_, int key_)
{
	if (!arr_)
		return -1;

	size_t left = 0;
	size_t right = length_ - 1;
	size_t middle = 0;

	while (left < right)
	{
		middle = left + ((double)(right - left) / (arr_[right] - arr_[left]) * (key_ - arr_[left]));

		if (key_ < arr_[middle])
			right = middle - 1;
		else if (key_ > arr_[middle])
			left = middle + 1;
		else
			return middle;
	}

	return -1;
}

int Fibonacci_Search(int* arr_, size_t length_, int key_)
{
	if (!arr_)
		return -1;

	size_t fibM1 = 1;
	size_t fibM2 = 0;
	size_t fib = fibM1 + fibM2;

	while (fib < length_)
	{
		fibM2 = fibM1;
		fibM1 = fib;
		fib = fibM1 + fibM2;
	}

	int offset = -1;

	while (fib > 1)
	{
		int index = ((offset + fibM2) <= (length_ - 1)) ? (offset + fibM2) : (length_ - 1);

		if (key_ > arr_[index])
		{
			fib = fibM1;
			fibM1 = fibM2;
			fibM2 = fib - fibM1;
			offset = index;
		}
		else if (key_ < arr_[index])
		{
			fibM1 = fibM1 - fibM2;
			fib = fibM2;
			fibM2 = fib - fibM1;
		}
		else
			return index;
	}

	if (fibM2 == key_ && arr_[offset + 1] == key_)
		return (offset + 1);

	return -1;
}

// ------------------------------- List Functions ------------------------------

DEnd_List* List_Create()
{
	DEnd_List* list = (DEnd_List*)malloc(sizeof(DEnd_List));
	if (!list)
		return NULL;

	list->size = 0;
	list->top = NULL;
	list->back = NULL;

	return list;
}

void Push_Front(DEnd_List* list_, int data_)
{
	if (!list_)
		return;

	List_Node* new_node = (List_Node*)malloc(sizeof(List_Node));
	if (!new_node)
		return;

	new_node->data = data_;
	new_node->next = NULL;

	if (list_->size == 0)
	{
		new_node->prev = NULL;
		list_->back = new_node;
	}
	else
	{
		new_node->prev = list_->top;
		list_->top->next = new_node;
	}

	list_->top = new_node;
	++list_->size;
}

void Push_Back(DEnd_List* list_, int data_)
{
	if (!list_)
		return;

	List_Node* new_node = (List_Node*)malloc(sizeof(List_Node));
	if (!new_node)
		return;

	new_node->data = data_;
	new_node->prev = NULL;

	if (list_->size == 0)
	{
		new_node->next = NULL;
		list_->top = new_node;
	}
	else
	{
		new_node->next = list_->back;
		list_->back->prev = new_node;
	}

	list_->back = new_node;
	++list_->size;
}

int Pop_Front(DEnd_List* list_)
{
	if (!list_ || list_->size == 0)
		return;

	List_Node* temp = list_->top;
	int data_cpy = list_->top->data;

	if (list_->top->prev == NULL)
	{
		list_->top = NULL;
		list_->back = NULL;
	}
	else
	{
		list_->top = list_->top->prev;
		list_->top->next = NULL;
	}

	free(temp);
	--list_->size;

	return data_cpy;
}

int Pop_Back(DEnd_List* list_)
{
	if (!list_ || list_->size == 0)
		return;

	List_Node* temp = list_->back;
	int data_cpy = list_->back->data;

	if (list_->back->next == NULL)
	{
		list_->back = NULL;
		list_->top = NULL;
	}
	else
	{
		list_->back = list_->back->next;
		list_->back->prev = NULL;
	}

	return data_cpy;
}

List_Node* List_Search(DEnd_List* list_, int key_)
{
	if (!list_ || list_->size == 0)
		return NULL;

	List_Node* current_node = list_->top;

	while (current_node)
	{
		if (current_node->data == key_)
			return current_node;

		current_node = current_node->prev;
	}
}

bool List_Erase(DEnd_List* list_, int key_)
{
	if (!list_ || list_->size == 0)
		return false;

	List_Node* target = List_Search(list_, key_);
	if (target == NULL)
		return false;

	if (list_->size == 1)
		Pop_Front(list_);

	if (target->next == NULL)
		Pop_Front(list_);
	else if (target->prev == NULL)
		Pop_Back(list_);
	else
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}

	free(target);
	--list_->size;

	return true;
}

bool List_Insert(DEnd_List* list_, int prev_node_data_, int data_)
{
	if (!list_ || list_->size == 0)
		return false;

	List_Node* prev_node = List_Search(list_, prev_node_data_);
	if (!prev_node)
		return false;

	if (prev_node->next == NULL)
		Push_Front(list_, data_);
	else
	{
		List_Node* new_node = (List_Node*)malloc(sizeof(List_Node));
		if (!new_node)
			return false;

		new_node->data = data_;
		new_node->next = prev_node->next;
		new_node->prev = prev_node;

		prev_node->next->prev = new_node;
		prev_node->next = new_node;
	}

	return true;
}

void List_Output(DEnd_List* list_)
{
	if (!list_)
		return;

	List_Node* current_node = list_->back;

	while (current_node)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}

	printf("\n");
}

// ------------------------------- Hash Functions ------------------------------

Hash_Map* Set_Hash_Map()
{
	Hash_Map* hash_map = (Hash_Map*)malloc(sizeof(Hash_Map));
	if (!hash_map)
		return NULL;

	hash_map->capasity = 10;
	hash_map->amount_of_elements = 0;
	hash_map->buckets = (Hash_Node**)calloc(hash_map->capasity, sizeof(Hash_Node));
	if (!hash_map->buckets)
	{
		free(hash_map);
		return NULL;
	}

	return hash_map;
}

Hash_Node* Set_Hash_Node(int key_, int value_)
{
	Hash_Node* new_node = (Hash_Node*)malloc(sizeof(Hash_Node));
	if (!new_node)
		return NULL;

	new_node->key = key_;
	new_node->value = value_;
	new_node->next = NULL;

	return new_node;
}

void Increase_Map_Capasity(Hash_Map* map_)
{
	if (!map_)
		return;

	Hash_Node** temp = (Hash_Node**)realloc(map_->buckets, map_->capasity + 10);
	if (!temp)
		return;

	map_->buckets = temp;
	map_->capasity += 10;
}

int Hash_Function(int key_)
{
	return (key_ / 7);
}

void Hash_El_Insert(Hash_Map* map_, int key_, int value_)
{
	if (!map_)
		return;

	if (map_->amount_of_elements + 1 > map_->capasity)
		Increase_Map_Capasity(map_);

	Hash_Node* new_node = Set_Hash_Node(key_, value_);

	int bucket_index = Hash_Function(key_);

	if (map_->buckets[bucket_index] != NULL)
		new_node->next = map_->buckets[bucket_index];

	map_->buckets[bucket_index] = new_node;
}

bool Hash_El_Erase(Hash_Map* map_, int key_)
{
	if (!map_)
		return;

	int bucket_index = Hash_Function(key_);

	Hash_Node* current_node = map_->buckets[bucket_index];
	Hash_Node* prev_node = NULL;

	while (current_node != NULL)
	{
		if (current_node->key == key_)
		{
			if (current_node == map_->buckets[bucket_index])
				map_->buckets[bucket_index] = current_node->next;
			else
				prev_node->next = current_node->next;

			free(current_node);
			--map_->amount_of_elements;

			return true;
		}

		prev_node = current_node;
		current_node = current_node->next;
	}

	return false;
}

Hash_Node* Hash_El_Search(Hash_Map* map_, int key_)
{
	if (!map_)
		return NULL;

	int bucket_index = Hash_Function(key_);

	Hash_Node* currnet_node = map_->buckets[bucket_index];

	while (currnet_node != NULL)
	{
		if (currnet_node->key == key_)
			return currnet_node;

		currnet_node = currnet_node->next;
	}

	return NULL;
}

void Hash_Output(Hash_Map* map_)
{
	if (!map_)
		return;

	for (size_t i = 0; i < map_->capasity; ++i)
	{
		Hash_Node* current_node = map_->buckets[i];

		printf("%2Iu. ", i);

		if (current_node == NULL)
		{
			printf("--\n");
			continue;
		}
		else
		{
			printf("%d ", current_node->value);

			while (current_node->next != NULL)
			{
				current_node = current_node->next;
				printf("--> %d ", current_node->value);
			}
		}

		printf("\n");
	}
}

void OpenAdr_Insert(Hash_Map* map_, int key_, int value_)
{
	if (!map_)
		return;

	if (map_->amount_of_elements + 1 > map_->capasity)
		Increase_Map_Capasity(map_);

	Hash_Node* new_node = Set_Hash_Node(key_, value_);

	int index = Hash_Function(key_);

	while (map_->buckets[index] != NULL)
		index = (index + 1) % map_->capasity;

	map_->buckets[index] = new_node;
	++map_->capasity;
} 

Tree_Node* Node_Create(int data_)
{
	Tree_Node* new_node = (Tree_Node*)malloc(sizeof(Tree_Node));
	if (!new_node)
		return NULL;

	new_node->data = data_;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void Node_Isert(Tree_Node** tree_, Tree_Node* node_)
{
	if (!(*tree_))
		*tree_ = node_;

	if (node_->data > (*tree_)->data)
		Node_Isert(&(*tree_)->right, node_);
	else if (node_->data <= (*tree_)->data)
		Node_Isert(&(*tree_)->left, node_);
}

Tree_Node* Node_Search(Tree_Node* tree_, int key_)
{
	if (!tree_)
		return NULL;

	if (key_ > tree_->data)
		return Node_Search(tree_->right, key_);
	else if (key_ < tree_->data)
		return Node_Search(tree_->left, key_);
	else
		return tree_;
}

