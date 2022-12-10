#include <bits/stdc++.h>

int main() {
  std::string command;
  int signal_strength = 0;
  int register_x = 1;

  for (uint cycle = 1; std::cin >> command; cycle++) {
    if (cycle == 20 || ((cycle - 20) % 40 == 0 && cycle > 20)) {
      signal_strength += register_x * cycle;
    }

    if (command == "noop") {
      continue;
    }

    int amount;
    std::cin >> amount;
    cycle++;

    if (cycle == 20 || ((cycle - 20) % 40 == 0 && cycle > 20)) {
      signal_strength += register_x * cycle;
    }

    register_x += amount;
  }

  std::cout << signal_strength << '\n';

  return 0;
}