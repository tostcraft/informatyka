#include <algorithm>
#include <iostream>
#include <vector>

int check(std::vector<int> arr, int n) {
  int suma = 0;
  for (int j = 0; j < n; j++) {
    suma += arr[j];
  }
  return suma/2;
}


int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr;
  for (int i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    arr.push_back(tmp);
  }
  std::sort(arr.begin(), arr.end());
  std::cout << check(arr, n);
}