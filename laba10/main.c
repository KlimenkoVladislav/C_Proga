#include "head.h"

int main(){
    srand(time(0));

    int kol_parabol;

    while (1){
        scanf("%d", &kol_parabol);
        if (kol_parabol>0){
            break;
        }
        else{
            printf("Нужна хотя бы одна порабола\n");
        }
    }

    struct PARABOLA *address = zapolnenie(kol_parabol);
    otvet(address, kol_parabol);
}