#include<bits/stdc++.h>
using std::cout;
using std::cin;

int binary_search(std::array<int, 100000> arr, int start, int stop, int n)
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
    int n, m, bajtek, w = 0;
    std::array<int, 100000> bitek = {0};
    cin >> n >>m;
    for(int i = 0; i<n; i++)
    {
        cin >>bitek[i];
    }
    std::sort(bitek.begin(), bitek.begin()+n);
    for(int i = 0; i<m; i++)
    {
        cin >>bajtek;
        int a = binary_search(bitek, 0, n, bajtek);
        if(bitek[a]!=bajtek) w++;
    }
    cout <<w <<"\n";


    return 0;
}