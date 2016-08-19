// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_MATRIX_HPP_
#define CROW_MATRIX_HPP_

#include "config.hpp"
#include "row.hpp"

namespace Crow {

class Matrix_ {
 public:
  Matrix_() = default;
  Matrix_(Matrix_ const &) = delete;

  static Index rows() { return RowsCount; }
  static Index cols() { return ColsCount; }

  Row operator()(Index const i) { return Row{0}; }  // TODO: 2016-08-18

  Row operator[](Index const i) const { return row[i]; }
  Row &operator[](Index const i) { return row[i]; }

 private:
  Row row[RowsCount];
};

Matrix_& Matrix() {
  static Matrix_ impl;
  return impl;
}

}  // namespace Crow

#endif  // CROW_MATRIX_HPP_

