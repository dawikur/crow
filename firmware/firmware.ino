// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "firmware.hpp"

Firmware firmware;

Crow::Row GetRow(Crow::Index const i) {
  return Crow::Row{0};
}
void SendReport(void const *const data, Crow::Index const size) {}

void setup() {
  firmware.setup(GetRow, SendReport);
}

void loop() {
  firmware.loop();
}
