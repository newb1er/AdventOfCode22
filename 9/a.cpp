#include <bits/stdc++.h>

using Position = std::pair<int, int>;
using PositionSet = std::set<Position>;

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

int main() {
  char direction = 0;
  int step_size = 0;
  Position head_position{0, 0};
  Position tail_position{0, 0};
  PositionSet tail_visited{tail_position};

  while (std::cin >> direction >> step_size) {
    for (int s = 0; s < step_size; ++s) {
      Position last_head_position = head_position;
      move_head(head_position, direction);

      if (!point_adjacent(head_position, tail_position)) {
        tail_position = last_head_position;
        tail_visited.insert(tail_position);
      }
    }
  }

  std::cout << tail_visited.size() << std::endl;

  return 0;
}