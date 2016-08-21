// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_FIRMWARE_HPP_
#define CROW_FIRMWARE_HPP_

#include "executor.hpp"
#include "matrix.hpp"
#include "keymap.hpp"

namespace Crow {

class Firmware {
 public:
  void setup(Matrix::GetRowImpl getRowImpl,
             System::SendReportImpl sendReportImpl) {
    matrix.setup(getRowImpl);
    execute.setup(sendReportImpl, Crow::Layers);
  }

  void loop() {
    for (Crow::Index i = 0; i < matrix.rows(); ++i) {
      auto const row = matrix(i);
      auto const prev_row = matrix[i];

      for (Crow::Index j = 0; j < matrix.cols(); ++j) {
        auto const bit = row[j];
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
  Matrix matrix;
  Executor execute;
};

}  // namespace Crow

#endif  // CROW_FIRMWARE_HPP_
