#include<iostream>
#include<cmath>
using std::cin; using std::cout;

bool is_prime(int n){
    if(n == 1 || n == 0) return false;
    for(int i = 2; i<=n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int sum_of_digits(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int sum_of_binary(int n){
    int sum = 0;
    while(n>0){
        sum += n%2;
        n/=2;
    }
    return sum;
}

int main(){
    int start;
    int stop;
    int c = 0;
    cin >>start;
    cin >>stop;
    for(int i = start; i<=stop; i++){
        if(i%2==0 && i!=2) continue;
        
        int digsum = sum_of_digits(i);
        int binsum = sum_of_binary(i);
        if(is_prime(i) && is_prime(digsum) && is_prime(binsum)){
            c++;
        }
    }
    cout <<c <<"\n";
    return 0;
}