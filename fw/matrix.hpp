// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_MATRIX_HPP_
#define CROW_MATRIX_HPP_

#include "config.hpp"
#include "row.hpp"

namespace Crow {

class Matrix {
 public:
  static int rows() { return Config::Rows; }
  static int cols() { return Config::Cols; }

  Matrix() : row{0} {}

  Row operator()(int const i) { return Row{0}; }

  Row operator[](int const i) const { return row; }
  Row &operator[](int const i) { return row; }

 private:
  Row row;
};

}  // namespace Crow

#endif  // CROW_MATRIX_HPP_

