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
    /*
    PART 1
    Calculations & filling the arrays
    */
    int n, cap;
    int coin_value[ARRAYSIZE] = {0};
    int values[ARRAYSIZE+1][ARRAYSIZE+1] = {0};//number of coins to give
    int numbers[ARRAYSIZE+1][ARRAYSIZE+1] = {0};//last coin given

    cout <<"change: "; cin >>cap;
    cout <<"number of coin types: ", cin >>n;
    cout <<"value of coin type: \n";
    for(int i = 0; i<n; i++)
    {
        cout <<i+1<<" : "; cin >>coin_value[i];
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=cap; j++)
        {
            if(j>=coin_value[i-1] && (values[i-1][j]>values[i][j-coin_value[i-1]]+1 || i==1))
            {
                values[i][j] = values[i][j-coin_value[i-1]]+1;
                numbers[i][j] = i;
            }
            else
            {
                values[i][j] = values[i-1][j];
                numbers[i][j] = numbers[i-1][j];
            }
        }
    }
    /*
    PART 2:
    Output
    */
    int item_count = 0;
    int * item_counters = new int[n];
    for(int i = 0; i<n; i++)
        item_counters[i] = 0;


    cout <<"\nAMOUNTS:\n";
    print_arr2D(values, 1, cap, 1, n);
    cout <<"\nNUMBERS:\n";
    print_arr2D(numbers, 1, cap, 1, n);

    cout <<"\nBest outcome: " <<values[n][cap];
    cout <<"\n";
    int marker = cap;
    while(marker>0)
    {
        int item = numbers[n][marker];
        item_count++;
        item_counters[item-1]++;
        marker-=coin_value[item-1];
    }
    cout <<"\nCoin count: "<<item_count;
    cout <<"\n\nCojns used:\n";
    for(int i = 0; i<n; i++)
    {
        cout <<"Coin type " <<i+1 <<" value " <<coin_value[i] <<": " <<item_counters[i] <<"\n";
    }

    return 0;
}