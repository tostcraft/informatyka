#include<iostream>
using std::cout;
using std::cin;


int byte_inversion(int n){
    int inversed = 2;
    while(n>0){
        short bit = n & 1;
        cout <<bit;
        inversed = inversed | bit;
        n = n >> 1;
        inversed = inversed << 1;
    }
    cout <<" ";
    return inversed;
    
}

long quick_power(int x, int p){
    p = byte_inversion(p);
    long ret = 1;
    while(p>1){
        short bit = p & 1;
        ret = ret*ret;
        if(bit == 1){
            ret*=x;
        }
        p = p >> 1;

    }
    return ret;

}

int main()
{

    int x, p;
    cin >>x;
    cin >>p;
    cout <<quick_power(x, p);

    cout <<"\n";
    return 0; 
}