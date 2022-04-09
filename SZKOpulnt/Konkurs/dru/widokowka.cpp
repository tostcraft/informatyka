#include <cstddef>
#include<iostream>

using std::cin;
using std::cout;

int main(){
    int n;
    cin >>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >>arr[i];
    }

    int max = 0;
    for(int i = 0; i<n-1; i++){
        int len = 0;
        for(int j = 0; j<arr[i] && j+i<n; j++){
            len++;
            if(arr[i+j]<arr[i]){
                len--;
                break;
            }
        }
        if(len>max)
        {
            max = len;
        }
    }
    cout <<max;
    cout <<"\n";
    return 0;
}