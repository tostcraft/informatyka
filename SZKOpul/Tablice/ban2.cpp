#include<bits/stdc++.h>
using std::cout;
using std::cin;


int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n ,w=0;
    bool checking = false;
    cin >>n;
    int arr[30000] = {-1};
    for(int i = 0; i<n; i++)
    {
        cin >>arr[i];
    }
    bool bit_arr[30000] = {false};

    int pos = 0;
    int i =0;
    while(i<n+1)
    {
        if(!bit_arr[pos])
        {
            checking = true;
            bit_arr[pos] = true;
            pos = arr[pos]-1;
            i++;
        }
        else if(bit_arr[pos] && checking)
        {
            pos = 0;
            w++;
            checking = false;
        }
        if(!checking and bit_arr[pos])
        {
            pos++;
        }
    }
    cout <<w <<"\n";


    return 0;
}