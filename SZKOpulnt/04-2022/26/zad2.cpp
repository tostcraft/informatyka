/*
f(x) = x*sin(x)
miejsca zerowe metodą bisekcji
-7 -6
-4 -3
3 4
*/
#include<iostream>
#include<cmath>

using std::cin; using std::cout;

double PREC = 0.0001;

double fofx(double x){
    return x*std::sin(x);
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
            if(std::abs(start) > std::abs(end)){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        else{
            if(std::abs(start) < std::abs(end)){
                end = mid;
            }
            else{
                start = mid;
            }
        }
    }
    return start;
}

int main(){
    double root = find_root_bisection(-7, -6);
    cout <<root <<"\n";
    return 0;
}