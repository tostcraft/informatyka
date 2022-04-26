/*
Napisz program obliczający miejsce zerowe metodą bisekcji
f(x) = x^3-2x^2-5x+6
w przedziale <0, 2>
z dokładnością do 0.0001
*/
#include<iostream>

using std::cin; using std::cout;

double PREC = 0.0001;

double fofx(double x){
    return (x*x*x)-(2*x*x)-(5*x)+6;
}

double find_root_bisection(double start, double end){
    while(start<end){
        double mid = (start+end)/2;
        double y = fofx(mid);
        cout <<mid <<" " <<y <<"\n";
        if(-PREC<y && y<PREC){
            return mid;
        }
        else if(y>PREC){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return start;
}

int main(){
    double root = find_root_bisection(0, 2);
    cout <<root <<"\n";
    return 0;
}