#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

TEST(TestArray, CheckValues) {
data_t data = {7, 1234567, "Name"};
data_of_array_t data_of_arr = {&data, 1, 1};

ASSERT_EQ(data_of_arr.array->code, data.code);
ASSERT_EQ(data_of_arr.array->phone, data.phone);
ASSERT_STREQ(data_of_arr.array->name, data.name);
}
