#include<iostream>

using std::cin;
using std::cout;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >>n;
    int ** arr_a = new int * [n];
    long ** arr_b = new long * [n];
    for (int i = 0; i<n; i++){
        arr_a[i] = new int[n];
        arr_b[i] = new long[n] {0};
    } 
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >>arr_a[i][j];
        }
    }
    arr_b[0][0] = arr_a[0][0];

    for(int i = 1; i<n; i++){
        arr_b[0][i] = arr_b[0][i-1]+arr_a[0][i];
        arr_b[i][0] = arr_b[i-1][0]+arr_a[i][0];
    }
    for(int i = 1;i<n;i++){
        for(int j = 1; j<n;j++){
            arr_b[i][j] = arr_b[i-1][j]+arr_b[i][j-1] - arr_b[i-1][j-1] + arr_a[i][j];
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0; j<n;j++){
            cout <<arr_b[i][j] <<" ";
        }
        cout <<"\n";
    }
    cout <<"\n";

    
}