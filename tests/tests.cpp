#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

TEST(TestAllocateMemory, TestAllocation) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 1);
EXPECT_EQ(data_of_arr.size, 0);

free(data_of_arr.array);
}

TEST(TestArray, CheckValues) {
data_t data = {7, 1234567, "Name"};
data_of_array_t data_of_arr = {&data, 1, 1};

EXPECT_EQ(data_of_arr.array->code, data.code);
EXPECT_EQ(data_of_arr.array->phone, data.phone);
EXPECT_STREQ(data_of_arr.array->name, data.name);
}

TEST(TestPush, ChackValues1) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_t temp_data = {8, 7654321, "NewName"};
push(&data_of_arr, temp_data);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 1);
EXPECT_EQ(data_of_arr.size, 1);

EXPECT_EQ(data_of_arr.array[0].code, temp_data.code);
EXPECT_EQ(data_of_arr.array[0].phone, temp_data.phone);
EXPECT_STREQ(data_of_arr.array[0].name, temp_data.name);

free(data_of_arr.array);
}

TEST(TestPush, ChackValues2) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_t temp_data1 = {8, 7654321, "FirstName"};
push(&data_of_arr, temp_data1);

data_t temp_data2 = {7, 1234567, "SecondName"};
push(&data_of_arr, temp_data2);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 2);
EXPECT_EQ(data_of_arr.size, 2);

EXPECT_EQ(data_of_arr.array[0].code, temp_data1.code);
EXPECT_EQ(data_of_arr.array[0].phone, temp_data1.phone);
EXPECT_STREQ(data_of_arr.array[0].name, temp_data1.name);

EXPECT_EQ(data_of_arr.array[1].code, temp_data2.code);
EXPECT_EQ(data_of_arr.array[1].phone, temp_data2.phone);
EXPECT_STREQ(data_of_arr.array[1].name, temp_data2.name);

free(data_of_arr.array);
}

TEST(TestPush, ChackValues3) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_t temp_data1 = {8, 7654321, "FirstName"};
push(&data_of_arr, temp_data1);

data_t temp_data2 = {7, 1234567, "SecondName"};
push(&data_of_arr, temp_data2);

data_t temp_data3 = {6, 1357924, "ThirdName"};
push(&data_of_arr, temp_data3);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 4);
EXPECT_EQ(data_of_arr.size, 3);

EXPECT_EQ(data_of_arr.array[0].code, temp_data1.code);
EXPECT_EQ(data_of_arr.array[0].phone, temp_data1.phone);
EXPECT_STREQ(data_of_arr.array[0].name, temp_data1.name);

EXPECT_EQ(data_of_arr.array[1].code, temp_data2.code);
EXPECT_EQ(data_of_arr.array[1].phone, temp_data2.phone);
EXPECT_STREQ(data_of_arr.array[1].name, temp_data2.name);

EXPECT_EQ(data_of_arr.array[2].code, temp_data3.code);
EXPECT_EQ(data_of_arr.array[2].phone, temp_data3.phone);
EXPECT_STREQ(data_of_arr.array[2].name, temp_data3.name);

free(data_of_arr.array);
}

TEST(TestResize, Resize1) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_of_arr.array = resize(&data_of_arr);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 2);

free(data_of_arr.array);
}

TEST(TestResize, Resize2) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_of_arr.array = resize(&data_of_arr);
data_of_arr.array = resize(&data_of_arr);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 4);

free(data_of_arr.array);
}

TEST(TestSorting, SortTwoStrucures) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_t temp_data1 = {8, 7654321, "FirstName"};
push(&data_of_arr, temp_data1);

data_t temp_data2 = {7, 1234567, "SecondName"};
push(&data_of_arr, temp_data2);

sorting_data(&data_of_arr);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 2);
EXPECT_EQ(data_of_arr.size, 2);

EXPECT_EQ(data_of_arr.array[0].code, temp_data2.code);
EXPECT_EQ(data_of_arr.array[0].phone, temp_data2.phone);
EXPECT_STREQ(data_of_arr.array[0].name, temp_data2.name);

