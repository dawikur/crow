// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_FIRMWARE_HPP_
#define FIRMWARE_FIRMWARE_HPP_

#include "executor.hpp"
#include "keymap.hpp"
#include "matrix.hpp"

namespace Crow {

class Firmware {
 public:
  using GetRowImpl = Row (*)(Index const);

  Firmware(GetRowImpl const             getRowImpl,
           Report::SendImpl const       sendReportImpl,
           Layer::SetCallbackImpl const setCallbackImpl)
    : getRow{getRowImpl}
    , matrix{}
    , execute{sendReportImpl, Crow::Layers, setCallbackImpl} {}

  void loop() {
    for (Crow::Index i = 0; i < matrix.rows(); ++i) {
      auto const row      = getRow(i);
      auto const prev_row = matrix[i];

      for (Crow::Index j = 0; j < matrix.cols(); ++j) {
        auto const bit      = row[j];
        auto const prev_bit = prev_row[j];

        if (bit != prev_bit) {
          execute({i, j, bit});
        }
      }
      matrix[i] = row;
    }

    execute();
  }

 private:
  GetRowImpl getRow;
  Matrix     matrix;
  Executor   execute;
};

}  // namespace Crow

#endif  // FIRMWARE_FIRMWARE_HPP_
