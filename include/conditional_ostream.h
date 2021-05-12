#pragma once

#include <ostream>


//
// Conditional Output Stream
//

struct ConditionalOStream {
  std::ostream& mOStream;
  const bool mEnabled { true };

  ConditionalOStream(
    std::ostream &inOStream,
    bool const &inEnabled = true
  ):
    mOStream(inOStream),
    mEnabled(inEnabled)
  {}

};


//
// Templated daisy-chaining stream insertion operator
// for ConditionalOStream and a type T
//

// For a const T
template <typename T>
ConditionalOStream &operator<<(
  ConditionalOStream &inConditionalOStream,
  T const &inT
) {
  if (inConditionalOStream.mEnabled) {
    inConditionalOStream.mOStream << inT;
  }
  return inConditionalOStream;
}

// For a non-const T
template <typename T>
ConditionalOStream &operator<<(
  ConditionalOStream &inConditionalOStream,
  T &&inT
) {
  if (inConditionalOStream.mEnabled) {
    inConditionalOStream.mOStream << inT;
  }
  return inConditionalOStream;
}


//
// Special stream insertion operator for std::endl
// and other similar "special" stream functions.
//

ConditionalOStream &operator<<(
  ConditionalOStream &inConditionalOStream,
  std::ostream&(* const &inStreamFunction)(std::ostream&)
) {
  if (inConditionalOStream.mEnabled) {
    inConditionalOStream.mOStream << inStreamFunction;
  }
  return inConditionalOStream;
}
