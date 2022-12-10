#include <bits/stdc++.h>

const size_t rope_length = 10;

using Position = std::pair<int, int>;
using Adjustment = std::pair<int, int>;
using PositionSet = std::set<Position>;
using Rope = std::vector<Position>;

void move_head(Position& head_position, char direction) {
  switch (direction) {
    case 'U':
      head_position.second += 1;
      break;
    case 'D':
      head_position.second -= 1;
      break;
    case 'L':
      head_position.first -= 1;
      break;
    case 'R':
      head_position.first += 1;
      break;
  }
}

bool point_adjacent(const Position& p1, const Position& p2) {
  return std::abs(p1.first - p2.first) <= 1 &&
         std::abs(p1.second - p2.second) <= 1;
}

void adjust_rope(Rope& rope) {
  for (size_t i = 1; i < rope.size(); ++i) {
    if (point_adjacent(rope.at(i - 1), rope.at(i))) {
      break;
    }

    Adjustment adjustment{rope.at(i - 1).first - rope.at(i).first,
                          rope.at(i - 1).second - rope.at(i).second};
    if (adjustment.first > 0) {
      rope.at(i).first += 1;
    }
    if (adjustment.first < 0) {
      rope.at(i).first -= 1;
    }

    if (adjustment.second > 0) {
      rope.at(i).second += 1;
    }
    if (adjustment.second < 0) {
      rope.at(i).second -= 1;
    }
  }
}

int main() {
  char direction = 0;
  int step_size = 0;
  Rope rope(rope_length, Position{0, 0});
  PositionSet tail_visited{rope.back()};

  while (std::cin >> direction >> step_size) {
    for (int s = 0; s < step_size; ++s) {
      move_head(rope.front(), direction);

      adjust_rope(rope);
      tail_visited.insert(rope.back());
    }
  }

  std::cout << tail_visited.size() << std::endl;

  return 0;
}