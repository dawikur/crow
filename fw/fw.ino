// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "executor.hpp"
#include "matrix.hpp"

Crow::Matrix matrix;
Crow::Executor execute;

void setup() {
}

void loop() {
  bool updateNeeded = false;

  for (Crow::Index i = 0; i < matrix.rows(); ++i) {
    auto const row = matrix(i);
    auto const prev_row = matrix[i];

    if (row != prev_row) {

      for (Crow::Index j = 0; j < matrix.cols(); ++j) {
        if (row[j] == prev_row[j]) {
          continue;
        }

        execute({i, j, row[j]});
      }
      matrix[i] = row;
      updateNeeded = true;
    }
  }

  if (updateNeeded) {

  }
}
