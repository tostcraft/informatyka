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
    int * finalarr = new int[k-p];
    int marker1 = p, marker2 = s;
    int c = 0;
    while(marker1<s && marker2<k){
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
    }
    for(int i = marker1; i<s; i++){
        finalarr[c] = arr[i];
        c++;
    }
    for(int i = marker2; i<k; i++){
        finalarr[c] = arr[i];
        c++;
    }
    
    for(int i = p; i<k; i++){
        arr[i] = finalarr[i-p];
    }
    print_arr(arr, k-p, p);

}

void mergesort(int arr[], int p, int k){
    if(p>=k) return;
    
    int s = (p+k)/2;
    mergesort(arr, p, s);
    mergesort(arr, s+1, k);
    
    merge(arr, p, s, k);
    print_arr(arr, k-p, p);

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