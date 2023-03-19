#include<iostream>
typedef long long ll;

using std::cout;
using std::cin;

ll factorial(int n){
    ll r = 1;
    for(int i = 2; i<=n; i++){
        r*=i;
    }
    return r;
}

int main()
{
    int n, a;
    cin >>n;
    for(int i = 0; i<n; i++){
        cin>>a;
        int copy = a;
        ll sum = 0;
        while(copy>0){
            sum+=factorial(copy%10);
            copy/=10;
        }
        if(sum==a)
            cout << sum <<"\n";
    } 
    
    return 0;
}