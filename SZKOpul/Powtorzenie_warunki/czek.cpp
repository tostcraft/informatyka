#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    long int n, m, a;
    cin >> n >> m >> a;
    if (a % n == 0 ^ a % m == 0)
    {
        cout << "TAK" << std::endl;
    }
    else
    {
        cout << "NIE" << std::endl;
    }

    return 0;
}