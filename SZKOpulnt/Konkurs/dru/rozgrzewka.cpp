#include<iostream>

using std::cin;
using std::cout;

int main(){
    int n;
    cin >>n;
    if(n%17==0){
        cout <<0 <<"\n";
    }
    else{
        cout <<17-n%17  <<"\n";
    }
    return 0;
}