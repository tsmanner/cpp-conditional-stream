{
  pkgs ? import <nixpkgs> {},
  compiler ? pkgs.clang_11
}:
pkgs.stdenv.mkDerivation rec {
  name = "cpp-conditional-ostream-tests";
  src = ./..;
  buildInputs = [ pkgs.which compiler pkgs.rapidcheck ];
  buildCommand = ''${compiler}/bin/c++ -o $out -g -std=c++11 -Wall -Wextra -Werror -I$src/include $src/tests/main.cpp -lrapidcheck'';
}
