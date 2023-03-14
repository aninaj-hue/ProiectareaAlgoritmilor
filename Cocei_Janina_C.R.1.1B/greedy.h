
#ifndef GREEDY_H_INCLUDED
#define GREEDY_H_INCLUDED
#include "capital.h"

void sort_objects_by_value_per_unit(struct oferta *oferte, int no_oferte);
void greedy_capital_discrete(struct oferta *oferte, int no_oferte, int capital_capacity);
#endif // GREEDY_H_INCLUDED
