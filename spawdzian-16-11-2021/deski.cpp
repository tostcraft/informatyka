#include<bits/stdc++.h>
using std::cout;
using std::cin;


int main()
{
    int n, a;
    cin >>n;
    int maxfour[4] = {0};
    for(int i=0; i<n; i++)
    {
        cin >>a;
        if(a>maxfour[0])
        {
            maxfour[3] = maxfour[2];
            maxfour[2] = maxfour[1];
            maxfour[1] = maxfour[0];
            maxfour[0]=a;
        }
        else if(a>maxfour[1])
        {
            maxfour[3]=maxfour[2];
            maxfour[2]=maxfour[1];
            maxfour[1] = a;
        }
        else if(a>maxfour[2])
        {
            maxfour[3] = maxfour[2];
            maxfour[2]=a;
        }
        else if(a>maxfour[3])
        {
            maxfour[3]=a;
        }
    }
    cout <<maxfour[3]*maxfour[3] <<"\n";
    return 0;
}