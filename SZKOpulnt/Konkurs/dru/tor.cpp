#include<iostream>

using std::cin;
using std::cout;

long long gcd(long long a, long long b){
    long long c;
    while(b!=0){
        c=a;
        a=b;
        b=c%a;
    }
    return a;
}

int main(){
    long long a ,b;
    cin >>a;
    cin >>b;
    cout <<a*b/gcd(a, b) <<"\n";
}