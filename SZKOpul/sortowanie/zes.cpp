#include<iostream>
using std::cout;
using std::cin;


// void print_arr(int *arr, int n){
//     for(int i = 0; i<n; i++){
//         cout << arr[i] <<" ";
//     }
//     cout <<"\n";
// }

void merge(int *arr, int p, int q, int r){
    
    int *left = new int[q-p+1];
    int *right = new int[r-q];
    int *merged = new int[r-p+1];

    for(int i = 0; i<q-p+1; i++){
        left[i] = arr[p+i];
    }
    for(int i = 0; i<r-q; i++){
        right[i] = arr[q+1+i];
    }

    int marker1 = 0, marker2 = 0;
    while(marker1<q-p+1 && marker2<r-q){
        if(left[marker1] > right[marker2]){
            merged[marker1+marker2] = left[marker1];
            marker1++;
        }
        else{
            merged[marker1+marker2] = right[marker2];
            marker2++;
        }
    }

    for(int i = marker1; i<q-p+1; i++){
        merged[marker2+i] = left[i];
    }
    for(int i = marker2; i<r-q; i++){
        merged[marker1+i] = right[i];
    }


    for(int i = 0; i<r-p+1; i++){
        arr[p+i] = merged[i];
    }

    delete left;
    delete right;
    delete merged;

}

void mergesort(int *arr, int p, int r){
    if(p>=r) return;
    int q = (p+r)/2;
    mergesort(arr, p, q);
    mergesort(arr, q+1, r);
    merge(arr, p, q, r);
}

int main()
{
    int n;
    cin >>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >>arr[i];
    }

    mergesort(arr, 0, n-1);
    int output = 0;

    for(int i = 1; i<n; i+=2){
        output += arr[i-1]-arr[i];
    }
    cout <<output <<"\n";


    return 0;
}