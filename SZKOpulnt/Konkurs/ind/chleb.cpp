#include<iostream>

using std::cin;
using std::cout;

int main(){

    long x, y;
    cin >>x;
    cin >>y;
    long w = x/y;
    if(y*w<x)
        w++;
    cout <<w;
    return 0;
}
