#!/usr/bin/env sh
nix run nixpkgs.clang_11 -c clang++ -g -Wall -Wextra -Werror -Iinclude main.cpp