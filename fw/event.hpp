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

CompressedEvent Event::compress() const {
  return {static_cast<Data>(row << 8 | col << 1 | wasPressed ? 1 : 0)};
}

Event CompressedEvent::expand() const {
  return {static_cast<Index>(data >> 8),
          static_cast<Index>((data >> 1) & 0x7),
          static_cast<bool>(data & 0x01)};
}

}  // namespace Crow

#endif  // CROW_EVENT_HPP_
