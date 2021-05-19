#include <iostream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  ConditionalOStream stream {};
  time_streaming(stream);
  return 0;
}
