#include <bits/stdc++.h>

int main() {
  std::string str;
  std::priority_queue<int> pq;
  int calo;
  calo = 0;

  while (std::getline(std::cin, str)) {
    if (str.length() == 0) {
      pq.push(calo);
      calo = 0;
      continue;
    }

    calo += std::stoi(str);
  }

  calo = 0;
  for (int i = 0; i < 3; ++i) calo += pq.top(), pq.pop();

  std::cout << calo << std::endl;

  return 0;
}