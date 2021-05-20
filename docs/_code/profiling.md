---
title: Profiling Results
classes: wide
---

|      System |           CPU | Memory |                         Disk | `ofstream`<br>`prof.txt` | `ofstream`<br>`/dev/null` | `ostringstream` | "blackhole"<br>`streambuf` | `ofstream`<br>failbit | `ConditionalOStream`
|-------------|---------------|--------|------------------------------|--------------------------|---------------------------|-----------------|----------------------------|-----------------------|----------------------
| WSL2 Debian |      i7-8565U |   32GB |   Intel M.2 SSDPEKK- F512G8L |                 10.7935s |                  7.78622s |        7.37819s |                   5.94589s |              2.66578s |            0.538241s
| WSL2 Debian | Ryzen 7 3800X |   32GB | Sabrent M.2 Rocket 4.0 500GB |                 7.74714s |                  6.69068s |        5.84889s |                   4.17527s |              2.11662s |            0.550667s
| NixOS 20.09 |  Ryzen 7 1700 |   32GB |         PNY CS1311 240GB SSD |                 9.88139s |                  7.96852s |        7.35156s |                   5.09152s |              2.67259s |            0.684588s

## Test Function

**tests/profiling/profile.h**
```cpp
#include <chrono>
#include <iostream>

// 100,000,000
constexpr unsigned iterations = 100000000;

template <typename StreamType>
void time_streaming(StreamType &stream) {
  auto value = "hello world\n";
  auto t0 = std::chrono::steady_clock::now();
  for (unsigned i = 0; i < iterations; ++i) {
    stream << i << ": " << value;
  }
  auto t1 = std::chrono::steady_clock::now();
  std::chrono::duration<long double> dt = t1 - t0;
  std::cout << "Streaming took " << dt.count() << "s\n";
}
```

## Stream to a file

**tests/profiling/ofstream.cpp**
```cpp
#include <iostream>
#include <fstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  auto stream = std::ofstream("ofstream.cpp.txt", std::ios::trunc);
  time_streaming(stream);
  return 0;
}
```

## Stream to `/dev/null`

**tests/profiling/devnull.cpp**
```cpp
#include <iostream>
#include <fstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  auto stream = std::ofstream("/dev/null", std::ios::out);
  time_streaming(stream);
  return 0;
}
```

## Stream to a `std::ostringstream`

**tests/profiling/ostringstream.cpp**
```cpp
#include <iostream>
#include <sstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  std::ostringstream stream;
  time_streaming(stream);
  return 0;
}
```

## Stream to a "blackhole"

This includes an implementation of a `std::streambuf` that ignores all input, borrowed from [Deduplicator on the Code Review Stack Exchange](https://codereview.stackexchange.com/a/260936).

**tests/profiling/nullbuffer.cpp**
```cpp
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
```

## Stream to a `ConditionalOStream`

**tests/profiling/conditional.cpp**
```cpp
#include <iostream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  ConditionalOStream stream {};
  time_streaming(stream);
  return 0;
}
```
