#include<iostream>
#include<random>

using std::cin; using std::cout;

int A[1000];


void print_arr(int n){
    for(int i = 0; i<n; i++){
        cout <<A[i] <<", ";
    }
    cout <<"\n";
}

int partition(int p, int k){
    int pivot = A[p];
    int pivot_index = p;
    for(int i = p+1; i<=k; i++){
        if(A[i]<=pivot){
            pivot_index++;
        }
    }
    std::swap(A[pivot_index-1], A[p]);

    cout <<pivot <<"\n";
    int marker1 = p, marker2 = k;
    while(marker1<pivot_index && marker2>pivot_index){
        while(A[marker1]<=pivot)marker1++;
        while(A[marker2]>pivot)marker2--;
        if(A[marker1]>pivot && A[marker2]<=pivot){
            std::swap(A[marker1], A[marker2]);
            marker1++;
            marker2--;
        }
    }
    return pivot_index;
    
}

void qsort(int p, int k, int n){
    if(p>=k) return;

    int pivot = partition(p, k);
    print_arr(n);
    qsort(p, pivot, n);
    print_arr(n);
    qsort(pivot+1, k, n);

}

int main(){
    srand(time(NULL));
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        A[i] = random()%20000 - 10000;
    }
    print_arr(n);
    qsort(0, n, n);
    print_arr(n);
    return 0;
}