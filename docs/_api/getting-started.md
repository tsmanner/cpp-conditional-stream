---
---

The `ConditionalOStream` class is a wrapper around an `std::ostream &` and a `bool`.  A templated `operator<<` is provided for `ConditionalOStream &` and any other type, which avoids streaming the other object if the `bool` is `false`.

A simple example usage is a program that prints a message if it is invoked with one argument, the string `"on"`.

```cpp
#include <iostream>
#include <string>
#include "conditional_ostream.h"

int main(int argc, char *argv[]) {
  if (argc == 2) {
    bool enabled = argv[1] == std::string("on");
    ConditionalOStream cs = ConditionalOStream(std::cout, enabled);
    cs << "The ConditionalOStream is enabled!\n";
  }
  return 0;
}
```

```sh
$ a.out on
The ConditionalOStream is enabled!
$ a.out
$ a.out off
$ a.out on foo bar
$
```
