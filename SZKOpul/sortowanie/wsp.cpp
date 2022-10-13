#include<iostream>

using std::cin;
using std::cout;

void print_arr(int arr[], int n){
    for(int i = 0; i<n && i<10; i++){
        cout <<arr[i] <<" ";
    }
    cout <<"\n";
}

void my_merge(int *arr, int p, int q, int r){

    int *left = new int[q-p+1];
    int *right = new int[r-q+1];
    for(int i = p; i<=q; i++){
        left[i-p] = arr[i];
    }
    //print_arr(left, q-p);
    for(int i = q+1; i<=r; i++){
        right[i-q-1] = arr[i];
    }
    //print_arr(right, r-q);

    int *merged = new int[r-p+1];
    int marker1 = 0, marker2 = 0;
    while(marker1<q-p+1 && marker2<r-q){
        if(left[marker1]>right[marker2]){
            merged[marker1+marker2] = left[marker1];
            marker1++;
        }
        else{
            merged[marker1+marker2] = right[marker2];
            marker2++;
        }
    }
    //print_arr(merged, r-p+1);

    for(int i = marker1; i<q-p+1; i++){
        merged[r-q+i] = left[i];
    }
    for(int i = marker2; i<r-q; i++){
        merged[q-p+1+i] = right[i];
    }

    for(int i = 0; i<r-p+1; i++){
        arr[i+p] = merged[i];
    }
    delete left;
    delete right;
    delete merged;

}

void mergesort(int arr[], int p, int r){
    if(p>=r) return;
    int q = (p+r)/2;
    mergesort(arr, p, q);
    mergesort(arr, q+1, r);
    my_merge(arr, p, q, r);

}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int n;
    cin >>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >>arr[i];
    }
    mergesort(arr, 0, n-1);
    print_arr(arr, 10);
    return 0;
}
