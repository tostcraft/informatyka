#include<iostream>
#include<random>

using std::cin; using std::cout;

bool binsearch(int arr[], int p, int k, int x){
    if(p==k) return arr[p] == x;
    int s = (p+k)/2;
    if(arr[s] < x) return binsearch(arr, s+1, k, x);
    return binsearch(arr, p, s, x);
}

int* random_array_gen(int size){
    int * arr = new int[size];
    for(int i = 0; i<size; i++){
        arr[i] = random() % 100;
    }
    return arr;
}

int* qsort(int*arr, int start, int end){
    int pivot = (start+end)/2;
    cout <<start <<" " <<end<<" " <<pivot <<"\n";
    for(int i = start; i<end; i++){
        cout <<arr[i] <<", ";
    }
    int marker1 = start, marker2 = end;
    while(marker1<marker2 && marker2<end){
        while(arr[marker1]<=arr[pivot]){
            marker1++;
        }
        while(arr[marker2]<=arr[pivot] && marker2<end){
            marker2--;
        }
        if(arr[marker1]>arr[marker2]){
            int hold = arr[marker1];
            arr[marker1]=arr[marker2];
            arr[marker2] = hold;
            marker1++;
            marker2--;
        }
        
    }
    
    if(start<pivot) arr = qsort(arr, start, pivot);
    if(pivot<end) arr = qsort(arr, pivot+1, end);
    for(int i = start; i<end; i++){
        cout <<arr[i] <<", ";
    }
    cout <<"\n";
    return arr;
}

int main(){
    std::srand(time(NULL));
    int n, x;
    cin >>n;
    int* arr = random_array_gen(n);
    int* arr2 = qsort(arr, 0, n-1);
    for(int i = 0; i<n; i++){
        cout <<arr2[i] <<", ";
    }
    
    cout <<"\n";
    cin >>x;

    cout <<binsearch(arr, 0, n-1, x) <<"\n";   

    return 0;
}