#pragma once

//typedef struct Hum Hum;

typedef struct Hum
{
    char name[20];
    unsigned int age;
}Hum;

typedef struct DB
{
    Hum** hums;
    unsigned size;
    unsigned capasity;
}DB;

DB* create(unsigned size_);

void add_Hum(Hum** hums_, int* size_, int* capacity_);

void print_hums(Hum* hums_, int size_);