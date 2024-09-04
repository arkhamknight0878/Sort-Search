#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct List_Node List_Node;

typedef struct DEnd_List DEnd_List;

typedef struct Hash_Node Hash_Node;

typedef struct Hash_Map Hash_Map;

typedef struct Tree_Node Tree_Node;

// ------------------------------ Array Functions ------------------------------

int* Rand_Arr_Create(size_t length_);

void Arr_Output(int* arr_, size_t length_);

// ------------------------------- Sort Functions ------------------------------

void Swap(int* element1_, int* element2_);

void Place_Sort(int* arr_, size_t length_);

int Shell_Gap(size_t length_, size_t current_index_);

void Shell_Sort(int* arr_, size_t length_);

void Hibbard_Sort(int* arr_, size_t length_);

int* Pratt_Sequence(size_t length_);

void Pratt_Sort(int* arr_, size_t length_);

void Bubble_Sort(int* arr_, size_t length_);

void Cocktail_Sort(int* arr_, size_t length_);

int Partion(int* arr_, size_t left_, size_t right_);

void Quick_Sort(int* arr_, size_t left_, size_t right_);

int Comb_Gap(size_t current_gap_);

void Comb_Sort(int* arr_, size_t length_);

void Selection_Sort(int* arr_, size_t length_);

void Merge(int* arr_, size_t left_, size_t middle_, size_t right_);

void Merge_Sort_Recur(int* arr_, size_t left_, size_t right_);

void Merge_Sort(int* arr_, size_t length_);

// ------------------------------ Search Functions -----------------------------

int Linear_Search_Unsorted(int* arr_, size_t length_, int key_);

int Linear_Search_Sorted(int* arr_, int key_);

int Binary_Search(int* arr_, size_t length_, int key_);

int Interpolation_Search(int* arr_, size_t length_, int key_);

int Fibonacci_Search(int* arr_, size_t length_, int key_);

// ------------------------------- List Functions ------------------------------

DEnd_List* List_Create();

void Push_Front(DEnd_List* list_, int data_);

void Push_Back(DEnd_List* list_, int data_);

int Pop_Front(DEnd_List* list_);

int Pop_Back(DEnd_List* list_);

List_Node* List_Search(DEnd_List* list_, int key_);

bool List_Erase(DEnd_List* list_, int key_);

bool List_Insert(DEnd_List* list_, int prev_node_data_, int data_);

void List_Output(DEnd_List* list_);

// ------------------------------- Hash Functions ------------------------------

Hash_Map* Set_Hash_Map();

Hash_Node* Set_Hash_Node(int key_, int value_);

void Increase_Map_Capasity(Hash_Map* map_);

int Hash_Function(int key_);

void Hash_El_Insert(Hash_Map* map_, int key_, int value_);

bool Hash_El_Erase(Hash_Map* map_, int key_);

Hash_Node* Hash_El_Search(Hash_Map* map_, int key_);

void Hash_Output(Hash_Map* map_);

void OpenAdr_Insert(Hash_Map* map_, int key_, int value_);

bool OpenAdr_Erase(Hash_Map* map_, int key_);

// ---------------------------- Binary Tree Functions ---------------------------

Tree_Node* Node_Create(int data_);

void Node_Isert(Tree_Node** tree_, Tree_Node* node_);

Tree_Node* Node_Search(Tree_Node* tree_, int key_);

bool Node_Erase(Tree_Node* tree_, int key_);