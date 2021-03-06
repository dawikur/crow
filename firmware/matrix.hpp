// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_MATRIX_HPP_
#define FIRMWARE_MATRIX_HPP_

#include "types.hpp"
#include "row.hpp"

namespace Crow {

class Matrix {
  public:
    Matrix()               = default;
    Matrix(Matrix const &) = delete;

    static Index rows() { return RowsCount; }
    static Index cols() { return ColsCount; }

    Row operator[](Index const i) const { return row[i]; }
    Row &operator[](Index const i) { return row[i]; }

  private:
    Row row[RowsCount];
};

}  // namespace Crow

#endif  // FIRMWARE_MATRIX_HPP_

