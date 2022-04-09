#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
  int longest = 0;
  for (int i = 0; i < n; i++) {
    std::vector<int>::iterator it = v.begin() + i + v[i];
    if (v.begin() + i + v[i] > v.end()) {
      it = v.end();
    }
    std::vector<int> sub(v.begin() + i, it);
    int min_element = *std::min_element(sub.begin(), sub.end());
    std::cout<<min_element<<"\n";
    if ( min_element >= v[i]&& sub.size()>longest) {
      longest = sub.size();
    }
  }
  std::cout << longest;
}