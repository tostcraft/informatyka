#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    int a, b, k, w;
    cin >> a >> b >> k;
    if (k<=a && 2 * k > a)
        w = b / k;
    else if (k <=b && 2 * k > b)
        w = a / k;
    else if (k < a && k < b)
        w = (a / k + b / k - 2) * 2;
    else
        w = 0;
    cout << w << std::endl;
}