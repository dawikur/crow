// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_CONFIG_HPP_
#define CROW_CONFIG_HPP_

//
//   Fill these
// ===============

#define ROWS_COUNT 5
#define COLS_COUNT 13

// ===============

#ifndef ARDUINO
# include <cstdint>
#endif

namespace Crow {

using Index = uint8_t;

constexpr Index RowsCount = ROWS_COUNT;
constexpr Index ColsCount = COLS_COUNT;

#if ROWS_COUNT <= 2
# define ROWS_BITS 1
#elif ROWS_COUNT <= 4
# define ROWS_BITS 2
#elif ROWS_COUNT <= 8
# define ROWS_BITS 3
#elif ROWS_COUNT <= 16
# define ROWS_BITS 4
#elif ROWS_COUNT <= 32
# define ROWS_BITS 5
#elif ROWS_COUNT <= 64
# define ROWS_BITS 6
#else
# error "Unsupported rows size."
#endif

constexpr Index RowsBits = ROWS_BITS;

#if COLS_COUNT <= 2
# define COLS_BITS 1
#elif COLS_COUNT <= 4
# define COLS_BITS 2
#elif COLS_COUNT <= 8
# define COLS_BITS 3
#elif COLS_COUNT <= 16
# define COLS_BITS 4
#elif COLS_COUNT <= 32
# define COLS_BITS 5
#elif COLS_COUNT <= 64
# define COLS_BITS 6
#else
# error "Unsupported columns size."
#endif

constexpr Index ColsBits = COLS_BITS;

#define BITS_COUNT (ROWS_BITS + COLS_BITS + 1)

#if COLS_COUNT <= 8
  using RawRow = uint8_t;
#elif COLS_COUNT <= 16
  using RawRow = uint16_t;
#elif COLS_COUNT <= 32
  using RawRow = uint32_t;
#elif COLS_COUNT <= 64
  using RawRow = uint64_t;
#else
# error "Unsupported row count."
#endif

#if BITS_COUNT <= 8
  using RawCompressEvent = uint8_t;
#elif BITS_COUNT <= 16
  using RawCompressEvent = uint16_t;
#elif BITS_COUNT <= 32
  using RawCompressEvent = uint32_t;
#elif BITS_COUNT <= 64
  using RawCompressEvent = uint64_t;
#else
# error "Unsupported matrix"
#endif

}  // namespace Crow

#undef BITS_COUNT
#undef COLS_COUNT
#undef ROWS_COUNT

#endif  // CROW_CONFIG_HPP_
