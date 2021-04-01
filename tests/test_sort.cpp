#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

#define SUCCESS_CODE 0

TEST(TestSort, SortTwoStrucures) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_t temp_data1 = {8, 7654321, "FirstName"};
    int push_status1 = push(&data_of_arr, temp_data1);

    data_t temp_data2 = {7, 1234567, "SecondName"};
    int push_status2 = push(&data_of_arr, temp_data2);

    sort_data(&data_of_arr);

    EXPECT_EQ(status, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.capacity, 2);
    EXPECT_EQ(data_of_arr.size, 2);

    EXPECT_EQ(push_status2, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[0].code, temp_data2.code);
    EXPECT_EQ(data_of_arr.array[0].phone, temp_data2.phone);
    EXPECT_STREQ(data_of_arr.array[0].name, temp_data2.name);

    EXPECT_EQ(push_status1, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[1].code, temp_data1.code);
    EXPECT_EQ(data_of_arr.array[1].phone, temp_data1.phone);
    EXPECT_STREQ(data_of_arr.array[1].name, temp_data1.name);

    free(data_of_arr.array);
}

TEST(TestSort, SortFiveStrucures) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_t temp_data1 = {8, 7654321, "FirstName"};
    int push_status1 = push(&data_of_arr, temp_data1);

    data_t temp_data2 = {7, 1234567, "SecondName"};
    int push_status2 = push(&data_of_arr, temp_data2);

    data_t temp_data3 = {4, 4235234, "ThirdName"};
    int push_status3 = push(&data_of_arr, temp_data3);

    data_t temp_data4 = {7, 9374626, "FourthName"};
    int push_status4 = push(&data_of_arr, temp_data4);

    data_t temp_data5 = {3, 26374853, "FifthName"};
    int push_status5 = push(&data_of_arr, temp_data5);

    sort_data(&data_of_arr);

    EXPECT_EQ(status, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.capacity, 8);
    EXPECT_EQ(data_of_arr.size, 5);

    EXPECT_EQ(push_status5, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[0].code, temp_data5.code);
    EXPECT_EQ(data_of_arr.array[0].phone, temp_data5.phone);
    EXPECT_STREQ(data_of_arr.array[0].name, temp_data5.name);

    EXPECT_EQ(push_status3, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[1].code, temp_data3.code);
    EXPECT_EQ(data_of_arr.array[1].phone, temp_data3.phone);
    EXPECT_STREQ(data_of_arr.array[1].name, temp_data3.name);

    EXPECT_EQ(push_status2, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[2].code, temp_data2.code);
    EXPECT_EQ(data_of_arr.array[2].phone, temp_data2.phone);
    EXPECT_STREQ(data_of_arr.array[2].name, temp_data2.name);

    EXPECT_EQ(push_status4, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[3].code, temp_data4.code);
    EXPECT_EQ(data_of_arr.array[3].phone, temp_data4.phone);
    EXPECT_STREQ(data_of_arr.array[3].name, temp_data4.name);

    EXPECT_EQ(push_status1, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[4].code, temp_data1.code);
    EXPECT_EQ(data_of_arr.array[4].phone, temp_data1.phone);
    EXPECT_STREQ(data_of_arr.array[4].name, temp_data1.name);

    free(data_of_arr.array);
}

TEST(TestSort, SortStrucuresWithEqualCode) {
    data_of_array_t data_of_arr;
    int status = allocate_memory_for_array(&data_of_arr);

    data_t temp_data1 = {7, 7654321, "FirstName"};
    int push_status1 = push(&data_of_arr, temp_data1);

    data_t temp_data2 = {7, 1234567, "SecondName"};
    int push_status2 = push(&data_of_arr, temp_data2);

    data_t temp_data3 = {7, 4235234, "ThirdName"};
    int push_status3 = push(&data_of_arr, temp_data3);

    sort_data(&data_of_arr);

    EXPECT_EQ(status, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.capacity, 4);
    EXPECT_EQ(data_of_arr.size, 3);

    EXPECT_EQ(push_status1, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[0].code, temp_data1.code);
    EXPECT_EQ(data_of_arr.array[0].phone, temp_data1.phone);
    EXPECT_STREQ(data_of_arr.array[0].name, temp_data1.name);

    EXPECT_EQ(push_status2, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[1].code, temp_data2.code);
    EXPECT_EQ(data_of_arr.array[1].phone, temp_data2.phone);
    EXPECT_STREQ(data_of_arr.array[1].name, temp_data2.name);

    EXPECT_EQ(push_status3, SUCCESS_CODE);
    EXPECT_EQ(data_of_arr.array[2].code, temp_data3.code);
    EXPECT_EQ(data_of_arr.array[2].phone, temp_data3.phone);
    EXPECT_STREQ(data_of_arr.array[2].name, temp_data3.name);

    free(data_of_arr.array);
}
