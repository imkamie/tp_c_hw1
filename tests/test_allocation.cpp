#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

#define SUCCESS_CODE 0

TEST(TestAllocateMemory, TestAllocation) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    EXPECT_EQ(status, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.capacity, 1);
    EXPECT_EQ(data_of_arr.size, 0);

    EXPECT_FALSE(data_of_arr.array == nullptr);

    EXPECT_EQ(data_of_arr.array->code, 0);
    EXPECT_EQ(data_of_arr.array->phone, 0);
    EXPECT_STREQ(data_of_arr.array->name, "");

    free(data_of_arr.array);
}
