#include<iostream>
using std::cout;
using std::cin;


int main()
{
    int x;
    cin >>x;
    int a = x/2;
    int b = x;
    while(b>a){
        cout <<a <<" " <<b <<"\n";
        b = a;
        a = (a+x/a)/2;
    };
    cout <<b <<"\n";
    return 0;
}