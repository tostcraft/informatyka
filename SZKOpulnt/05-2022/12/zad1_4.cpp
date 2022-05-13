#include<iostream>
#include<fstream>
#include<array>
using std::cout;

int main(){
    std::array<int, 100000> arr;
    std::ifstream file("dane1_4.txt");
    int a;
    int i = 0;
    while(file>>a){
        arr[i] = a;
        i++;
    }
    int max = 0;
    int start = 0;
    int end = 0;
    for(int i = 0; i<100000; i++)
    {
        if(arr[i]<0) continue;
        int sum = 0;
        for(int j = i; j<100000; j++){
            sum+=arr[j];
            if(sum<0)break;
            if(sum>max){
                start = i;
                end = j;
                max = sum;
            }
        }
    }
    cout <<max <<" " <<start <<" " <<end <<"\n";
    return 0;
}