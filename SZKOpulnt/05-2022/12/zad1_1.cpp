#include <iostream>
#include <iostream>
#include <array>
using std::cin; using std::cout;

int main(){
    std::array<int, 11> arr = {2, -3, 1, -7, 4, -2, -1, 5, -3, 2, -1};
    int max = -1000;
    int start = 0; 
    int end = 10;
    for(int i = 0; i<11; i++){
        int sum = 0;
        for(int j = i; j<11; j++){
            sum += arr[j];
            if(sum > max){
                start = i;
                end = j;
                max = sum;
            }
        }
    }
    cout << arr[start] <<" " <<arr[end] <<"\n";
    return 0;
}