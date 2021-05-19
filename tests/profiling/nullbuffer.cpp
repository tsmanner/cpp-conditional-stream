#include <iostream>
#include <iterator>
#include <streambuf>

#include "conditional_ostream.h"
#include "profile.h"


class blackhole_buf final : public std::streambuf {
    char_type target[64];
    std::streamsize xsputn(const char_type*, std::streamsize n) { return n; }
    int_type overflow(int_type = traits_type::eof()) {
        setp(target, std::end(target));
        return 0;
    }
};


int main() {
  blackhole_buf buf {};
  std::ostream stream { &buf };
  time_streaming(stream);
  return 0;
}
