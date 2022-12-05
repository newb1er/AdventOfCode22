#include <bits/stdc++.h>

int score(char ch) {
  if (ch < 'a') {
    return (ch - 'A') + 27;
  } else {
    return (ch - 'a') + 1;
  }
}

int main() {
  std::string str;
  int total = 0;
  std::array<std::string, 3> arr;

  for (int i = 0; std::getline(std::cin, arr.at(i)); ++i) {
    if (i && i % 2 == 0) {
      for (char ch : arr.at(0)) {
        if (arr.at(1).find(ch) != std::string::npos &&
            arr.at(2).find(ch) != std::string::npos) {
          total += score(ch);
          break;
        }
      }
      i = -1;
    }
  }

  std::cout << total << std::endl;

  return 0;
}