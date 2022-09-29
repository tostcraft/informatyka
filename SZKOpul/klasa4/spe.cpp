#include<iostream>

using std::cin;
using std::cout;

long nwd(long a, long b){
    long side;
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
    int *lights = new int[n];
    for(int i = 0; i<n; i++){
        cin >>lights[i];
        lights[i]+=1;
    }
    long current_nwd = nwd(lights[0], lights[1]);
    // cout <<current_nwd <<"\n";
    long total_nww = lights[0]*lights[1]/current_nwd;
    for(int i = 2; i<n; i++){
        current_nwd = nwd(total_nww, lights[i]);
        total_nww = total_nww*lights[i]/current_nwd;
    }
    cout <<total_nww-1 <<"\n";

    return 0;
}