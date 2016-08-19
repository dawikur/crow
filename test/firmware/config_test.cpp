
#include "config.hpp"

#include "gtest.h"

template <class Type> struct id;

TEST(config_test, data_type_is_big_for_whole_row) {
  ASSERT_LE(Crow::ColsCount, sizeof(Crow::RawRow) * 8);
}

TEST(config_test, data_type_is_big_for_whole_event) {
  ASSERT_LE(Crow::ColsBits + Crow::RowsBits + 1,
            sizeof(Crow::RawCompressEvent) * 8);
}

TEST(config_test, all_numbers_of_cols_will_fit_in_ColsBit_number) {
  ASSERT_LE(Crow::ColsCount, pow(2, Crow::ColsBits) - 1);
}

TEST(config_test, all_numbers_of_rows_will_fit_in_RowsBit_number) {
  ASSERT_LE(Crow::RowsCount, pow(2, Crow::RowsBits) - 1);
}
