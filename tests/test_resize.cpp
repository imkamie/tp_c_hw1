#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

#define SUCCESS_CODE 0

TEST(TestResize, Resize1) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_of_arr.array = resize(&data_of_arr);

    EXPECT_EQ(status, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.capacity, 2);

    free(data_of_arr.array);
}

TEST(TestResize, Resize2) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_of_arr.array = resize(&data_of_arr);
    data_of_arr.array = resize(&data_of_arr);

    EXPECT_EQ(status, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.capacity, 4);

    free(data_of_arr.array);
}
