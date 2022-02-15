#include<bits/stdc++.h>
using std::cout;
using std::cin;

int binary_search(int * arr, int start, int stop, int n)
{
    while(start<=stop)
    {
        int pos = (stop+start)/2;
        if(arr[pos]>=n)
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
    int n;
    cin >>n;
    auto bierki = new int[n];

    for(int i = 0; i<n; i++)
    {
        cin>>bierki[i];
    }
    std::sort(bierki, bierki+n);

    int a = 0;
    for(int i = 0; i<n; i++)
    {
        int val = bierki[i]+bierki[i+1];
        int j = binary_search(bierki, i+2, n, val);
        if(j>n)j--;
        if(a<j-i) 
        {
            a = j-i;
        }
    }
    cout <<a <<"\n" ;
    return 0;
}