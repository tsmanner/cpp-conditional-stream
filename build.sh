#!/usr/bin/env sh
nix run nixpkgs.clang_11 -c clang++ -g -std=c++11 -Wall -Wextra -Werror -Iinclude main.cpp
