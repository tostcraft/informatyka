#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    int n;
    cin >> n;
    int counters[1000000] = {0};
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        counters[a - 1]++;
    }
    int odd = 0;
    for (int i = 0; i < 1000000; i++)
    {
        if (counters[i] % 2 == 1)
        {
            odd++;
        }
    }
    if (n % 2 == 0 && odd == 0)
    {
        cout << "TAK";
        return 0;
    }
    else if (n % 2 != 0 && odd == 1)
    {
        cout << "TAK";
        return 0;
    }
    cout << "NIE";
    return 0;
}