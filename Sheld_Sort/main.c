#include "Functions.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 0;
	int capacity = 1;

	DB* db = create(5);

	add_Hum(&db->hums, &db->size, &db->capasity);
	add_Hum(&db->hums, &db->size, &db->capasity);
	add_Hum(&db->hums, &db->size, &db->capasity);

	print_hums(db->hums, db->size);

	return 0;
}