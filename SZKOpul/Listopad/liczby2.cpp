#include<iostream>
using std::cout;
using std::cin;

long long fac(int n){
    long long res = 1;
    for (int i = 2; i<=n; i++){
        res*=i;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a;
        cin >>a;
        int copy = a;
        long long facsum = 0;
        while(copy>0){
            int digit = copy%10;
            copy = copy/10;
            facsum+=fac(digit);
        }
        if (a==facsum){
            cout <<a <<"\n";
        }
    }

    

    return 0;
}