EXPECT_EQ(data_of_arr.array[1].code, temp_data1.code);
EXPECT_EQ(data_of_arr.array[1].phone, temp_data1.phone);
EXPECT_STREQ(data_of_arr.array[1].name, temp_data1.name);

free(data_of_arr.array);
}

TEST(TestSorting, SortFiveStrucures) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_t temp_data1 = {8, 7654321, "FirstName"};
push(&data_of_arr, temp_data1);

data_t temp_data2 = {7, 1234567, "SecondName"};
push(&data_of_arr, temp_data2);

data_t temp_data3 = {4, 4235234, "ThirdName"};
push(&data_of_arr, temp_data3);

data_t temp_data4 = {7, 9374626, "FourthName"};
push(&data_of_arr, temp_data4);

data_t temp_data5 = {3, 26374853, "FifthName"};
push(&data_of_arr, temp_data5);

sorting_data(&data_of_arr);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 8);
EXPECT_EQ(data_of_arr.size, 5);

EXPECT_EQ(data_of_arr.array[0].code, temp_data5.code);
EXPECT_EQ(data_of_arr.array[0].phone, temp_data5.phone);
EXPECT_STREQ(data_of_arr.array[0].name, temp_data5.name);

EXPECT_EQ(data_of_arr.array[1].code, temp_data3.code);
EXPECT_EQ(data_of_arr.array[1].phone, temp_data3.phone);
EXPECT_STREQ(data_of_arr.array[1].name, temp_data3.name);

EXPECT_EQ(data_of_arr.array[2].code, temp_data2.code);
EXPECT_EQ(data_of_arr.array[2].phone, temp_data2.phone);
EXPECT_STREQ(data_of_arr.array[2].name, temp_data2.name);

EXPECT_EQ(data_of_arr.array[3].code, temp_data4.code);
EXPECT_EQ(data_of_arr.array[3].phone, temp_data4.phone);
EXPECT_STREQ(data_of_arr.array[3].name, temp_data4.name);

EXPECT_EQ(data_of_arr.array[4].code, temp_data1.code);
EXPECT_EQ(data_of_arr.array[4].phone, temp_data1.phone);
EXPECT_STREQ(data_of_arr.array[4].name, temp_data1.name);

free(data_of_arr.array);
}

TEST(TestSorting, SortStrucuresWithEqualCode) {
data_of_array_t data_of_arr;
int status = allocate_memory_for_array_of_structure(&data_of_arr);

data_t temp_data1 = {7, 7654321, "FirstName"};
push(&data_of_arr, temp_data1);

data_t temp_data2 = {7, 1234567, "SecondName"};
push(&data_of_arr, temp_data2);

data_t temp_data3 = {7, 4235234, "ThirdName"};
push(&data_of_arr, temp_data3);

sorting_data(&data_of_arr);

EXPECT_EQ(status, 0);
EXPECT_EQ(data_of_arr.capacity, 4);
EXPECT_EQ(data_of_arr.size, 3);

EXPECT_EQ(data_of_arr.array[0].code, temp_data1.code);
EXPECT_EQ(data_of_arr.array[0].phone, temp_data1.phone);
EXPECT_STREQ(data_of_arr.array[0].name, temp_data1.name);

EXPECT_EQ(data_of_arr.array[1].code, temp_data2.code);
EXPECT_EQ(data_of_arr.array[1].phone, temp_data2.phone);
EXPECT_STREQ(data_of_arr.array[1].name, temp_data2.name);

EXPECT_EQ(data_of_arr.array[2].code, temp_data3.code);
EXPECT_EQ(data_of_arr.array[2].phone, temp_data3.phone);
EXPECT_STREQ(data_of_arr.array[2].name, temp_data3.name);

free(data_of_arr.array);
}

TEST(TestPrint, Print) {
data_t data = {7, 1234567, "Name"};
data_of_array_t data_of_arr = {&data, 1, 2};

int expectation = printf("%d %d %s\n",
                         data_of_arr.array->code, data_of_arr.array->phone, data_of_arr.array->name);

EXPECT_EQ(expectation, 15);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
