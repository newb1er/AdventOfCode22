#include <bits/stdc++.h>

using Map = std::vector<std::string>;
using Axis = size_t;
using AxisSize = size_t;

uint char_to_int(char c) { return c - '0'; }

bool visible(const Map &map, Axis x, Axis y) {
  uint tree_height = char_to_int(map[y][x]);
  bool top_visible = true;
  bool bottom_visible = true;
  bool left_visible = true;
  bool right_visible = true;

  // top
  for (Axis y_ = 0; y_ < y; y_++) {
    if (char_to_int(map[y_][x]) >= tree_height) {
      top_visible = false;
      break;
    }
  }

  // bottom
  for (Axis y_ = y + 1; y_ < map.size(); y_++) {
    if (char_to_int(map[y_][x]) >= tree_height) {
      bottom_visible = false;
      break;
    }
  }

  // left
  for (Axis x_ = 0; x_ < x; x_++) {
    if (char_to_int(map[y][x_]) >= tree_height) {
      left_visible = false;
      break;
    }
  }

  // right
  for (Axis x_ = x + 1; x_ < map[0].size(); x_++) {
    if (char_to_int(map[y][x_]) >= tree_height) {
      right_visible = false;
      break;
    }
  }

  return top_visible || bottom_visible || left_visible || right_visible;
}

uint visible_trees(const Map &map, AxisSize col, AxisSize row) {
  uint trees = 0;
  Axis x = 0;
  Axis y = 0;

  for (y = 1; y < row - 1; y++) {
    for (x = 1; x < col - 1; x++) {
      if (visible(map, x, y)) {
        trees++;
      }
    }
  }

  return trees;
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

  std::cout << visible_trees(map, col, row) + col + col + row + row - 4
            << std::endl;

  return 0;
}