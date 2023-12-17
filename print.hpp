#ifndef __PRINT_H__
#define __PRINT_H__

// Copyright (C) 2023 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
enum class Style {
  reset = 0,
  black = 30,
  red = 31,
  green = 32,
  yellow = 33,
  blue = 34,
  magenta = 35,
  cyan = 36,
  white = 37,
  black_bg = 40,
  red_bg = 41,
  green_bg = 42,
  yellow_bg = 43,
  blue_bg = 44,
  magenta_bg = 45,
  cyan_bg = 46,
  white_bg = 47,
  default_bg = 49,
  bold = 1,
  underline = 4,
  inverse = 7,
  bold_off = 21,
  underline_off = 24,
  inverse_off = 27,
};

using std::cout;

inline std::ostream &operator<<(std::ostream &os, Style _style) { return os << static_cast<int>(_style); }

void print(Style _style) { cout << "\033[" << _style << "m"; }
template<class T> void print(T _param) { cout << _param; }
template<class T, class... Types> void print(T _first, Types... _rest)
{
  cout << _first;
  print(_rest...);
}
template<class... Types> void print(Style _style, Types... _rest)
{
  cout << "\033[" << _style << "m";
  print(_rest...);
}

// print line
template<class T, class... Types> void println(T _first, Types... _rest) { print(_first, _rest..., "\n"); }

// print reset
template<class T, class... Types> void printr(T _first, Types... _rest) { print(_first, _rest..., Style::reset); }

// print line reset
template<class T, class... Types> void printlnr(T _first, Types... _rest)
{
  print(_first, _rest..., Style::reset, "\n");
}

#endif// __PRINT_H__


// “\x1b[1A”

/*
source:“\x1b[1A”
https://www.quora.com/How-can-you-move-back-up-a-line-in-c++

 */
