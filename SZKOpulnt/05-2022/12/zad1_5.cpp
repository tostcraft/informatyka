#include<iostream>
#include<fstream>
#include<array>
using std::cout;

int main(){
    std::array<int, 10> arr;
    std::ifstream file("dane1_5.txt");
    int a;
    int i = 0;
    while(file>>a){
        arr[i] = a;
        i++;
    }
    int max = 0;
    int start = 0;
    int end = 0;
    int sum = 0;
    int l = 0;
    for(int i = 0; i<(int)arr.size(); i++)
    {
        sum+=arr[i];
        l++;
        if(sum<0){
            l=0;
            sum = 0;
            continue;
        }
        if(sum>max){
            max = sum;
            start = i-l+1;
            end = i;
        }
    }
    cout <<max <<" " <<start+1 <<" " <<end+1 <<"\n";
    for(int i = start; i<=end; i++){
        cout <<arr[i] <<" ";
    }
    cout <<"\n";
    return 0;
}