#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PARABOLA{
    int a;
    int b;
    int c;
};

struct abc_max_min{
    int a;
    int b;
    int c;
};

struct PARABOLA *zapolnenie(int kol_parabol);
void otvet(struct PARABOLA *address, int kol_parabol);