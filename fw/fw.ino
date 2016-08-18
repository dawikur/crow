// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "layer.hpp"
#include "matrix.hpp"

Crow::Matrix matrix;
Crow::Layer current_layer;

void setup() {
}

void loop() {
  for (Crow::Index i = 0; i < matrix.rows(); ++i) {
    auto const row = matrix(i);
    auto const prev_row = matrix[i];

    if (row != prev_row) {

      for (Crow::Index j = 0; j < matrix.cols(); ++j) {
        if (row[j] == prev_row[j]) {
          continue;
        }

        current_layer[i][j](row[j]);
      }
      matrix[i] = row;

    }
  }
}
