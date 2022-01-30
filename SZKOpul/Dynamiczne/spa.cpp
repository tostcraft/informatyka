#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    int arr[150] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    std::sort(arr, arr + n);
    int s1 = 0, s2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1 >= s2)
        {
            s2 += arr[i];
        }
        else
        {
            s1 += arr[i];
        }
    }
    if (s1 > s2)
        cout << s1 << " " << s2 << "\n";
    else
        cout << s2 << " " << s1 << "\n";
    return 0;
}