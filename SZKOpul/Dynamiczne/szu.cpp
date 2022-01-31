#include<bits/stdc++.h>
using std::cout;
using std::cin;



int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >>n; 
    auto grid = new int[1000][1000];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >>grid[i][j];
        }
    }
    auto values = new int[1000][1000];
    for(int i = 0; i<n; i++)
    {
        int x = 0, y = i%n;
        while(x<n && y>-1)
        {
            int p = 0;
            if(x>0)
            {
                p = values[y][x-1];
            }
            if(y>0 && values[y-1][x]>p)
            {
                p = values[y-1][x];
            }

            values[y][x] = grid[y][x]+p;
            x++;
            y--;
        }
    }
    for(int i = 0; i<n; i++)
    {
        int x = i%n, y = n-1;
        while(x<n && y>-1)
        {
            int p = 0;
            if(x>0)
            {
                p = values[y][x-1];
            }
            if(y>0 && values[y-1][x]>p)
            {
                p = values[y-1][x];
            }

            values[y][x] = grid[y][x]+p;
            x++;
            y--;
        }
    }

    cout <<values[n-1][n-1] <<"\n";

    return 0;
}