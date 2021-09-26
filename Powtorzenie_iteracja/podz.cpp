#include<bits/stdc++.h>

using std::cin;
using std::cout;

int main()
{
    long long int a,b,w;
    cin >>a >>b;
    w =(b/5-(a-1)/5)+(b/3-(a-1)/3)-(b/15-(a-1)/15);
    cout <<w <<std::endl;
    return 0;
}