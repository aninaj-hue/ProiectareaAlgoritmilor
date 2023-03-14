
#ifndef CODE_SKELETON_LAB10_KNAPSACK_H
#define CODE_SKELETON_LAB10_KNAPSACK_H

struct oferta
{
    int id;
    int pret;
    int profit;
    int nr_actiuni;
};

struct a_matrix
{
    int no_rows;
    int no_cols;
    int *matrix;
};


float value_per_unit(struct oferta obj);
void generator_oferte(struct oferta *oferte, int no_oferte);
void print_oferte(struct oferta *oferte, int no_oferte);
void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value);
void dynamic_programming_capital_discrete(struct oferta *oferte, int no_oferte, int capital_capacity);
void print_matrix(struct a_matrix matrix);

#endif //CODE_SKELETON_LAB10_KNAPSACK_H
