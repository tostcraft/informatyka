#include<bits/stdc++.h>
using std::cout;
using std::cin;


int binary_search(long * arr, int start, int stop, long long int n)
{
    while(start<=stop)
    {
        int pos = (stop+start)/2;
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
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >>n >>m;
    int in, days = 0;
    auto arr_a = new long[1000000];
    auto arr_b = new long[1000000];
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
            long total_days = arr_a[month-1]+day;
            int converted_month = binary_search(arr_b, 0, m, total_days);
            int converted_day = total_days-arr_b[converted_month-1];
            cout << converted_day <<" " <<converted_month <<"\n";
        }
        if(dir == 'B')
        {
            long total_days = arr_b[month-1]+day;
            int converted_month = binary_search(arr_a, 0, n, total_days);
            int converted_day = total_days-arr_a[converted_month-1];
            cout << converted_day <<" " <<converted_month <<"\n";
        }
    }
    
    return 0;
}