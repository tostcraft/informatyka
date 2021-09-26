#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    int n;
    cin >> n;
    int * tab;
    tab = new int[n];
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tab[i];
    }
    int x;
    cin >> x;
    for (int j = 1; j <= n; j++)
    {
        if (x == tab[j])
        {
            k++;
        }
    }
    cout << k << " ";
    for (int j = 1; j <= n; j++)
    {
        if (x == tab[j])
        {
            cout << j << " ";
        }
    }
    cout << std::endl;
}