#include <sstream>
#include <rapidcheck.h>

#include "conditional_ostream.h"


struct StreamCounter {
  unsigned mCount { 0 };
};


std::ostream &operator<<(std::ostream &os, StreamCounter &sc) {
  ++sc.mCount;
  return os;
}


int main() {

  rc::check("ConditionalOStream(std::ostream *)",
    [](bool inEnable) {
      StreamCounter counter {};
      std::stringstream ss;
      ConditionalOStream(inEnable ? &ss : nullptr) << counter;
      RC_ASSERT(counter.mCount == (inEnable ? 1u : 0u));
    }
  );

  rc::check("ConditionalOStream(std::ostream &)",
    [](bool inEnable) {
      StreamCounter counter {};
      if (inEnable) {
        std::stringstream ss;
        ConditionalOStream(ss) << counter;
      }
      RC_ASSERT(counter.mCount == (inEnable ? 1u : 0u));
    }
  );

  rc::check("ConditionalOStream(std::ostream *, bool const &)",
    [](bool inEnable) {
      StreamCounter counter {};
      std::stringstream ss;
      ConditionalOStream(&ss, inEnable) << counter;
      RC_ASSERT(counter.mCount == (inEnable ? 1u : 0u));
    }
  );

  rc::check("ConditionalOStream(std::ostream &, bool const &)",
    [](bool inEnable) {
      StreamCounter counter {};
      std::stringstream ss;
      ConditionalOStream(ss, inEnable) << counter;
      RC_ASSERT(counter.mCount == (inEnable ? 1u : 0u));
    }
  );

  return 0;
}
