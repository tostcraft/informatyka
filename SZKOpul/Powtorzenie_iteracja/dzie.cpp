#include<bits/stdc++.h>
using std::cin;
using std::cout;


int main()
{
    long long int n, a;
    cin >>n;
    for(long long int i = 1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cout <<i <<std::endl;
            a=i;
        }
    }
    for(long long int i = a; i>0; i--)
    {
        if(n%i==0 && i*i<n)
        {
            cout <<n/i <<std::endl;
        }
    }
    return 0;
}
