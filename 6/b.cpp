
#include <bits/stdc++.h>

const int N = 14;

bool different_char(std::string& s, size_t begin, size_t end) {
  for (size_t i = begin; i < end; ++i) {
    auto pos = s.find(s.at(i), i + 1);
    if (pos != std::string::npos && pos < end) return false;
  }

  return true;
}

int main() {
  std::string str;

  std::cin >> str;

  for (size_t end = N; end <= str.size(); ++end) {
    if (different_char(str, end - N, end)) {
      std::cout << end << '\n';
      break;
    }
  }

  return 0;
}