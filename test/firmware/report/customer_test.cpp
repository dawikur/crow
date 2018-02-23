// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "report_customer.hpp"

#include "gtest/gtest.h"

TEST(customer_test, by_default_report_is_not_modified) {
  Crow::Reports::Customer report;

  ASSERT_FALSE(report);
}

