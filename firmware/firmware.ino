// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "HID.h"

#include "firmware.hpp"

Crow::Firmware firmware;

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
  static HIDSubDescriptor node(Crow::Reports::KeyboardDescriptor,
                               sizeof(Crow::Reports::KeyboardDescriptor));
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
