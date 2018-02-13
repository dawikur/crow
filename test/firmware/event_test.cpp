// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "event.hpp"

#include "gtest/gtest.h"

TEST(event_test, event_initialization_works) {
  Crow::Event const event{4, 7, true};

  ASSERT_EQ(4, event.row);
  ASSERT_EQ(7, event.col);
  ASSERT_TRUE(event.wasPressed);
}

TEST(event_test, event_expand_gives_same_event_as_before_compression) {
  Crow::Event const event{5, 13, true};

  auto const compressed = event.compress();
  auto const expanded = compressed.expand();

  ASSERT_EQ(event.row, expanded.row);
  ASSERT_EQ(event.col, expanded.col);
  ASSERT_EQ(event.wasPressed, expanded.wasPressed);
}

