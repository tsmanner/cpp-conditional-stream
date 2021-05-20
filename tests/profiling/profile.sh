#!/usr/bin/env sh

# cout is absurdly slow, 100,000,000 lines took ~75s when I tried it, where ofstream only took 11-12s.
# nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/cout.cpp          && echo -n "Profiling cout.cpp:           " && ./a.out
nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/ofstream.cpp      && echo -n "Profiling ofstream.cpp:       " && ./a.out ; rm ofstream.cpp.txt
nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/devnull.cpp       && echo -n "Profiling devnull.cpp:        " && ./a.out
nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/ostringstream.cpp && echo -n "Profiling ostringstream.cpp:  " && ./a.out
nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/nullbuffer.cpp    && echo -n "Profiling nullbuffer.cpp:     " && ./a.out
nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/failbit.cpp       && echo -n "Profiling failbit.cpp:        " && ./a.out
nix run nixpkgs.clang_11 -c clang++ -Iinclude tests/profiling/conditional.cpp   && echo -n "Profiling conditional.cpp:    " && ./a.out
