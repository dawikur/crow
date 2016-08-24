// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_EVENT_HPP_
#define FIRMWARE_EVENT_HPP_

#include "config.hpp"

namespace Crow {

struct Event;
struct CompressedEvent;

struct Event {
  inline CompressedEvent compress() const;

  Index const row;
  Index const col;
  bool const wasPressed;
};

struct CompressedEvent {
  inline Event expand() const;

  RawCompressEvent const raw;
};

CompressedEvent Event::compress() const {
  return {static_cast<RawCompressEvent>((((row << ColsBits) | col) << 1) |
                                        static_cast<Index>(wasPressed))};
}

Event CompressedEvent::expand() const {
  return {static_cast<Index>(raw >> (ColsBits + 1)),
          static_cast<Index>((raw >> 1) & ((1 << ColsBits) - 1)),
          static_cast<bool>(raw & 0x01)};
}

}  // namespace Crow

#endif  // FIRMWARE_EVENT_HPP_
