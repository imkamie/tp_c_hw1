#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "utils.h"

#define INITIAL_SIZE 0
#define ENTER_DATA 1
#define PRINT_DATA 2

int main() {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);
    if (status) {
        free(data_of_arr.array);
        return ENOMEM;
    }

    data_t temp_data;

    do {
        printf("Введите 1, если хотите ввести данные.\nВведите 2, если хотите вывести их.\n");
        int choice = 0;
        if (scanf("%d", &choice) != 1) {
            perror("Ошибка: ");
        }

        switch (choice) {
            case ENTER_DATA:
                filling_structure(&temp_data);
                push(&data_of_arr, temp_data);
                break;
            case PRINT_DATA:
                if (data_of_arr.size == INITIAL_SIZE) {
                    printf("Данных нет.\n");
                    break;
                }
                sort_data(&data_of_arr);
                print_data(&data_of_arr);
                break;
            default:
                printf("Некорректный ввод.\n");
                asking_for_continue();
                break;
        }
    } while (asking_for_continue());

    free(data_of_arr.array);

    return 0;
}
