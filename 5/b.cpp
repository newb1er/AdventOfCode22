#include <bits/stdc++.h>

typedef struct _crate {
  int id;
  char name;
} crate;

auto parse_draw() {
  std::string str;
  std::vector<std::deque<char>> crates(0);

  while (std::getline(std::cin, str)) {
    if (str == "") break;
    if (crates.capacity() == 0) crates.resize((str.size() + 1) / 4);
    if (str.substr(0, 3).at(1) == '1') continue;

    for (int i = 0; i < crates.size(); i++) {
      if (str.at(i * 4 + 1) == ' ') continue;
      crates.at(i).push_front(str.at(i * 4 + 1));
    }
  }

  return crates;
}

void move_crates(std::vector<std::deque<char>>& crates, int quantity, int from,
                 int to) {
  std::stack<char> midpoint;

  for (int i = 0; i < quantity; i++) {
    midpoint.push(crates.at(from).back());
    crates.at(from).pop_back();
  }

  while (!midpoint.empty()) {
    crates.at(to).push_back(midpoint.top());
    midpoint.pop();
  }
}

int main() {
  auto crates = parse_draw();
  std::string str;

  while (std::getline(std::cin, str)) {
    std::stringstream ss(str);
    std::string foo_str;
    int quantity, from, to;

    ss >> foo_str >> quantity >> foo_str >> from >> foo_str >> to;

    move_crates(crates, quantity, from - 1, to - 1);
  }

  for (auto& stack : crates) {
    if (!stack.empty()) {
      std::cout << stack.back();
    }
  }

  std::cout << '\n';

  return 0;
}