#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::vector<std::string> v;
  for (int i = 0; i < n; i++) {
    std::string tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
  for (int iter = 0; iter < n; iter++) {
    int min = 1000000;
    std::string s;
    for (int i = 0; i < 1000; i++) {
      s = std::to_string(i * i);
      while (s.size() < 6) {
        s = "0" + s;
      }
      int sum = 0;
      for (int j = 0; j < 6; j++) {
        sum += std::min(abs(v[iter][j] - s[j]), 10 - abs(v[iter][j] - s[j]));
      }
      if (sum < min) {
        min = sum;
      }
    }
    std::cout << min << "\n";
  }
}