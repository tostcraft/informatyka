#include<bits/stdc++.h>
using std::cout;
using std::cin;

const int ARRAYSIZE = 100;

void print_arr2D(int arr[][ARRAYSIZE+1], int startx, int endx, int starty, int endy)
{
    for(int i = starty; i<=endy; i++)
    {
        for(int j = startx; j<=endx; j++)
        {
            cout <<std::right <<std::setw(3) <<arr[i][j] <<" ";
        }
        cout <<"\n";
    }
}


int main()
{
    int x, y;
    int packages[ARRAYSIZE];
    int numbers[ARRAYSIZE+1][ARRAYSIZE+1] = {0};
    // int values[ARRAYSIZE+1][ARRAYSIZE+1] = {0};

    cin >>x >>y;
    for(int i = 0; i<x; i++)
    {
        cin >>packages[i];
    }

    for(int i = 1; i<=x; i++)
    {
        int it = i-1;
        for(int j = 1; j<=y; j++)
        {
            if(j>packages[it] && (numbers[i][j-packages[it]]+1<numbers[i-1][j] || numbers[i-1][j]==0))
            {
                numbers[i][j] = numbers[i][j-packages[it]]+1;
                // values[i][j] = packages[it];
            }
            else
            {
                numbers[i][j] = numbers[i-1][j];
                // values[i][j] = values[i-1][j];
            }
        }
    }

    print_arr2D(numbers, 1, y, 1, x);
    cout <<"\n";
    // print_arr2D(values, 1, y, 1, x);
    // cout <<"\n";

    cout <<numbers[x][y] <<"\n";
    


    return 0;
}