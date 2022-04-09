#include<iostream>

using std::cout;
using std::cin;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >>n;
    cin >>q;
    int* arr = new int[n]{0};
    for(int i = 0; i<q; i++)
    {
        int r, m, c;
        cin >>r; cin >>m; cin >>c;
        for(int j = r; j<n; j+=m){
            arr[j] = c;
        }
    }
    for(int i = 0; i<n; i++){
        cout <<arr[i] <<" ";
    }
    cout <<"\n";

    return 0;
}