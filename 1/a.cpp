#include <bits/stdc++.h>

int main() {
  std::string str;
  int calo, max_calo;
  max_calo = 0;
  calo = 0;

  while (std::getline(std::cin, str)) {
    if (str.length() == 0) {
      max_calo = std::max(calo, max_calo);
      calo = 0;
      continue;
    }

    calo += std::stoi(str);
  }

  std::cout << max_calo << std::endl;

  return 0;
}