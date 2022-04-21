#include<iostream>
#include<iomanip>

using std::cin; using std::cout;

double PRECISION = 0.00001;

double fofx(double a/*x^2*/, double b/*x*/, double c/*1*/, double x){
    return a*x*x+b*x+c;
}

double binary_root(double a, double b, double c, double start, double end){
    // cout <<a <<" " <<b <<" " <<c <<" " <<start <<" " <<end <<"\n";
    while(start<=end){
        double mid = (start+end)/2.0;
        double val = fofx(a, b, c, mid);
        // cout <<mid <<" " <<val <<"\n";
        if((PRECISION*-1)<=val && val<=PRECISION){
            return mid;
        }
        else if(val > PRECISION){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return start;
}

int main(){
    double a, b, c;
    cout <<"a(x^2): "; cin >>a;
    cout <<"b(x): "; cin >>b;
    cout <<"c: "; cin >>c;
    double root = binary_root(a, b, c, 2, 4);
    cout <<std::setprecision(5) <<root <<"\n";
    return 0;
}