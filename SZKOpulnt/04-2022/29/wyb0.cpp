#include<iostream>
using std::cin; using std::cout;

int main(){
    int n;
    cin >>n;
    cout <<n <<"\n";
    for(int i = 1; i<=n; i++){
        cout <<n+i <<" ";
    }
    cout <<"\n";
    return 0;
}