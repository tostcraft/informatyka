#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    long long int k;
    cin >> k;
    while(k>0)
    {
        k/=16;
        if(k%16>9)
        {
            cout <<"TAK" <<std::endl;
            return 0;
        }
    }
    cout <<"NIE" <<std::endl;
    return 0;
}