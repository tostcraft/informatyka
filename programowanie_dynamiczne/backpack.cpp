#include<bits/stdc++.h>
using std::cout;
using std::cin;

const int ARRAYSIZE = 100;

void print_arr2D(int  arr[][ARRAYSIZE+1], int startx, int endx, int starty, int endy)
{
    for(int i = starty; i<=endy; i++)
    {
        for(int j = startx; j<=endx; j++)
        {
            cout <<arr[i][j] <<" ";
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
    int item_mass[ARRAYSIZE] = {0};
    int item_worth[ARRAYSIZE] = {0};
    int values[ARRAYSIZE+1][ARRAYSIZE+1] = {0};//tablica wartości
    int numbers[ARRAYSIZE+1][ARRAYSIZE+1] = {0};//numer przedmiotów

    cout <<"backpack capacity: "; cin >>cap;
    cout <<"number of items: ", cin >>n;
    cout <<"mass and value of item: \n";
    for(int i = 0; i<n; i++)
    {
        cout <<i+1 <<".  mass: "; cin >>item_mass[i];
        cout <<"    value: "; cin >>item_worth[i];
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=cap; j++)
        {
            if(j>=item_mass[i-1] && values[i-1][j]<values[i][j-item_mass[i-1]]+item_worth[i-1])
            {
                values[i][j] = values[i][j-item_mass[i-1]]+item_worth[i-1];
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


    cout <<"\nVALUES:\n";
    print_arr2D(values, 1, cap, 1, n);
    cout <<"\nNUMBERS:\n";
    print_arr2D(numbers, 1, cap, 1, n);

    cout <<"\nNajlepszy wynik: " <<values[n][cap];
    cout <<"\n";
    int marker = cap;
    while(marker>0)
    {
        int item = numbers[n][marker];
        item_count++;
        item_counters[item-1]++;
        marker-=item_mass[item-1];
    }
    cout <<"\nItem count: "<<item_count;
    cout <<"\n\nItems used:\n";
    for(int i = 0; i<n; i++)
    {
        cout <<"Item " <<i+1 <<": " <<item_counters[i] <<"\n";
    }

    return 0;
}