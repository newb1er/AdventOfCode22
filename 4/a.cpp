#include <bits/stdc++.h>

int main() {
  std::string str;
  int count = 0;

  while (std::getline(std::cin, str)) {
    auto left = str.substr(0, str.find(','));
    auto right = str.substr(str.find(',') + 1);
    auto left_range =
        std::make_pair(std::stoi(left.substr(0, left.find('-'))),
                       std::stoi(left.substr(left.find('-') + 1)));
    auto right_range =
        std::make_pair(std::stoi(right.substr(0, right.find('-'))),
                       std::stoi(right.substr(right.find('-') + 1)));

    if (left_range.first <= right_range.first &&
        left_range.second >= right_range.second) {
      count++;
    } else if (right_range.first <= left_range.first &&
               right_range.second >= left_range.second) {
      count++;
    }
  }

  std::cout << count << std::endl;
}