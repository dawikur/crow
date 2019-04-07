// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_BASE_HPP_
#define FIRMWARE_REPORT_BASE_HPP_

#include "types.hpp"

namespace Crow {
namespace Reports {

template <Index Id, class RawReport>
class Base {
  public:
    Base() : raw{}, changed{false} {}

    virtual explicit operator bool() const { return changed; }

    void commit() { changed = false; }

    void clear() {
        for (uint8_t *ptr = (uint8_t*)(void*)&raw,
                     *end = ptr + sizeof (raw);
             ptr != end;
             ++ptr) {
            if (*ptr != 0) {
                *ptr = 0;
                markChanged();
            }
        }
    }

    static Index constexpr id() { return Id; }
    void const *data() const { return &raw; }
    Index       size() const { return sizeof(raw); }

  protected:
    void markChanged() { changed = true; }
  
    RawReport raw;
  
  private:
    bool changed;
};

}  // namespace Reports
}  // namespace Crow

#endif  // FIRMWARE_REPORT_CUSTOMER_HPP_
