// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "HID.h"

#include "firmware.hpp"

Crow::Firmware firmware;

static uint8_t const _hidReportDescriptor[] PROGMEM = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)

    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)

    0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0xE7,                    //   LOGICAL_MAXIMUM (231)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0xE7,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
};

Crow::Index const Rows[Crow::RowsCount] = {15, 18, 19, 20, 21};
Crow::Index const Cols[Crow::ColsCount] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16};

Crow::Row GetRow(Crow::Index const i) {
  digitalWrite(Rows[i], LOW);
  delay(10);

  Crow::RawRow row = 0x00;
  for (Crow::Index i = 0; i < Crow::ColsCount; ++i) {
    row <<= 0x01;
    row |= (digitalRead(Cols[i]) ^ HIGH);
  }

  digitalWrite(Rows[i], HIGH);

  return Crow::Row{row};
}

void SendReport(Crow::Index const id, void const *const data, Crow::Index const size) {
  HID().SendReport(id, data, size);
}

void setup() {
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);

  for (int i = 0; i < Crow::RowsCount; ++i) {
    pinMode(Rows[i], OUTPUT);
    digitalWrite(Rows[i], HIGH);;
  }

  for (int i = 0; i < Crow::ColsCount; ++i) {
    pinMode(Cols[i], INPUT_PULLUP);
  }

  firmware.setup(GetRow, SendReport);
}

void loop() {
  firmware.loop();
}
