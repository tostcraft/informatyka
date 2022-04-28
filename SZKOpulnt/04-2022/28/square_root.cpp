#include<iostream>
#include<iomanip>
#include<cmath>

using std::cin; using std::cout;

double PRECISION = 10;
double PREC_VAL = std::pow(0.1, PRECISION);

double fofx(double a/*x^2*/, double b/*x*/, double c/*1*/, double x){
    return a*x*x+b*x+c;
}

double binary_root(double a, double b, double c, double start, double end){
    // cout <<a <<" " <<b <<" " <<c <<" " <<start <<" " <<end <<"\n";
    while(start<=end){
        double mid = (start+end)/2.0;
        double val = fofx(a, b, c, mid);
        // cout <<mid <<" " <<val <<"\n";
        if((PREC_VAL*-1)<=val && val<=PREC_VAL){
            return mid;
        }
        else if(val > PREC_VAL){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return start;
}

double heron_root(double s){
    double x0 = s/2;
    double x1 = (x0+s/x0)/2;
    while(x1-x0>PREC_VAL){
        x0 = x1;
        x1 = (x0+s/x0)/2;
    }
    return x1;
}

int main(){
    double base;
    cin >>base;
    double root = binary_root(1,0,-base, 1, base);
    double root1 = heron_root(base);
    cout <<std::setprecision(PRECISION) <<root <<" " <<root1 <<"\n";
    return 0;
}