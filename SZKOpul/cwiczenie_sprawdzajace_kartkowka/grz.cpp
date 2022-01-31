#include<bits/stdc++.h>
using std::cout;
using std::cin;


/*

Zadanie zrobione dzięki pomocy Agaty

*/


int main()
{
    
    int n;
    cin >>n; 
    auto grid = new long long int[1000][1000];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >>grid[i][j];
        }
    }
    auto values = new long long int[1000][1000];
    
    values[0][0] = grid[0][0];

    for(int i = 1; i<n; i++)
    {
        values[0][i] = grid[0][i]+values[0][i-1];
        values[i][0] = grid[i][0] + values[i-1][0];
    }

    for(int i = 1; i<n; i++)
    {
        for(int j = 1; j<n; j++)
        {
            values[i][j] = grid[i][j]+std::max(values[i-1][j], values[i][j-1]);
        }
    }

    cout <<values[n-1][n-1] <<"\n";

    return 0;
}