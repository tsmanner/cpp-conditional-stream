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


template<typename _CharT, typename _Traits>
using EndlType = std::basic_ostream<_CharT, _Traits>&(*)(std::basic_ostream<_CharT, _Traits>&);

ConditionalStream &operator<<(ConditionalStream &cs, EndlType<char, std::char_traits<char>> const &inEndl) {
  if (cs.mEnabled) {
    cs.mOstream << inEndl;
  }
  return cs;
}

