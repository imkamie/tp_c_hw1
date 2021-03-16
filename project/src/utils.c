#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void print_data(const data_of_array_t* data_of_arr) {
    for (int i = 0; i < data_of_arr->size; i++) {
        printf("%d %d %s\n",
               data_of_arr->array[i].code, data_of_arr->array[i].phone, data_of_arr->array[i].name);
    }
}

data_t* resize(data_of_array_t* data_of_arr)  {
    int new_capacity = data_of_arr->capacity * 2;

    data_t* new_array = calloc(new_capacity, sizeof(data_t));
    if (!new_array) {
        free(new_array);
        return NULL;
    }
    memcpy(new_array, data_of_arr->array, sizeof(data_t) * data_of_arr->size);
    free(data_of_arr->array);

    data_of_arr->capacity = new_capacity;

    return new_array;
}

void push(data_of_array_t* data_of_arr, data_t data) {
    if (data_of_arr->size >= data_of_arr->capacity) {
        data_of_arr->array = resize(data_of_arr);
        if (!data_of_arr->array) {
            return;
        }
    }
    int current_size = data_of_arr->size;
    data_of_arr->array[current_size] = data;
    data_of_arr->size++;
}

void filling_structure(data_t* data) {
    printf("Введите код телефона:\n");
    if (scanf("%d", &data->code) != 1) {
        perror("Ошибка: ");
    }

    printf("Введите номер из 7 цифр:\n");
    char phone_string[8];
    if (scanf("%7s", phone_string) != 1) {
        perror("Ошибка: ");
    }
    data->phone = (int)strtol(phone_string, NULL, 10);

    scanf("%*[^\n]");
    scanf("%*c");
    printf("Введите имя:\n");
    if (scanf("%20s", data->name) != 1) {
        perror("Ошибка: ");
    }
}

void sort_data(data_of_array_t* data_of_arr) {
    for (int i = 1; i < data_of_arr->size; ++i) {
        data_t temp_data = data_of_arr->array[i];
        int temp_code = data_of_arr->array[i].code;
        int j = i - 1;
        for (; j >= 0 && temp_code < data_of_arr->array[j].code; --j) {
            data_of_arr->array[j + 1] = data_of_arr->array[j];
        }
        data_of_arr->array[j + 1] = temp_data;
    }
}

int allocate_memory_for_array(data_of_array_t* data_of_arr) {
    data_t* new_array = calloc(1, sizeof(data_t));
    if (!new_array) {
        free(new_array);
        return 1;
    }

    data_of_arr->array = new_array;
    data_of_arr->capacity = 1;
    data_of_arr->size = 0;

    return 0;
}

int asking_for_continue() {
    printf("Хотите продолжить? Введите 1, если да, и введите 2, если нет.\n");
    int answer = 0;
    if (scanf("%d", &answer) != 1) {
        perror("Ошибка: ");
    }

    if (answer == 1) {
        return 1;
    } else if (answer == 2) {
        return 0;
    } else {
        printf("Некорректный ввод.\n");
        asking_for_continue();
    }

    return 0;
}
