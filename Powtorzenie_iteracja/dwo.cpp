#include<bits/stdc++.h>
using std::cout;
using std::cin;


int main()
{
    long long int x, a = 1;
    cin >> x;
    for(int i = 1; i>-1; i++)
    {
        if(a*2>x)
        {
            cout <<i <<std::endl;
            break;
        }
        a*=2;
    }
    return 0;
}