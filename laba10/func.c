#include "head.h"

struct PARABOLA *zapolnenie(int kol_parabol){
    struct PARABOLA *parabola = malloc(kol_parabol*sizeof(struct PARABOLA));
    if (parabola==NULL){printf("Память не выделена\n"); return 0;}
    for (int i=0; i<kol_parabol; i++){
        parabola[i].a = rand()%100-50;
        parabola[i].b = rand()%100-50;
        parabola[i].c = rand()%100-50;
    }
    for (int i=0; i<kol_parabol; i++){
        printf("%d, %d, %d\n", parabola[i].a, parabola[i].b, parabola[i].c);
    }
    return parabola;
}

void otvet(struct PARABOLA *parabola, int kol_parabol){
    int kol_parabol_with_min = 0;
    int max_min = -100;

    struct abc_max_min min_parabola;
    struct abc_max_min *address_for_min_parabola = &min_parabola;
    for (int i=0; i<kol_parabol; i++){
        if (parabola[i].a < 0){
            kol_parabol_with_min++;
            float x0 = -((float)(parabola[i].b)) / (2.0f * (float)(parabola[i].a));
            printf("%.3f\n", x0);
            if (max_min<x0){
                max_min = x0;
                address_for_min_parabola->a = parabola[i].a;
                address_for_min_parabola->b = parabola[i].b;
                address_for_min_parabola->c = parabola[i].c;
            }
        }
    }
    printf("Количество порабол с ветвями вниз: %d\n", kol_parabol_with_min);
    printf("Парабола с наибольшим минимумом: y = (%d)*x^2 + (%d)*x + (%d)\n", address_for_min_parabola->a, address_for_min_parabola->b, address_for_min_parabola->c);

    address_for_min_parabola = NULL; 
}