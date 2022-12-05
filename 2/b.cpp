#include <bits/stdc++.h>

enum Round {
  LOSE = 'X',
  DRAW = 'Y',
  WIN = 'Z',
};

/**
 * Rock <---- Paper <-- Scissors
 *  ^                       /
 *  |______________________/
 *
 *  When a player wins, the shape he chose plus 1 is the shape the opponent
 * chose.
 *  When a player lose, the shape he chose plus 2 is the shape the opponent
 * chose.
 */
int score(int elf, int round) {
  if (round == DRAW)
    return 3 + (elf % 'A' + 1);
  else if (round == WIN) {
    char me = (elf + 1) % 'A' % 3 + 'A';
    return 6 + (me % 'A' + 1);
  } else if (round == LOSE) {
    char me = (elf + 2) % 'A' % 3 + 'A';
    return 0 + (me % 'A' + 1);
  } else
    return 0;
}

int main() {
  int total = 0;
  std::string input;

  while (std::getline(std::cin, input)) {
    std::stringstream ss{input};
    char elf, round;
    ss >> elf >> round;

    total += score(elf, round);
  }

  std::cout << total << std::endl;

  return 0;
}