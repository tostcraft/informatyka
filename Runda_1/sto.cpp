#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    double f;
    cin >>f;
    double c = (f-32.0)*5/9;
    cout <<setprecision(2) <<fixed <<c <<endl;
    return 0;
}