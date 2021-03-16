#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

TEST(TestPrint, Print) {
    data_t data = {7, 1234567, "Name"};
    data_of_array_t data_of_arr = {&data, 1, 2};

    int expectation = printf("%d %d %s\n",
                             data_of_arr.array->code, data_of_arr.array->phone, data_of_arr.array->name);

    EXPECT_EQ(expectation, 15);
}
