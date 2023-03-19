#include<iostream>
#include<cmath>
using std::cout;
using std::cin;

long narcissise(long x){
    long copy = x;
    long len = 0;
    while(copy>0){
        len+=1;
        copy/=10;
    }
    copy = x;
    long sum = 0;
    while(copy>0){
        int digit = copy%10;
        copy/=10;
        int add = pow(digit, len);
        sum+= add;
    }
    return sum;
    
}

long Bconversion(int n, int B){
    /*returns REVERSED decimal interpretation of a number converted to base B (from 2 to 10)*/
    long ret = 0;
    while (n>0)
    {
        int digit = n%B;
        n/=B;
        ret = ret*10+digit;
    }
    return ret;
    

}

int main()
{
    int x, B;
    cin >>x;
    cin >>B;
    long temp = Bconversion(x, B);
    long fin = narcissise(temp);
    cout <<temp <<" " <<fin <<"\n";
    if(fin == x) cout <<"TAK\n";
    else cout <<"NIE\n";
    return 0;
}