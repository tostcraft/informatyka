#include<iostream>
using std::cout;
using std::cin;


int evaluate(double *&R, int n, double x){
    double w = 0;
    for(int i = n-1; i>=0; i--){
        w = (x*w+R[2*i])*x;
        cout <<R[2*i] <<" " <<w <<"\n";
    }
    return w/x;
}

int main()
{
    int n;
    double x;
    cin >>n;
    double *R = new double[2*n];
    for(int i = 0; i<n; i++){
        cin >>R[2*i];
        R[2*i+1] = 0;
    }
    cin>>x;
    cout <<evaluate(R, n, x);
    delete R;
    cout <<"\n";
    return 0;
}