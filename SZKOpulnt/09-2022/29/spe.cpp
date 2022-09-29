#include<iostream>
//ciagi 0-1 str. 63
using std::cin;
using std::cout;

long long nwd(long long a, long long b){
    int side;
    while(b>0){
        // cout <<a <<" " <<b <<"\n";
        side = a;
        a = b;
        b = side%b;
    }
    return a;
}

int main(){

    int n;
    cin >>n;
    long long *lights = new long long[n];
    for(int i = 0; i<n; i++){
        cin >>lights[i];
        lights[i]+=1;
    }
    long long int current_nwd = nwd(lights[0], lights[1]);
    // cout <<current_nwd <<"\n";
    long long int total_nww = lights[0]*lights[1]/current_nwd;
    for(int i = 2; i<n; i++){
        current_nwd = nwd(total_nww, lights[i]);
        total_nww = total_nww*lights[i]/current_nwd;
    }
    cout <<total_nww-1 <<"\n";

    return 0;
}