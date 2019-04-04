// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include <HID.h>

#include "firmware.hpp"

Crow::Index const Rows[Crow::RowsCount]
    = {4, 3, 2, 0, 1};
Crow::Index const Cols[Crow::ColsCount]
    = {9, 10, 16, 14, 15, 8, 7, 18, 6, 5, 19, 20, 21};

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

void SendReport(Crow::Index const id,
                void const *const data,
                Crow::Index const size) {
    HID().SendReport(id, data, size);
}

void SetLayer(Crow::Index const id) {
    if (id == 0) {
        TXLED0;
        RXLED0;
    } else if (id == 1) {
        TXLED0;
        RXLED1;
    } else {
        TXLED1;
        RXLED0;
    }
}

Crow::Firmware firmware{GetRow, SendReport, SetLayer};

void setup() {
    TXLED0;
    RXLED0;

    static HIDSubDescriptor customerNode(
        Crow::Reports::CustomerDescriptor,
        sizeof(Crow::Reports::CustomerDescriptor));
    HID().AppendDescriptor(&customerNode);

    static HIDSubDescriptor keyboardNode(
        Crow::Reports::KeyboardDescriptor,
        sizeof(Crow::Reports::KeyboardDescriptor));
    HID().AppendDescriptor(&keyboardNode);

    static HIDSubDescriptor pointerNode(Crow::Reports::PointerDescriptor,
                                        sizeof(Crow::Reports::PointerDescriptor));
    HID().AppendDescriptor(&pointerNode);

    for (Crow::Index i = 0; i < Crow::RowsCount; ++i) {
        pinMode(Rows[i], OUTPUT);
        digitalWrite(Rows[i], HIGH);
    }

    for (Crow::Index i = 0; i < Crow::ColsCount; ++i) {
        pinMode(Cols[i], INPUT_PULLUP);
    }
}

void loop() {
    firmware.loop();
}
