// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "types.hpp"

#include <cmath>

#include "gtest/gtest.h"

template <class Type> struct id;

TEST(types_test, data_type_is_big_for_whole_row) {
  ASSERT_LE(Crow::ColsCount, sizeof(Crow::RawRow) * 8);
}

TEST(types_test, data_type_is_big_for_whole_compressed_event) {
  ASSERT_LE(Crow::ColsBits + Crow::RowsBits + 1,
            sizeof(Crow::RawCompressEvent) * 8);
}

TEST(types_test, all_numbers_of_cols_will_fit_in_ColsBit_number) {
  ASSERT_LE(Crow::ColsCount, std::pow(2, Crow::ColsBits) - 1);
}

TEST(types_test, all_numbers_of_rows_will_fit_in_RowsBit_number) {
  ASSERT_LE(Crow::RowsCount, std::pow(2, Crow::RowsBits) - 1);
}
