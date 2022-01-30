#include<bits/stdc++.h>
using std::cout;
using std::cin;
/*

Zrobione dzięki pomocy Martyny.

*/


int binary_search(long int arr[], long int start, long int stop, long int n)
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
    return -1;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long int n, m, bajtek, w = 0;
    long int bitek[100000] = {0};
    cin >> n >>m;
    for(int i = 0; i<n; i++)
    {
        cin >>bitek[i];
    }
    std::sort(bitek, bitek+n);
    for(int i = 0; i<m; i++)
    {
        cin >>bajtek;
        if(binary_search(bitek, 0, n, bajtek)==-1) 
        {
            w++;
        }
    }
    cout <<w <<"\n";
    return 0;
}