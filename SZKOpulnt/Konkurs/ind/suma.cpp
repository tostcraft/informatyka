#include<iostream>

using std::cin;
using std::cout;

long long DIVIDER = 1000000007;

int main(){
    int n;
    cin >>n;

    int* numbers = new int[n];
    for(int i = 0; i<n; i++)
    {
        cin >>numbers[i];
    }

    long long sum = 0;
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            sum += (numbers[i]^numbers[j]);
        }
    }

    cout <<sum%DIVIDER <<"\n";

    return 0;
}
