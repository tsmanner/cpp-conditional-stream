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
