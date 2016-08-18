// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_EVENT_HPP_
#define CROW_EVENT_HPP_

#include "config.hpp"

namespace Crow {

struct Event;
struct CompressedEvent;

struct Event {
  CompressedEvent compress() const;

  Index const row;
  Index const col;
  bool const wasPressed;

};

struct CompressedEvent {
  Event expand() const;

  Data const data;
};

CompressedEvent Event::compress() {
  return { row << 8 | col << 1 | wasPressed ? 1 : 0; };
}

Event CompressedEvent::expand() {
  return { data >> 8, (data >> 1) & 0x7, data & 0x01 }
  }
}

}  // namespace Crow

#endif  // CROW_EVENT_HPP_
