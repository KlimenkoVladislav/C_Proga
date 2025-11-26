#include <stdio.h>
#include <math.h>

float determinat(int N, int matrica[N][N+1], int flag){
    float det = 0;
    int d_matrica[N][N+1];      //создадим новый массив, потому что как оказалось эти действия изменяют массив в мэйне. НАДО СПРОСИТЬ ПОЧЕМУ ТАК ПРОИСХОДИТ
    for (int i=0; i<N; i++){
        for (int j=0; j<N+1; j++){
            d_matrica[i][j] = matrica[i][j];
        }
        if (flag>=0){d_matrica[i][flag] = matrica[i][N];}       //замена столбца № flag на столбец В, чтобы решалось по Крамеру
    }

    if (N>2){       //пытаюсь уменьшить размер матрицы до 2х2
        for (int x=0; x<N; x++){        //исключаем последнюю строку (потому что так проще в плане написания дальнейших циклов) и столбец № х
            int smaller_matrica[N-1][N];        //N столбцов, а не N-1 необходимо для того, чтобы можно было бахнуть рекурсию. по факту мы не смотрим на последний столбец
            for (int i=0; i<N-1; i++){      //для заполнения уменьшенного массива размером N-1 на N-1
                for (int j=0; j<N; j++){
                    if (j<x){smaller_matrica[i][j] = d_matrica[i][j];}
                    else if (j>=x){smaller_matrica[i][j] = d_matrica[i][j+1];}   //по каким-то мат.правилам мы исключаем столбец № х, когда уменьшаем размер матрицы в Крамере
                }
            }
            int znak = (x % 2 == 0)? 1 : -1;
            det+=znak*d_matrica[N-1][x]*determinat(N-1, smaller_matrica, -1);  //элемент последней строки столбца № х со своим знаком умножаем на уменьшенную матрицу
        }
    }
    else if (N==2){det=d_matrica[0][0]*d_matrica[1][1]-d_matrica[0][1]*d_matrica[1][0];}     //определитель для матрицы 2х2
    return det;
}

int main(){
    int n; printf("Введите размер матрицы NxN: "); scanf("%d", &n);
    int matrica[n][n+1];
    for (int i = 0; i<n; i++){      //задаём расширенную матрицу
        for (int j = 0; j<n+1; j++){
            int k; 
            if (j!=n){printf("Коэффициент перед x%d = ", j+1);}
            else {printf("Чему равна эта строка: ");}
            scanf("%d", &k); 
            matrica[i][j] = k;
        }
    }
    printf("\n\n\n");
    for (int i = 0; i<n; i++){      //красиво выводим систему уравнений
        for (int j = 0; j<n; j++){
            printf("x%d*(%d) ", j+1, matrica[i][j]);
            if (j<n-1){printf("+ ");}
            else {printf("= ");}
        }
        printf("%d\n", matrica[i][n]);
    }
    printf("\n\n\n");
    if (determinat(n, matrica, -1)!=0){
        for (int i=0; i<n; i++){
            printf("x%d = %.2f    ", i+1, determinat(n, matrica, i)/determinat(n, matrica, -1));
        }
    }
    else{printf("Нет единственного решения");}
    printf("\n");
}

// #include <stdio.h>

// int check_rows(int sudoku[9][9]){
//     for (int i=0; i<9; i++){        //берём строчку
//         for (int j=0; j<9; j++){
//             int kol=0;
//             for (int z=0; z<9; z++){
//                 if (sudoku[i][j]==sudoku[i][z]){kol++;}
//             }
//             if (kol!=1){return 0;}
//         }
//     }
//     return 1;
// }

// int check_columns(int sudoku[9][9]){
//     for (int j; j<9; j++){      //берём столбец
//         for (int i=0; i<9; i++){
//             int kol=0;
//             for (int z=0; z<9; z++){
//                 if (sudoku[i][j]==sudoku[z][j]){kol++;}
//             }
//             if (kol!=1){return 0;}
//         }
//     }
//     return 1;
// }

// int check_squares(int sudoku[9][9]){
//     for (int h_sudoku=0; h_sudoku<9; h_sudoku+=3){      //берём квадрат
//         for (int l_sudoku=0; l_sudoku<9; l_sudoku+=3){
//             int kvadrat[9];                 //представляем кварат в виде последовательности цифр
//             int x_kvadrat=0;
//             for (int i=l_sudoku; i<l_sudoku+3; i++){        //проходимся по квадрату
//                 for (int j=h_sudoku; j<h_sudoku+3; j++){
//                     kvadrat[x_kvadrat] = sudoku[i][j];      //добавляем значение квадрата в последовательность цифр квадрата
//                     x_kvadrat++;
//                 }
//             }
//             //тут последовательность квадрата полностью заполнена
//             for (int i=0; i<9; i++){
//                 int kol=0;
//                 for (int j=0; j<9; j++){
//                     if (kvadrat[i]==kvadrat[j]){kol++;}
//                 }
//                 if (kol!=1){return 0;}
//             }
//         }
//     }
//     return 1;
// }

// void is_valid_sudoku(int sudoku[9][9]){
//     if (check_rows(sudoku) + check_columns(sudoku) + check_squares(sudoku) ==3){printf("Это решение!\n");}
//     else {printf("Это не решение :( \n");}
// }

// int main(){
//     int sudoku[9][9] = {
//         {5, 3, 4, 6, 7, 8, 9, 1, 2},
//         {6, 7, 2, 1, 9, 5, 3, 4, 8},
//         {1, 9, 8, 3, 4, 2, 5, 6, 7},
//         {8, 5, 9, 7, 6, 1, 4, 2, 3},
//         {4, 2, 6, 8, 5, 3, 7, 9, 1},
//         {7, 3, 1, 9, 2, 4, 8, 5, 6},
//         {9, 6, 1, 5, 3, 7, 2, 8, 4},
//         {2, 8, 7, 4, 1, 9, 6, 3, 5},
//         {3, 4, 5, 2, 8, 6, 1, 7, 9}
//     };
//     is_valid_sudoku(sudoku);
// }