#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

TEST(TestAllocateMemory, TestAllocation) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    EXPECT_EQ(status, 0);
    EXPECT_EQ(data_of_arr.capacity, 1);
    EXPECT_EQ(data_of_arr.size, 0);

    free(data_of_arr.array);
}
