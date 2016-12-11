// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "report_pointer.hpp"

#include "gtest/gtest.h"

TEST(pointer_test, by_default_report_is_not_modified) {
  Crow::Reports::Pointer report;

  ASSERT_FALSE(report);
}

TEST(pointer_test, report_will_be_set_when_clicking_button) {
  Crow::Reports::Pointer report;

  report.action('B' ^ 'L', true);

  ASSERT_TRUE(report);
}

TEST(pointer_test, commit_unsets_button_action) {
  Crow::Reports::Pointer report;

  report.action('B' ^ 'M', true);
  report.commit();

  ASSERT_FALSE(report);
}

TEST(pointer_test, releasing_button_sets_report) {
  Crow::Reports::Pointer report;

  report.action('B' ^ 'R', true);
  report.commit();
  report.action('B' ^ 'R', false);

  ASSERT_TRUE(report);
}

TEST(pointer_test, clicking_two_button_will_set_both_of_them) {
  Crow::Reports::Pointer report;

  report.action('B' ^ 'L', true);
  report.action('B' ^ 'M', true);

  int8_t raw[4] = {0x5, 0, 0, 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 4));
}

TEST(pointer_test, releasing_one_button_releasis_only_this_one) {
  Crow::Reports::Pointer report;

  report.action('B' ^ 'L', true);
  report.action('B' ^ 'R', true);
  report.action('B' ^ 'L', false);

  int8_t raw[4] = {0x2, 0, 0, 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 4));
}

TEST(pointer_test, moving__will_set_report) {
  Crow::Reports::Pointer report;

  report.action('+' ^ 'x', true);

  ASSERT_TRUE(report);
}

TEST(pointer_test, commiting_will_not_unset_moving_report) {
  Crow::Reports::Pointer report;

  report.action('-' ^ 'x', true);
  report.commit();

  ASSERT_TRUE(report);
}

TEST(pointer_test, stopping_and_commiting_movement_will_unset_report) {
  Crow::Reports::Pointer report;

  report.action('-' ^ 'x', true);
  report.commit();
  report.action('-' ^ 'x', false);
  report.commit();

  ASSERT_FALSE(report);
}

TEST(pointer_test, speed_will_increase_slowly_in_first_few_commits) {
  Crow::Reports::Pointer report;

  {
    report.action('+' ^ 'x', true);
    report.action('-' ^ 'y', true);

    int8_t raw[4] = {0, 5, -5, 0};
    ASSERT_EQ(0, memcmp(raw, report.data(), 4));
  }

  for (int8_t i = 5; i < 10; ++i) {
    int8_t raw[4] = {0, i, (int8_t)-i, 0};
    ASSERT_EQ(0, memcmp(raw, report.data(), 4));

    report.commit();
  }
}

TEST(pointer_test, speed_will_increase_faster_in_later_few_commits) {
  Crow::Reports::Pointer report;

  {
    report.action('+' ^ 'x', true);
    report.action('-' ^ 'y', true);

    int8_t raw[4] = {0, 5, -5, 0};
    ASSERT_EQ(0, memcmp(raw, report.data(), 4));
  }

  for (int8_t i = 5; i < 10; ++i) {
    report.commit();
  }

  for (int8_t i = 10; i < 30; i += 5) {
    int8_t raw[4] = {0, i, (int8_t)-i, 0};
    ASSERT_EQ(0, memcmp(raw, report.data(), 4));

    report.commit();
  }
}
