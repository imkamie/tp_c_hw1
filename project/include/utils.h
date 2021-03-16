#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#define NAME_MAX_LENGTH 20

typedef struct data {
    int code;
    int phone;
    char name[NAME_MAX_LENGTH];
} data_t;

typedef struct data_of_arr {
    data_t* array;
    int size;
    int capacity;
} data_of_array_t;

data_t* resize(data_of_array_t* arr);
void push(data_of_array_t* arr, data_t data);
void sort_data(data_of_array_t* data_of_arr);
int allocate_memory_for_array(data_of_array_t *data_of_arr);
void print_data(const data_of_array_t * data_of_arr);
void print_elem_of_arr(const data_t* elem);
void filling_structure(data_t* data);
int asking_for_continue();

#endif  // PROJECT_INCLUDE_UTILS_H_
