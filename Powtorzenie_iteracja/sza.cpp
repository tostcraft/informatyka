#include<bits/stdc++.h>

using std::cout;
using std::cin;

int main()
{
    int a;
    cin>>a;
    for(int i=0; i<a; i++)
    {
        for(int j=0;j<a;j++)
        {
            cout <<(j+i)%2;
        }
        cout <<std::endl;
    }
}