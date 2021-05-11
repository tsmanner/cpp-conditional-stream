#pragma once

#include <ostream>


struct ConditionalStream {
  std::ostream& mOstream;
  const bool mEnabled { true };

  ConditionalStream(
    std::ostream &inOstream,
    bool const &inEnabled = true
  ):
    mOstream(inOstream),
    mEnabled(inEnabled)
  {}

};


template <typename T>
ConditionalStream &operator<<(ConditionalStream &cs, T const &t) {
  if (cs.mEnabled) {
    cs.mOstream << t;
  }
  return cs;
}
