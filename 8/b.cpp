#include <bits/stdc++.h>

using Map = std::vector<std::string>;
using Axis = size_t;
using AxisSize = size_t;
using Col = std::string;
using Row = std::string;

uint char_to_int(char c) { return c - '0'; }

uint scenic_score(const Map &map, Axis x, Axis y) {
  uint tree_height = char_to_int(map[y][x]);
  uint top_visible = 0;
  uint bottom_visible = 0;
  uint left_visible = 0;
  uint right_visible = 0;

  // top
  // to deal with < 0 case (which is unsigned)
  // we use y + 1 != 0 instead of y <= 0
  // NOTE: for a unsigned type, 0 - 1 = 2^N - 1 (> 0)
  for (Axis y_ = y - 1; y_ + 1 != 0; y_--, top_visible++) {
    if (char_to_int(map[y_][x]) >= tree_height) {
      top_visible++;
      break;
    }
  }

  // bottom
  for (Axis y_ = y + 1; y_ < map.size(); y_++, bottom_visible++) {
    if (char_to_int(map[y_][x]) >= tree_height) {
      bottom_visible++;
      break;
    }
  }

  // left
  for (Axis x_ = x - 1; x_ + 1 != 0; x_--, left_visible++) {
    if (char_to_int(map[y][x_]) >= tree_height) {
      left_visible++;
      break;
    }
  }

  // right
  for (Axis x_ = x + 1; x_ < map[0].size(); x_++, right_visible++) {
    if (char_to_int(map[y][x_]) >= tree_height) {
      right_visible++;
      break;
    }
  }

  return top_visible * bottom_visible * left_visible * right_visible;
}

uint max_scenic_score(const Map &map, AxisSize col, AxisSize row) {
  uint max_score = 0;
  Axis x = 0;
  Axis y = 0;

  for (y = 1; y < row - 1; y++) {
    for (x = 1; x < col - 1; x++) {
      max_score = std::max(max_score, scenic_score(map, x, y));
    }
  }

  return max_score;
}

int main() {
  AxisSize col = 0;
  AxisSize row = 0;
  std::string input_string;
  Map map;
  map.reserve(100);

  for (row = 0; std::getline(std::cin, input_string); row++) {
    map.push_back(input_string);
  }
  col = map[0].size();

  std::cout << max_scenic_score(map, col, row) << std::endl;

  return 0;
}