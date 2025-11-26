// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// // это 14е
// int main(){
//     char *stroka = malloc(10000*sizeof(char));
//     if (stroka==NULL){printf("Память не выделена"); return -1;}
//     printf("Введите строку: "); fgets(stroka, 10000*sizeof(char), stdin);
//     char *na_raz = realloc(stroka, strlen(stroka)*sizeof(char));
//     if (na_raz!=NULL){stroka=na_raz;}
//     int summa = 0;
//     int number_in_stroka = 0;
//     for (int i=0; i<strlen(stroka)-1; i++){
//         if ('0'<=stroka[i] && stroka[i]<=57){
//             number_in_stroka = 1;
//             summa += stroka[i]-48;
//         }
//     }
//     if (number_in_stroka == 0){printf("Цифр в строке нет\n");}
//     else {printf("%d\n", summa);}
    
//     free(stroka); stroka=NULL;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_stroka(char *address_massiva, int sdvig_massiva, int operacia_massiva){    //получает адрес нулевого элемента, который записан в переменной stroka
    for (int i=0; i<strlen(address_massiva)-1; i++){
        if (operacia_massiva==0){       // шифрование
            if (65<=address_massiva[i] && address_massiva[i]<=90){      //A...Z
                if (address_massiva[i]+sdvig_massiva<=90){printf("%c", address_massiva[i]+sdvig_massiva);}
                else {printf("%c", address_massiva[i]+sdvig_massiva-26);}
            }
            else if (97<=address_massiva[i] && address_massiva[i]<=122){        //a...z
                if (address_massiva[i]+sdvig_massiva<=122){printf("%c", address_massiva[i]+sdvig_massiva);}
                else {printf("%c", address_massiva[i]+sdvig_massiva-26);}
            }
            else {printf("%c", address_massiva[i]);}
        }
        else {      // дешифрование
            if (65<=address_massiva[i] && address_massiva[i]<=90){      //A...Z
                if (address_massiva[i]-sdvig_massiva>=65){printf("%c", address_massiva[i]-sdvig_massiva);}
                else {printf("%c", address_massiva[i]-sdvig_massiva+26);}
            }
            else if (97<=address_massiva[i] && address_massiva[i]<=122){        //a...z
                if (address_massiva[i]-sdvig_massiva>=97){printf("%c", address_massiva[i]-sdvig_massiva);}
                else {printf("%c", address_massiva[i]-sdvig_massiva+26);}
            }
            else {printf("%c", address_massiva[i]);}
        }
    }
    printf("\n");
}

int main(){
    char *stroka = malloc(10000*sizeof(char));      //выделяю память для массива, заполняю его, отдаю лишнюю память
    if (stroka==NULL){printf("Память не выделена"); return -1;}
    printf("Введите строку: "); fgets(stroka, 10000*sizeof(char), stdin);
    char *na_raz = realloc(stroka, (strlen(stroka)-1)*sizeof(char));
    if (na_raz!=NULL){stroka = na_raz;}

    int sdvig; printf("Введите сдвиг: "); scanf("%d", &sdvig);      //ввод сдвига и операции
    while (-26>=sdvig || sdvig>=26){        //чтобы значение сдвига принадлежало промежутку [-25, 25]
        if (sdvig<0){sdvig+=26;}
        else {sdvig-=26;}
    }
    if (sdvig<0){sdvig = 26+sdvig;}        //чтобы значение сдвига не было отрицательным
    int operacia;
    while (1){
        printf("Введите операцию (0 - шифрование; 1 - дешифрование): "); scanf("%d", &operacia);
        if (operacia == 0 || operacia == 1){break;}
        else {printf("Введите 0 или 1!!!    ");}
    }

    new_stroka(stroka, sdvig, operacia);     //передаю адрес нулевого элемента динамического массива
    free(stroka); stroka = NULL;
}