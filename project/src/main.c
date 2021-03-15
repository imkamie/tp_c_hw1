#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array_of_structure(&data_of_arr);
    if (status != 0) {
        free(data_of_arr.array);
        return 1;
    }

    data_t temp_data;

    do {
        printf("Введите 1, если хотите ввести данные.\nВведите 2, если хотите вывести их.\n");
        int choice = 0;
        if (scanf("%d", &choice) != 1) {
            perror("Ошибка: ");
        }

        switch (choice) {
            case 1:
                filling_structure(&temp_data);
                push(&data_of_arr, temp_data);
                break;
            case 2:
                if (data_of_arr.size == 0) {
                    printf("Данных нет.\n");
                    break;
                }
                sorting_data(&data_of_arr);
                print_data(&data_of_arr);
                break;
            default:
                printf("Некорректный ввод.\n");
                asking_for_continue();
                break;
        }
    } while (asking_for_continue() == 1);

    free(data_of_arr.array);

    return 0;
}
