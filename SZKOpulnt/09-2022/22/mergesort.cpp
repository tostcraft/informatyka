#include <future>
#include<iostream>
#include<random>
#include<algorithm>

using std::cin;
using std::cout;

int * make_ranodm_arr(int n, int max){
    srand(time(NULL));
    int * arr = new int[n];
    for(int i = 0; i<n; i++){
        int val = random();
        arr[i] = val%max - max/2;
    }
    return arr;
}

void print_arr(int * arr, int n, int s){
    for(int i = s; i<n; i++){
        cout <<arr[i] <<" ";
    }
    cout << "\n";
}

void merge(int arr[], int p, int s, int k){
    // cout <<"STARTING MERGE: " <<p <<" " <<s <<" " <<k <<"\n";
    int * finalarr = new int[k-p+1];

    if(k-p==1){
        if(arr[k]<arr[p]){
            int hold = arr[k];
            arr[k] = arr[p];
            arr[p] = hold;
        }
        // cout <<"2 ELEMENTS: ";
        // print_arr(arr, 10, 0);
        return;
    }

    int marker1 = p, marker2 = s+1;
    int c = 0;
    while(marker1<=s && marker2<=k){
        // cout <<c <<"\n" <<"marker1: " <<marker1 <<" " <<arr[marker1] <<"\nmarker2: " <<marker2 <<" " <<arr[marker2] <<"\n";
        if(arr[marker1]<=arr[marker2]){
            finalarr[c] = arr[marker1];
            c++;
            marker1++;
        }
        else{
            finalarr[c] = arr[marker2];
            c++;
            marker2++;
        }
        // print_arr(finalarr, k-p, 0);
    }
    for(int i = marker1; i<=s; i++){
        finalarr[c] = arr[i];
        c++;
    }
    for(int i = marker2; i<=k; i++){
        finalarr[c] = arr[i];
        c++;
    }
    // cout <<"FINAL ";
    // print_arr(finalarr, k-p, 0);
    for(int i = 0; i<k-p+1; i++){
        arr[p+i] = finalarr[i];
    }
    // cout <<"HERE ";
    // print_arr(arr, 10, 0);

}

void mergesort(int arr[], int p, int k){
    // cout <<"entering mergesort"<<p <<" "<<k <<"\n";
    if(p<k){
        int s = (k+p)/2;
        mergesort(arr, p, s);
        mergesort(arr, s+1, k);
        merge(arr, p, s, k);
    }
    else{
        // cout <<"EXITING" <<" " << p <<" " <<arr[p] <<"\n";
    }

}



int main(){
    int n;
    cin>>n;
    int * arr1 = make_ranodm_arr(n, 20);
    print_arr(arr1, n, 0);
    // print_arr(arr2, n);
    mergesort(arr1, 0, n);
    print_arr(arr1, n, 0);
    return 0;
}