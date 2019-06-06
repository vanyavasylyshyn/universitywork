#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>

struct BILET {
    std::string punkt;
    int number_of_avia;
    std::string pib[3];
    int data[3];
    BILET *next;
};

BILET * create_BILET(BILET* beg, BILET * bilet);
BILET * find(BILET * pv, const std::string punkt, BILET ** prev);
BILET * delete_BILET(BILET * beg);
void find(BILET * pv, int number);
void find(BILET * pv, const int data[3]);
void find_BILET(BILET * beg);
void get_all_BILETS(BILET * beg);
BILET * read_BILET();