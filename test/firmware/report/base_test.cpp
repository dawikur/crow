// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "report_base.hpp"

#include "gtest/gtest.h"

TEST(base_test, by_default_report_is_not_modified) {
    Crow::Reports::Base<1, int> report;

    ASSERT_FALSE(report);
}

TEST(base_test, initially_data_is_all_zero) {
    Crow::Reports::Base<1, int[2]> report;

    int raw[2] = {0};
    ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

