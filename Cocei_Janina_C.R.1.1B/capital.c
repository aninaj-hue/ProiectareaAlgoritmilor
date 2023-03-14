#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "capital.h"

void generator_oferte(struct oferta *oferte, int no_oferte)
{
    int iterator;
    time_t t;

    srand((unsigned) time(&t));
    for(iterator = 0; iterator < no_oferte; iterator++)
    {
        oferte[iterator].id = iterator;
        oferte[iterator].pret= rand() % 1000 + 1;
        oferte[iterator].profit = rand() % 1000 + 1;
        oferte[iterator].nr_actiuni=rand()% 5 + 1;
    }
}

void print_oferte(struct oferta *oferte, int no_oferte)
{
    int iterator;

    printf("\n Oferte:");
    for (iterator = 0; iterator < no_oferte ; iterator++)
    {
        printf("\n id: %d nr_actiuni: %d pret: %d profit: %d",oferte[iterator].id, oferte[iterator].nr_actiuni, oferte[iterator].pret, oferte[iterator].profit);
    }
}

void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value)
{
    int position;
    if (column_index == 0)
    {
    }
    position = row_index * matrix.no_cols + column_index;
    *(matrix.matrix + position) = element_value;
}


int get_matrix_value(struct a_matrix matrix, int row_index, int column_index)
{
    int position;

    position = row_index * matrix.no_cols + column_index;
    return *(matrix.matrix + position);
}

void print_matrix(struct a_matrix matrix)
{
    int iterator_rows;
    int iterator_columns;

    printf("\n === Matrice=== \n");
    for(iterator_rows = 0; iterator_rows < matrix.no_rows; iterator_rows++)
    {
        for(iterator_columns = 0; iterator_columns < matrix.no_cols; iterator_columns++)
        {
            printf("%d ",matrix.matrix[iterator_rows * matrix.no_cols + iterator_columns]);
        }
        printf("\n");
    }
}

int get_max(int val1, int val2)
{
    if (val1 > val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

float value_per_unit(struct oferta obj){
    return obj.profit/ (obj.nr_actiuni * 1.0);
}

void dynamic_programming_capital_discrete(struct oferta *oferte, int no_oferte, int capital_capacity)
{
    struct a_matrix matrix;
    int capital_value;
    int actiuni_iterator;
    int weight_iterator;
    int value_current_size_without_current_obj;
    int value_remaining_size_wthout_current_obj;
    int value_current_size_plus_current_obj;
    int value_max;
    int knapsack_remaining_capacity;

    matrix.no_rows = no_oferte+ 1;
    matrix.no_cols = capital_capacity + 1;
    matrix.matrix = calloc((matrix.no_rows) * (matrix.no_cols), sizeof(int));

    for (actiuni_iterator = 0; actiuni_iterator <= no_oferte; actiuni_iterator++)
    {
        for (weight_iterator = 0; weight_iterator <= capital_capacity; weight_iterator++)
        {
            if (actiuni_iterator == 0 || weight_iterator == 0)
                set_matrix_value(matrix, actiuni_iterator, weight_iterator, 0);
            else if (oferte[actiuni_iterator - 1].pret * oferte[actiuni_iterator - 1].nr_actiuni <= weight_iterator)
            {
                int carry = get_max(
                                oferte[actiuni_iterator - 1].profit * oferte[actiuni_iterator - 1].nr_actiuni
                                + get_matrix_value(matrix, actiuni_iterator - 1, weight_iterator - oferte[actiuni_iterator - 1].pret * oferte[actiuni_iterator - 1].nr_actiuni),

                                get_matrix_value(matrix, actiuni_iterator - 1, weight_iterator));

                set_matrix_value(matrix, actiuni_iterator, weight_iterator, carry);
            }
            else
                set_matrix_value(matrix, actiuni_iterator, weight_iterator, get_matrix_value(matrix, actiuni_iterator - 1, weight_iterator));
        }
    }


    capital_value = get_matrix_value(matrix, matrix.no_rows - 1, matrix.no_cols - 1);
    print_matrix(matrix);
    free(matrix.matrix);

    printf("\n=== Profitul maxim este  %d ===", capital_value);
}
