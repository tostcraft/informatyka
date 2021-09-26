#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    long long int n, a, max, min;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a > max || i==0)
        {
            max = a;
        }
        if (a < min || i == 0)
        {
            min = a;
        }
    }
    cout << max - min << std::endl;
    return 0;
}