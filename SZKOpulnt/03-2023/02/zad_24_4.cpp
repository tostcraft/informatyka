#include<iostream>
using std::cout;
using std::cin;

int F(int*&T, int p, int k, int e){
    if(k==p){
        if(T[p]>e){
            cout <<p <<" ";
            return p;
        }
        cout <<p+1 <<" ";
        return p+1;
    }
    int s = (p+k)/2;
    if(T[s]>e){
        return F(T, p, s, e);
    }
    return F(T, s+1, k, e);
}

int main()
{
    int n;
    cin >>n;
    int * T = new int[n];
    for(int i = 0; i<n; i++){
        cin >>T[i];
    }
    int a, b;
    cin >>a;
    cin >>b;
    int ans = F(T, 0, n-1, b) - F(T, 0, n-1, a-1);
    cout << ans;
    cout <<"\n";
    return 0;
}