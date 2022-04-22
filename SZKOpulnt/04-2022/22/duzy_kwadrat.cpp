#include <ios>
#include<iostream>

using std::cin; using std::cout;

unsigned long long qpow(unsigned long long a, unsigned int n){
    unsigned long long w = 1;
    while(n>0){
        if(n%2==1){
            w *= a;
        }
        a*=a;
        n/=2;
    }
    return w;
}

int main(){
    unsigned int n; cin>>n;
    unsigned long long int number = qpow(10, n) - 1;
    cout <<number*number <<"\n";
    return 0;
}