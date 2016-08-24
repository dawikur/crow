// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "row.hpp"

#include "gtest/gtest.h"

TEST(row_test, by_default_row_is_zero) {
  Crow::Row const row;

  ASSERT_FALSE(row[0]);
  ASSERT_FALSE(row[1]);
  ASSERT_FALSE(row[2]);
  ASSERT_FALSE(row[3]);
  ASSERT_FALSE(row[4]);
}

TEST(row_test, returns_true_for_all_bits_set) {
  Crow::Row const row{31};

  ASSERT_TRUE(row[0]);
  ASSERT_TRUE(row[1]);
  ASSERT_TRUE(row[2]);
  ASSERT_TRUE(row[3]);
  ASSERT_TRUE(row[4]);
}

TEST(row_test, returns_true_or_false_depending_on_bit) {
  Crow::Row const row{77};

  ASSERT_TRUE(row[0]);
  ASSERT_FALSE(row[1]);
  ASSERT_TRUE(row[2]);
  ASSERT_TRUE(row[3]);
  ASSERT_FALSE(row[4]);
  ASSERT_FALSE(row[5]);
  ASSERT_TRUE(row[6]);
}
