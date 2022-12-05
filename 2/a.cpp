#include <bits/stdc++.h>

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
int score(int elf, int me) {
  int shape_score = (me % 'X' + 1);

  if (elf + ('X' - 'A') == me) return 3 + shape_score;

  if (((elf + 1) % 'A' % 3) + 'X' == me)
    return 6 + shape_score;
  else
    return 0 + shape_score;
}

int main() {
  int total = 0;
  std::string input;

  while (std::getline(std::cin, input)) {
    std::stringstream ss{input};
    char elf, me;
    ss >> elf >> me;

    total += score(elf, me);
  }

  std::cout << total << std::endl;

  return 0;
}