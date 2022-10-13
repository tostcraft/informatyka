#include<iostream>

using std::cin;
using std::cout;

int top_three(int arr[], int n){
    int outcome[5] = {-1000, -1000, -1000, 1000, 1000}; //first, second, third, last-1, last
    for(int i = 0; i<n; i++){
        if(arr[i] > outcome[0]){
            outcome[2] = outcome[1];
            outcome[1] = outcome[0];
            outcome[0] = arr[i];
        }
        else if(arr[i] > outcome[1]){
            outcome[2] = outcome[1];
            outcome[1] = arr[i];
        }
        else if(arr[i] > outcome[2]){
            outcome[2] = arr[i];
        }
        if(arr[i]<outcome[4]){
            outcome[3] = outcome[4];
            outcome[4] = arr[i];
        }
        else if(arr[i]<outcome[3]){
            outcome[3] = arr[i];
        }
    }

    int op1 = outcome[0] * outcome[1] * outcome[2];
    int op2 = outcome[0] * outcome[3] * outcome[4];
    int to_return = (op1>op2)?op1:op2;
    //cout <<outcome[0] <<" " <<outcome[1] <<" " <<outcome[2] <<"\n";
    return to_return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int z;
    cin >>z;
    for(int i = 0; i<z; i++){
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int top = top_three(arr, n);
        cout <<top <<"\n";
        delete arr;
    }

    return 0;
}
