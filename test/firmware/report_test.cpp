
#include "report.hpp"

#include "gtest.h"

TEST(report_test, size_will_return_8) {
  Crow::Report report;

  ASSERT_EQ(8, report.size());
}

TEST(report_test, initially_data_is_all_zero) {
  Crow::Report report;

  uint8_t raw[8] = {0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}


TEST(report_test, setting_key_will_success) {
  Crow::Report report;

  report.key('a', true);


  uint8_t raw[8] = {0, 0, 'a', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, setting_two_different_keys_will_success) {
  Crow::Report report;

  report.key('a', true);
  report.key('b', true);

  uint8_t raw[8] = {0, 0, 'a', 'b', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, setting_one_keys_two_times_will_set_it_only_once) {
  Crow::Report report;

  report.key('a', true);
  report.key('a', true);

  uint8_t raw[8] = {0, 0, 'a', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, one_key_can_be_released) {
  Crow::Report report;
  report.key('c', true);

  report.key('c', false);

  uint8_t raw[8] = {0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, first_of_two_keys_can_be_released) {
  Crow::Report report;
  report.key('d', true);
  report.key('e', true);

  report.key('d', false);

  uint8_t raw[8] = {0, 0, 0, 'e', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, second_of_two_keys_can_be_released) {
  Crow::Report report;
  report.key('d', true);
  report.key('e', true);

  report.key('e', false);

  uint8_t raw[8] = {0, 0, 'd', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, first_oftwo_key_can_be_replaced_by_another) {
  Crow::Report report;
  report.key('d', true);
  report.key('e', true);

  report.key('d', false);
  report.key('f', true);

  uint8_t raw[8] = {0, 0, 'f', 'e', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, second_oftwo_key_can_be_replaced_by_another) {
  Crow::Report report;
  report.key('d', true);
  report.key('e', true);

  report.key('e', false);
  report.key('f', true);

  uint8_t raw[8] = {0, 0, 'd', 'f', 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, one_modifier_can_be_set) {
  Crow::Report report;

  report.modifier(0x02, true);

  uint8_t raw[8] = {0x02, 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, two_modifiers_can_be_set) {
  Crow::Report report;

  report.modifier(0x02, true);
  report.modifier(0x08, true);

  uint8_t raw[8] = {0x0a, 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}

TEST(report_test, one_of_two_modifiers_can_be_set) {
  Crow::Report report;
  report.modifier(0x02, true);
  report.modifier(0x08, true);

  report.modifier(0x02, false);

  uint8_t raw[8] = {0x08, 0};
  ASSERT_EQ(0, memcmp(raw, report.data(), 8));
}
