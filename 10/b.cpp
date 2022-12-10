#include <bits/stdc++.h>

struct Sprite {
  int first, second, third;
  Sprite() : first(0), second(1), third(2) {}

  void set_position(int middle_position) {
    second = middle_position % 40;
    first = (second - 1 + 40) % 40;
    third = (second + 1) % 40;
  }

  bool get_pixel(int position) {
    if (position == first) return true;
    if (position == second) return true;
    if (position == third) return true;
    return false;
  }
};

int main() {
  std::string command;
  int signal_strength = 0;
  int register_x = 1;
  Sprite sprite;

  for (uint cycle = 1; std::cin >> command; cycle++) {
    if ((cycle - 1) % 40 == 0) std::cout << '\n';

    if (sprite.get_pixel((cycle - 1) % 40)) {
      std::cout << '#';
    } else {
      std::cout << '.';
    }

    if (command == "noop") {
      continue;
    }

    int amount;
    std::cin >> amount;
    cycle++;

    if ((cycle - 1) % 40 == 0) std::cout << '\n';
    if (sprite.get_pixel((cycle - 1) % 40)) {
      std::cout << '#';
    } else {
      std::cout << '.';
    }

    register_x += amount;
    sprite.set_position(register_x);
  }

  return 0;
}