#include<iostream>

using std::cin; using std::cout;

std::pair<long, long> NWD_exp(long a, long b){
    if(b==0) return std::pair<long, long>(1, 0); //if b is 0 then a is the NWD and we return (1, 0)
    std::pair<long, long> last = NWD_exp(b, a%b); //get the next iteration depth and save it as "last"
    long x = last.second; //let x be the last y
    long y = last.first - a/b*last.second; //let y be last.x - (a div b)  * last.y
    return std::pair<long, long>(x, y); //return a pair (x, y)

}

long long factorial(ulong a){
    if (a==0 or a ==1) return 1;
    return a*factorial(a-1);
}

long fib(ulong a){
    if(a==0 or a==1) return 1;
    return fib(a-1)+fib(a-2);
}

int main(){
    long a, b;
    cin >>a; cin>>b;
    auto outcome = NWD_exp(a, b);
    cout <<outcome.first << " " <<outcome.second <<"\n";
    return 0;
}