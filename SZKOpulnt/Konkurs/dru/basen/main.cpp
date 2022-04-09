#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>

using std::cin;
using std::cout;

int main() {

  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int q;
  int n;
  cin >> q;

  for (int j = 0; j < q; j++) {
    cin >> n;

    long long max = 0;
    long long a = 0;
    long long b = 0;
    int x = std::sqrt(n);
    for (int i = x; i >0; i--) {
      if ((n - 2 * i) % (i + 2) == 0) {
        a = i;
        b = (n - 2 * i) / (i + 2);
        max = a * b;
        break;
      }
    }
    if (max == 0) {
      cout << "NIE\n";
    } else {
      cout << std::min(a, b) << " " << std::max(a, b) << "\n";
    }
  }

  return 0;
}