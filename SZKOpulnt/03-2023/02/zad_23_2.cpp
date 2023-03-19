#include<iostream>
using std::cout;
using std::cin;


int natural_root(int x){
    int a = x/2;
    while(true){
        int next = (a+x/a)/2;
        if(next >= a){
            break;
        }
        a = next;
    }
    return a;
}

int main()
{
    int x;
    cin>>x;
    cout <<natural_root(x) <<"\n";
    return 0;
}