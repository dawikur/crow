// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_MATRIX_HPP_
#define CROW_MATRIX_HPP_

#include "config.hpp"
#include "row.hpp"

namespace Crow {

class Matrix {
 public:
  using GetRowImpl = Row (*)(Index const);

  Matrix() = default;
  Matrix(Matrix const &) = delete;

  void setup(GetRowImpl const newGetRowImpl) {
    getRowImpl = newGetRowImpl;
  }

  static Index rows() { return RowsCount; }
  static Index cols() { return ColsCount; }

  Row operator()(Index const i) { return (*getRowImpl)(i); }

  Row operator[](Index const i) const { return row[i]; }
  Row &operator[](Index const i) { return row[i]; }

 private:
  GetRowImpl getRowImpl;
  Row row[RowsCount];
};

}  // namespace Crow

#endif  // CROW_MATRIX_HPP_

