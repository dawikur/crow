// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "HID.h"

#include "firmware.hpp"

Crow::Firmware firmware;

Crow::Index const Rows[Crow::RowsCount] = {15, 18, 19, 20, 21};
Crow::Inaax const Cols[Crow::ColsCount] = {14, 16, 10, 9, 8, 7, 6, 5, 4, 3, 2, 0, 1};

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

void SetLayerCallback(Crow::Index const id) {
  if (id == 0) {
    TXLED0;
    RXLED0;
  } else if (id == 1) {
    TXLED1;
    RXLED0;
  } else {
    TXLED0;
    RXLED1;
  }
}

void setup() {
  TXLED0;
  RXLED0;

  //static HIDSubDescriptor customerNode(
  //  Crow::Reports::CustomerDescriptor,
  //  sizeof(Crow::Reports::CustomerDescriptor));
  //HID().AppendDescriptor(&customerNode);

  static HIDSubDescriptor keyboardNode(
    Crow::Reports::KeyboardDescriptor,
    sizeof(Crow::Reports::KeyboardDescriptor));
  HID().AppendDescriptor(&keyboardNode);

  for (Crow::Index i = 0; i < Crow::RowsCount; ++i) {
    pinMode(Rows[i], OUTPUT);
    digitalWrite(Rows[i], HIGH);;
  }

  for (Crow::Index i = 0; i < Crow::ColsCount; ++i) {
    pinMode(Cols[i], INPUT_PULLUP);
  }

  firmware.setup(GetRow, SendReport, SetLayerCallback);
}

void loop() {
  firmware.loop();
}
