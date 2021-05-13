#pragma once

#include <ostream>


//
// Conditional Output Stream
//

struct ConditionalOStream {
  std::ostream *const mOStream { nullptr };

  // Explicit constructors so that implicit
  // conversion from `std::ostream &`s can't
  // happen and lead to ambiguous overloads.

  explicit ConditionalOStream() {}

  explicit ConditionalOStream(
    std::ostream *inOStream
  ):
    mOStream(inOStream)
  {}

  explicit ConditionalOStream(
    std::ostream &inOStream
  ):
    mOStream(&inOStream)
  {}

  explicit ConditionalOStream(
    std::ostream *inOStream,
    bool const &inEnabled
  ):
    mOStream(inEnabled ? inOStream : nullptr)
  {}

  explicit ConditionalOStream(
    std::ostream &inOStream,
    bool const &inEnabled
  ):
    mOStream(inEnabled ? &inOStream : nullptr)
  {}

};


//
// Templated daisy-chaining stream insertion operator
// for ConditionalOStream and a type T
//

// For a const T
template <typename T>
inline ConditionalOStream const &operator<<(
  ConditionalOStream const &inConditionalOStream,
  T const &inT
) {
  if (inConditionalOStream.mOStream) {
    (*inConditionalOStream.mOStream) << inT;
  }
  return inConditionalOStream;
}

// For a non-const T
template <typename T>
inline ConditionalOStream const &operator<<(
  ConditionalOStream const &inConditionalOStream,
  T &&inT
) {
  if (inConditionalOStream.mOStream) {
    (*inConditionalOStream.mOStream) << inT;
  }
  return inConditionalOStream;
}


//
// Special stream insertion operator for std::endl
// and other similar "special" stream functions.
//

inline ConditionalOStream const &operator<<(
  ConditionalOStream const &inConditionalOStream,
  std::ostream&(* const &inStreamFunction)(std::ostream&)
) {
  if (inConditionalOStream.mOStream) {
    (*inConditionalOStream.mOStream) << inStreamFunction;
  }
  return inConditionalOStream;
}
