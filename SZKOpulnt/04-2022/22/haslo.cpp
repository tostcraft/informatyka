#include <ios>
#include<iostream>

using std::cin; using std::cout;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    long *arr = new long[1000000];
    for (int i = 0; i<n; i++){
        cin >>arr[i];
    }

    int count = 0;
    for(int i = 0; i<n-1; i++){
        long sum = arr[i];
        for(int j = i+1; j<n; j++){
            if(arr[j] == sum){
                count++;
            }
            sum+=arr[j];
        }
    }

    cout <<count <<"\n";

    return 0;
}