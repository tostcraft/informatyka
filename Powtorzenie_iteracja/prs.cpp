#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    int n, x, y, maxx = -1, maxy = -1, minx = 1000001, miny = 1000001;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x > maxx)
        {
            maxx = x;
        }
        if (x < minx)
        {
            minx = x;
        }
        if (y > maxy)
        {
            maxy = y;
        }
        if (y < miny)
        {
            miny = y;
        }
    }
    cout << 2 * (maxx - minx + maxy - miny) << std::endl;
    return 0;
}