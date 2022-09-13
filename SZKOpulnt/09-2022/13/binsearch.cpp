#include<iostream>
#include<random>

using std::cin; using std::cout;

bool binsearch(int arr[], int p, int k, int x){
    if(p==k) return arr[p] == x;
    int s = (p+k)/2;
    if(arr[s] < x) return binsearch(arr, s+1, k, x);
    return binsearch(arr, p, s, x);
}

int main(){
    std::srand(time(NULL));
    int n, x;
    cin >>n;
    int* arr = new int[n]{0};
    for(int i = 0; i<n; i++){
        arr[i] = arr[(i-1)%n] + random() % 200;
        cout << arr[i] <<" ";
    }
    cout <<"\n";
    cin >>x;

    cout <<binsearch(arr, 0, n-1, x) <<"\n";   

    return 0;
}