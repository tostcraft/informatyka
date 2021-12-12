#include<bits/stdc++.h>
using std::cout;
using std::cin;

int binary_search(int arr[], int start, int stop, int n)
{
    while(start!=stop)
    {
        int pos = (stop-start)/2+start;
        if(arr[pos]==n)return pos;
        if(arr[pos]>n)
        {
            stop = pos-1;
        }
        else
        {
            start = pos+1;
        }
    }
    return start;
}



int main()
{
    int n, m;
    int arr_a[1000000] = {0};
    int arr_b[1000000] = {0};
    cin >>n >>m;
    int in, days = 0;
    for(int i = 1; i<=n; i++)
    {
        cin >>in;
        days+=in;
        arr_a[i] = days;
    }
    days = 0;
    for(int i = 1; i<=m; i++)
    {
        cin >>in;
        days+=in;
        arr_b[i] = days;
    }

    int day, month;
    char dir;
    int z;
    cin >>z;
    for(int i = 0; i<z; i++)
    {
        cin >>day >>month >>dir;
        if(dir == 'A')
        {
            int total_days = arr_a[month-1]+day;
            int converted_month = binary_search(arr_b, 0, m-1, total_days);
            int converted_day = total_days-arr_b[converted_month];
            cout << converted_day <<" " <<converted_month+1 <<"\n";
        }
        if(dir == 'B')
        {
            int total_days = arr_b[month-1]+day;
            int converted_month = binary_search(arr_a, 0, n-1, total_days);
            int converted_day = total_days-arr_a[converted_month];
            cout << converted_day <<" " <<converted_month+1 <<"\n";
        }
    }
    
    return 0;
}