#include <stdio.h>
#include <stdlib.h>
#include "capital.h"
#include "greedy.h"

int main()
{
    struct oferta *oferte;
    int no_oferte;
    int capital_capacity;

    printf("Introduceti capitalul disponibil: ");
    scanf("%d",&capital_capacity);

    printf("Introduceti numarul de oferte: ");
    scanf("%d",&no_oferte);

    oferte = malloc(no_oferte * sizeof(struct oferta));
    generator_oferte(oferte, no_oferte);

    printf("\n=== Random oferte ===");
    print_oferte(oferte, no_oferte);


    char optiune;
    printf("\nAlegeti algoritmul preferat: [D]Programare Dinamica\t [G] Greedy\n");
    fflush(stdin);
    scanf("%c",&optiune);

    if(optiune == 'D'){
        printf("\n ===Metoda dinamica===\n" );
        dynamic_programming_capital_discrete(oferte, no_oferte, capital_capacity);
    }
    else if(optiune == 'G'){
        printf("\n ===Metoda prin greedy===\n" );
        greedy_capital_discrete(oferte, no_oferte,  capital_capacity);
    }

}
