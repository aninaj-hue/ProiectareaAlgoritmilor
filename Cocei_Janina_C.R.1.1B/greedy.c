#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "greedy.h"
#include "capital.h"

void sort_objects_by_value_per_unit(struct oferta *oferte, int no_oferte){
    int iterator_1;
    int iterator_2;
    int index_min;
    int aux_pret;
    int aux_id;
    int aux_profit;

    for(iterator_1 = 0; iterator_1 < no_oferte - 1; iterator_1++){
        index_min = iterator_1;
        for(iterator_2 = iterator_1 + 1; iterator_2 < no_oferte; iterator_2++){
            if ( value_per_unit(oferte[index_min]) < value_per_unit(oferte[iterator_2]) ){
                index_min = iterator_2;
            }
        }
        if (index_min != iterator_1){
            aux_pret = oferte[index_min].pret;
            aux_id = oferte[index_min].id;
            aux_profit = oferte[index_min].profit;
            oferte[index_min].pret = oferte[iterator_1].pret;
            oferte[index_min].id = oferte[iterator_1].id;
            oferte[index_min].profit = oferte[iterator_1].profit;
            oferte[iterator_1].pret = aux_pret;
            oferte[iterator_1].id = aux_id;
            oferte[iterator_1].profit = aux_profit;
        }
    }
}

void greedy_capital_discrete(struct oferta *oferte, int no_oferte, int capital_capacity){
    int iterator;
    int capital_current_capacity;
    float capital_value;
    capital_current_capacity = capital_capacity;
    capital_value = 0.0f;

    for(iterator = 0; iterator < no_oferte; ++iterator){
        float pret_unitate = value_per_unit(oferte[iterator]);
        if(pret_unitate <= capital_current_capacity){
            int unitati_cumparate = capital_current_capacity/pret_unitate;
            capital_current_capacity -= unitati_cumparate/pret_unitate;
            capital_value += unitati_cumparate*oferte[iterator].profit;
        }
    }

    printf("\nProfitul maxim este: %f", capital_value);
}
