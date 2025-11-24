#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int size, int arr[size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // если текущий > следующего, то делаем swap - меняем местами
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
// ...
    int array[N] = {6, -5, 3, 77, 4};
    // Сортируем по возрастанию
    bubble_sort(N, array);
// ...

//добавил какой-то комментарий

//и ещё комментарий