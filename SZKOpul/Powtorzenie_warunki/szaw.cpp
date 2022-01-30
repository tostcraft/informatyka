#include<bits/stdc++.h>

using std::cout;
using std::cin;

int main()
{
    int x1, y1, x2, y2;
    cin >>x1 >>y1 >>x2 >>y2;
    if(x1 == x2 ^ y1 == y2)
    {
        cout <<"TAK" <<std::endl;
    }
    else
    {
        cout <<"NIE"<<std::endl;
    }
    return 0;
}