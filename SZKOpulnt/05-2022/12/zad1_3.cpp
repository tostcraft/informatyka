#include <fstream>
#include<iostream>
#include<array>
#include<fstream>
using std::cin; using std::cout;

int main(){
    std::array<int, 1000> arr;
    std::ifstream file("dane1_3.txt");
    int a;
    int i = 0;
    while(file>>a){
        arr[i] = a;
        i++;
    } 

    int max = 0;
    for(int i = 0; i<1000; i++)
    {
        if(arr[i]<0) continue;
        int sum = 0;
        for(int j = i; j<1000; j++){
            sum+=arr[j];
            if(sum>max){
                max = sum;
            }
        }
    }
    cout <<max <<"\n";
    return 0;
}