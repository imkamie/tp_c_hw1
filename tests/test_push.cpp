#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

TEST(TestPush, CheckValues1) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_t temp_data = {8, 7654321, "NewName"};
    int push_status = push(&data_of_arr, temp_data);

    EXPECT_EQ(status, 0);
    EXPECT_EQ(data_of_arr.capacity, 1);
    EXPECT_EQ(data_of_arr.size, 1);

    EXPECT_EQ(push_status, 0);
    EXPECT_EQ(data_of_arr.array[0].code, temp_data.code);
    EXPECT_EQ(data_of_arr.array[0].phone, temp_data.phone);
    EXPECT_STREQ(data_of_arr.array[0].name, temp_data.name);

    free(data_of_arr.array);
}

TEST(TestPush, CheckValues2) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_t temp_data1 = {8, 7654321, "FirstName"};
    int push_status1 = push(&data_of_arr, temp_data1);

    data_t temp_data2 = {7, 1234567, "SecondName"};
    int push_status2 = push(&data_of_arr, temp_data2);

    EXPECT_EQ(status, 0);
    EXPECT_EQ(data_of_arr.capacity, 2);
    EXPECT_EQ(data_of_arr.size, 2);

    EXPECT_EQ(push_status1, 0);
    EXPECT_EQ(data_of_arr.array[0].code, temp_data1.code);
    EXPECT_EQ(data_of_arr.array[0].phone, temp_data1.phone);
    EXPECT_STREQ(data_of_arr.array[0].name, temp_data1.name);

    EXPECT_EQ(push_status2, 0);
    EXPECT_EQ(data_of_arr.array[1].code, temp_data2.code);
    EXPECT_EQ(data_of_arr.array[1].phone, temp_data2.phone);
    EXPECT_STREQ(data_of_arr.array[1].name, temp_data2.name);

    free(data_of_arr.array);
}

TEST(TestPush, CheckValues3) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_t temp_data1 = {8, 7654321, "FirstName"};
    int push_status1 = push(&data_of_arr, temp_data1);

    data_t temp_data2 = {7, 1234567, "SecondName"};
    int push_status2 = push(&data_of_arr, temp_data2);

    data_t temp_data3 = {6, 1357924, "ThirdName"};
    int push_status3 = push(&data_of_arr, temp_data3);

    EXPECT_EQ(status, 0);
    EXPECT_EQ(data_of_arr.capacity, 4);
    EXPECT_EQ(data_of_arr.size, 3);

    EXPECT_EQ(push_status1, 0);
    EXPECT_EQ(data_of_arr.array[0].code, temp_data1.code);
    EXPECT_EQ(data_of_arr.array[0].phone, temp_data1.phone);
    EXPECT_STREQ(data_of_arr.array[0].name, temp_data1.name);

    EXPECT_EQ(push_status2, 0);
    EXPECT_EQ(data_of_arr.array[1].code, temp_data2.code);
    EXPECT_EQ(data_of_arr.array[1].phone, temp_data2.phone);
    EXPECT_STREQ(data_of_arr.array[1].name, temp_data2.name);

    EXPECT_EQ(push_status3, 0);
    EXPECT_EQ(data_of_arr.array[2].code, temp_data3.code);
    EXPECT_EQ(data_of_arr.array[2].phone, temp_data3.phone);
    EXPECT_STREQ(data_of_arr.array[2].name, temp_data3.name);

    free(data_of_arr.array);
}
