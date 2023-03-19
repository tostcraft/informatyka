#include<fstream>
#include<iostream>

using std::cout;

bool is_prime(int num){
    for(int i = 2; i*i<=num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    std::ifstream file("punkty.txt");

    int x, y;
    int counter = 0;
    while (file >>x){
        file>>y;
        if(is_prime(x) && is_prime(y)) counter++;
    }

    file.close();
    cout <<counter;
    return 0;
}