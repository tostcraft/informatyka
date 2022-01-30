#include<bits/stdc++.h>
using std::cout;
using std::cin;

const int ARRSIZE = 100;

void print_arr2D(int  arr[][ARRSIZE+1], int startx, int endx, int starty, int endy)
{
    for(int i = starty; i<endy; i++)
    {
        for(int j = startx; j<endx; j++)
        {
            cout <<arr[i][j] <<" ";
        }
        cout <<"\n";
    }
}

int main()
{
    int n;
    int arr1[ARRSIZE];
    int arr2[ARRSIZE];
    int numbers[ARRSIZE+1][ARRSIZE+1]={0};
    cin >> n;

    std::srand(time(NULL));
    for(int i =0; i<n; i++)
    {
        arr1[i] = std::rand()%10;
        arr2[i] = std::rand()%10;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(arr1[j-1]==arr2[i-1])
            {
                numbers[i][j] = numbers[i-1][j-1]+1;
            }
            else
            {
                numbers[i][j] = std::max(numbers[i-1][j], numbers[i][j-1]);
            }
        }
    }

    int w = numbers[n][n];
    int marker1 = n, marker2 = n;
    int * outcome = new int[w];
    int it = 0;
    while(marker1>0 && marker2>0)
    {
        if(numbers[marker2][marker1]==numbers[marker2-1][marker1])
            marker2--;
        else if(numbers[marker2][marker1]==numbers[marker2][marker1-1])
            marker1--;
        else
        {
            outcome[w-it-1] = arr2[marker2-1];
            marker2--;
            marker1--;
            it++;
        }
    }
    for(int i = 0; i<w; i++)
    {
        cout <<outcome[i] <<" ";
    }
    cout <<"\n";

    return 0;
}